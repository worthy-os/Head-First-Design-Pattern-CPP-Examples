#ifndef GUMBALL_MACHINE_H
#define GUMBALL_MACHINE_H

#include <iostream>

class GumballMachine {
public:
    GumballMachine (int c) : count (c) {
        if (count > 0) state = NO_QUARTER;  // Moving from initial SOLD_OUT state.
    }
    void insertQuarter ();
    void ejectQuarter ();
    void turnCrank ();
    void dispense ();
    void refill (int numberOfGumballs);
private:
    static constexpr int SOLD_OUT       = 0;
    static constexpr int NO_QUARTER     = 1;
    static constexpr int HAS_QUARTER    = 2;
    static constexpr int WE_HAVE_A_SALE = 3;
    int                  state          = SOLD_OUT;
    int                  count          = 0;
    friend std::ostream &operator<< (std::ostream &, GumballMachine &);
};

inline void GumballMachine::insertQuarter () {
    if (state == NO_QUARTER) {
        state = HAS_QUARTER;
        std::cout << "you inserted a quarter\n";
    } // We stay in present state, but warn.
    else if (state == HAS_QUARTER)      std::cout << "You can't insert another quarter\n";
    else if (state == SOLD_OUT)         std::cout << "You can't insert a quarter, the machine is sold out\n";
    else if (state == WE_HAVE_A_SALE)   std::cout << "Please wait, we're already giving you a gumball\n";
}

inline void GumballMachine::ejectQuarter () {
    if (state == HAS_QUARTER) {
        state = NO_QUARTER;
        std::cout << "Quarter returned\n";
    } // We stay in present state, but warn.
    else if (state == NO_QUARTER)       std::cout << "You haven't inserted a quarter\n";
    else if (state == WE_HAVE_A_SALE)   std::cout << "Sorry, you already turned the crank\n";
    else if (state == SOLD_OUT)         std::cout << "You can't eject, you haven't inserted a quarter yet\n";
}

inline void GumballMachine::turnCrank () {
    if (state == HAS_QUARTER) {
        state = WE_HAVE_A_SALE;
        std::cout << "You turned the crank sucessfully.n";
        dispense ();
    } // We stay in present state, but warn.
    else if (state == WE_HAVE_A_SALE)   std::cout << "Turning twice doesn't get you another gumball!\n";
    else if (state == NO_QUARTER)       std::cout << "You turned, but there are no quarter\n";
    else if (state == SOLD_OUT)         std::cout << "You turned, but there are no gumballs\n";
}

inline void GumballMachine::dispense () {
    if (state == WE_HAVE_A_SALE) {
        std::cout << "A gumball comes rolling out the slot\n";
        count = count - 1;
        if (count == 0) {
            std::cout << "Our error, out of gumballs.\n";
            state = SOLD_OUT;
        } else {
            state = NO_QUARTER;
        }
    } // We stay in present state, but warn.
    else if (state == NO_QUARTER)  std::cout << "You need to pay first\n";
    else if (state == SOLD_OUT)    std::cout << "No gumball dispensed\n";
    else if (state == HAS_QUARTER) std::cout << "No gumball dispensed\n";
}

inline std::ostream & operator<< (std::ostream &os, GumballMachine &gumballMachine) {
    os << "Inventory: " << gumballMachine.count << " gumball"; if (gumballMachine.count != 1) { os << "s"; }
    os << "\nMachine is in state: ";
    if (gumballMachine.state == GumballMachine::SOLD_OUT)         os << "sold out";
    else if (gumballMachine.state == GumballMachine::NO_QUARTER)  os << "waiting for quarter";
    else if (gumballMachine.state == GumballMachine::HAS_QUARTER) os << "waiting for turn of crank";
    else if (gumballMachine.state == GumballMachine::WE_HAVE_A_SALE) os << "delivering a gumball";
    os << "\n";
    return os;
}

#endif /* GUMBALL_MACHINE_H */
