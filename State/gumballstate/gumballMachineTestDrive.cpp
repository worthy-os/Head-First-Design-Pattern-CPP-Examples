#include "GumballMachine.h"
#include <iostream>

int main() {
    auto gumballMachine{ GumballMachine {5} };
    std::cout << gumballMachine << '\n';
    gumballMachine.insert_quarter();
    gumballMachine.turn_crank();
    gumballMachine.insert_quarter();
    gumballMachine.turn_crank();
    std::cout << gumballMachine << '\n';
    gumballMachine.insert_quarter();
    gumballMachine.turn_crank();
    gumballMachine.insert_quarter();
    gumballMachine.turn_crank();
    std::cout << gumballMachine << '\n';
    gumballMachine.insert_quarter();
    gumballMachine.turn_crank();
    gumballMachine.insert_quarter();
    gumballMachine.turn_crank();
    std::cout << gumballMachine << '\n';
    gumballMachine.insert_quarter();
    gumballMachine.turn_crank();
    gumballMachine.insert_quarter();
    gumballMachine.turn_crank();
    std::cout << gumballMachine << '\n';
    gumballMachine.insert_quarter();
    gumballMachine.turn_crank();
    gumballMachine.insert_quarter();
    gumballMachine.turn_crank();
	std::cout << gumballMachine;
    std::cout << "###" << std::endl;
    return EXIT_SUCCESS;
}
