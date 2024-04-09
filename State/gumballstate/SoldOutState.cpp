#include "SoldOutState.h"
#include "GumballMachine.h"
#include <iostream>

Sold_out_state::Sold_out_state(GumballMachine *gbm) : gumball_machine_ptr_(gbm) {}

void Sold_out_state::refill() { gumball_machine_ptr_->set_state(gumball_machine_ptr_->get_no_quarter_state_uptr()); }

void Sold_out_state::insert_quarter() { std::cout << "You can't insert a quarter, the machine is sold out.\n"; }

void Sold_out_state::eject_quarter() { std::cout << "You can't eject, you haven't inserted a quarter yet.\n"; }

void Sold_out_state::turn_crank() { std::cout << "You turned, but there are no gumballs.\n"; }

void Sold_out_state::dispense() { std::cout << "No gumball dispensed.\n"; }

void Sold_out_state::to_string(std::ostream &os) const { os << "Dispensing a gumball."; }
