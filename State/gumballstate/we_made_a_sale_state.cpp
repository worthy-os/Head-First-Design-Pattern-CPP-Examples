#include "we_made_a_sale_state.h"
#include "GumballMachine.h"
#include <iostream>

We_have_a_sale_state::We_have_a_sale_state(GumballMachine *gbm)
    : gumball_machine_ptr_(gbm) {
}

void We_have_a_sale_state::insert_quarter() {
    std::cout << "Please wait, we're already giving you a gumball\n";
}

void We_have_a_sale_state::eject_quarter() {
    std::cout << "Sorry, you already turned the crank\n";
}

void We_have_a_sale_state::turn_crank() {
    std::cout << "Your error, you may not turn twice.\n";
}

void We_have_a_sale_state::dispense() {
    gumball_machine_ptr_->release_ball();
    if (gumball_machine_ptr_->get_count() > 0)
        gumball_machine_ptr_->set_state(gumball_machine_ptr_->get_no_quarter_state_uptr());
    else {
        std::cout << "Our error, we are out of gumballs.\n";
        gumball_machine_ptr_->set_state(gumball_machine_ptr_->get_sold_out_state_uptr());
    }
}

void We_have_a_sale_state::refill () {
}

void We_have_a_sale_state::to_string(std::ostream &os) const {
    os << "waiting for quarter";
}
