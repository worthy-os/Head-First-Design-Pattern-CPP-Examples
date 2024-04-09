#ifndef STATE_H
#define STATE_H
#include <ostream>
class State_base_with_delegated_context_fns {
public:
    virtual      ~State_base_with_delegated_context_fns () = default;
    virtual void insert_quarter() = 0;
    virtual void eject_quarter() = 0;
    virtual void turn_crank() = 0;
    virtual void dispense() = 0;
    virtual void refill() = 0;
protected:
    virtual void to_string(std::ostream &) const = 0;
friend std::ostream& operator<<(std::ostream&, const State_base_with_delegated_context_fns &);
};

inline std::ostream& operator<<(std::ostream& os, const State_base_with_delegated_context_fns &state) {
    state.to_string(os);
	return os;
}

#endif /* STATE_H */
