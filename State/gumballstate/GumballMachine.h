#pragma once
#include "State.h"
#include <ostream>
#include <memory>
class NoQuarterState; class HasQuarterState; class SoldOutState; class We_have_a_sale_state;

class GumballMachine {                              // We have a total of 4 states the context can be in.
    int                                                    count_{};
    std::unique_ptr<State_base_with_delegated_context_fns> sold_out_state_uptr_;        // Constructor loads with it covariant.
    std::unique_ptr<State_base_with_delegated_context_fns> no_quarter_state_uptr_;
    std::unique_ptr<State_base_with_delegated_context_fns> has_quarter_state_uptr_;
    std::unique_ptr<State_base_with_delegated_context_fns> we_have_a_sale_state_uptr_;

    State_base_with_delegated_context_fns                  *current_state_ptr_{};
public:
    explicit GumballMachine(int);
    void refill(int);
    void insert_quarter();
    void eject_quarter();
    void turn_crank();
    void release_ball();
    void set_state(State_base_with_delegated_context_fns *);
    int  get_count() const;

    State_base_with_delegated_context_fns *get_current_state_ptr() const;

    State_base_with_delegated_context_fns *get_no_quarter_state_uptr() const;
    State_base_with_delegated_context_fns *get_has_quarter_state_uptr() const;
    State_base_with_delegated_context_fns *get_sold_out_state_uptr() const;
    State_base_with_delegated_context_fns *get_we_have_sale_state_uptr() const;
    friend std::ostream& operator<<(std::ostream &, const GumballMachine &);
};
