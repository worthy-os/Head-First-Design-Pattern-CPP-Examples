#pragma once
#include "State.h"
#include <ostream>
class GumballMachine;

class Has_quarter_state : public State_base_with_delegated_context_fns {
    GumballMachine *gumball_machine_ptr_;
public:
    explicit Has_quarter_state(GumballMachine *);
    void insert_quarter() override;
    void eject_quarter() override;
    void turn_crank() override;
    void dispense() override;
    void refill() override;
protected:
    void to_string(std::ostream &) const override;
};
