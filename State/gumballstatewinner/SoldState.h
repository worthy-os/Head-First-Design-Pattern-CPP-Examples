#ifndef SOLD_STATE_H
#define SOLD_STATE_H

#include "State.h"
#include <ostream>

class GumballMachine;

class We_have_a_sale_state : public State {
	public:
		We_have_a_sale_state() = default;
		We_have_a_sale_state(GumballMachine *gbm);
		void insertQuarter() override;
		void ejectQuarter() override;
		void turnCrank() override;
		void dispense() override;
		void refill() override;
	protected:
		void toString(std::ostream &) const override;
	private:
		GumballMachine *gumballMachine;
};

#endif /* SOLD_STATE_H */
