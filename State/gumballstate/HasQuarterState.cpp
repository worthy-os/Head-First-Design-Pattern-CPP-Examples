#include "GumballMachine.h"
#include "HasQuarterState.h"
#include <iostream>

Has_quarter_state::Has_quarter_state(GumballMachine *gbm)
	: gumball_machine_ptr_(gbm) { }

void Has_quarter_state::insert_quarter() {
	std::cout << "You can't insert another quarter\n";
}

void Has_quarter_state::eject_quarter() {
	std::cout << "Quarter return\n";
    gumball_machine_ptr_->set_state(gumball_machine_ptr_->get_no_quarter_state_uptr());
}

void Has_quarter_state::turn_crank() {
    gumball_machine_ptr_->set_state(gumball_machine_ptr_->get_we_have_sale_state_uptr());
    std::cout << "You turned...\n";
}

void Has_quarter_state::dispense() {
	std::cout << "No gumball dispensed\n";
}

void Has_quarter_state::refill() { }

void Has_quarter_state::to_string(std::ostream &os) const {
	os << "waiting for turn of crank";
}
