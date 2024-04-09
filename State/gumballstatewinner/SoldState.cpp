#include "GumballMachine.h"
#include "SoldState.h"
#include <iostream>

We_have_a_sale_state::We_have_a_sale_state(GumballMachine *gbm) : gumballMachine(gbm) { }

void
We_have_a_sale_state::insertQuarter()
{
	std::cout << "Please wait, we're already giving you a gumball\n";
}

void
We_have_a_sale_state::ejectQuarter()
{
    std::cout << "Your error, you already turned the crank\n";
}

void
We_have_a_sale_state::turnCrank()
{
    std::cout << "Your error, you may not turn twice.\n";
}

void
We_have_a_sale_state::dispense()
{
	gumballMachine->releaseBall();
	if (gumballMachine->getCount() > 0)
		gumballMachine->setState(gumballMachine->getNoQuarterState());
	else {
		std::cout << "Oops, out of gumballs\n";
		gumballMachine->setState(gumballMachine->getSoldOutState());
	}
}

void
We_have_a_sale_state::refill() { }

void
We_have_a_sale_state::toString(std::ostream &os) const
{
	os << "waiting for quarter";
}
