#ifndef SOLD_OUT_STATE_H
#define SOLD_OUT_STATE_H
#include "State.h"
#include <ostream>
class GumballMachine;

class Sold_out_state : public State_base_with_delegated_context_fns {
        GumballMachine *gumball_machine_ptr_;
    public:
        explicit Sold_out_state(GumballMachine *);
        void insert_quarter() override;
        void eject_quarter() override;
        void turn_crank() override;
		void dispense() override;
		void refill() override;
	protected:
        void to_string(std::ostream &) const override;
};

#endif /* SOLD_OUT_STATE_H */
