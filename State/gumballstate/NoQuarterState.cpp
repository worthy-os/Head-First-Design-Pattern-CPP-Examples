#include "NoQuarterState.h"
#include "GumballMachine.h"
#include <iostream>
#include <ostream>

No_quarter_state::No_quarter_state(GumballMachine *gbm) : gumball_machine_ptr_(gbm) { }

void No_quarter_state::insert_quarter() {
    State_base_with_delegated_context_fns * new_state_ptr = gumball_machine_ptr_->get_has_quarter_state_uptr();
    gumball_machine_ptr_->set_state(new_state_ptr);      // gumball_machine_ptr_->setState(gumball_machine_ptr_->getHasQuarterState());
    std::cout << "You inserted a quarter.\n";
}

void No_quarter_state::eject_quarter() { std::cout << "You haven't inseted a quarter\n"; }

void No_quarter_state::turn_crank() { std::cout << "You turned, but there's no quarter\n"; }

void No_quarter_state::dispense() { std::cout << "You need to pay first\n"; }

void No_quarter_state::refill() {}

void No_quarter_state::to_string(std::ostream &os) const { os << "waiting for turn of crank"; }
