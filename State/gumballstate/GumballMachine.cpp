#include "GumballMachine.h"
#include "HasQuarterState.h"
#include "NoQuarterState.h"
#include "SoldOutState.h"
#include "we_made_a_sale_state.h"
#include <cassert>
#include <iostream>
#include <memory>
#include <ostream>
class State_base_with_delegated_context_fns;

GumballMachine::GumballMachine (int numberOfBalls)
    : count_ (numberOfBalls),
      sold_out_state_uptr_       (std::make_unique<Sold_out_state>       (this)),          // New up a uptr of a specific derived_state. The "this" ptr is ???? converted to a uptr of a derived/covariant type.
      no_quarter_state_uptr_     (std::make_unique<No_quarter_state>     (this)),
      has_quarter_state_uptr_    (std::make_unique<Has_quarter_state>    (this)),
      we_have_a_sale_state_uptr_ (std::make_unique<We_have_a_sale_state> (this))
{
    current_state_ptr_ = (count_ > 0) ? no_quarter_state_uptr_.get () : sold_out_state_uptr_.get ();
}

void GumballMachine::insert_quarter () {         // Most machine operations are delegated to the state's fns, but not getCount?? TODO?: why?!
    current_state_ptr_->insert_quarter ();
}

void GumballMachine::eject_quarter () {
    current_state_ptr_->eject_quarter ();
}

void GumballMachine::turn_crank () {
    current_state_ptr_->turn_crank ();
    current_state_ptr_->dispense ();
}

void GumballMachine::release_ball () {
    assert (count_ > 0);                                     // if (count > 0) --count;  // TODO?: ERROR why check before decrement? This should have been checked already.
    --count_;
    std::cout << "A gumball comes rolling out the slot.\n";
}

void GumballMachine::refill (int c) {
    count_ += c;
    current_state_ptr_->refill ();
    std::cout << "The gumball machine was just refilled; its new count is: " << count_ << '\n';
}

void
GumballMachine::set_state(State_base_with_delegated_context_fns *s) {
    current_state_ptr_ = s;
}

int
GumballMachine::get_count() const {
    return count_;
}

State_base_with_delegated_context_fns *
GumballMachine::get_current_state_ptr() const {
    return current_state_ptr_;
}

State_base_with_delegated_context_fns *
GumballMachine::get_no_quarter_state_uptr() const {
    return no_quarter_state_uptr_.get();
}

State_base_with_delegated_context_fns *
GumballMachine::get_has_quarter_state_uptr() const {
    return has_quarter_state_uptr_.get();
}

State_base_with_delegated_context_fns *
GumballMachine::get_sold_out_state_uptr() const {
    return sold_out_state_uptr_.get();
}

State_base_with_delegated_context_fns *
GumballMachine::get_we_have_sale_state_uptr() const {
    return we_have_a_sale_state_uptr_.get();
}

std::ostream & operator<< (std::ostream &os, GumballMachine const & gbm) {
    os << "\nInventory: " << gbm.get_count () << " gumball";
    if (gbm.get_count () != 1) os << "s";
    os << "\n";
    os << "Machine is in state: " << *gbm.get_current_state_ptr () << "\n";
    return os;
}
