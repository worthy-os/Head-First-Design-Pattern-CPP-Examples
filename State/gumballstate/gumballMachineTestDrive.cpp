#include "GumballMachine.h"
#include <iostream>

int main() {
    auto gumballMachine{ GumballMachine {5} };

    std::cout << gumballMachine << '\n';
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    std::cout << gumballMachine << '\n';

    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    std::cout << gumballMachine << '\n';

    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    std::cout << gumballMachine << '\n';

    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    std::cout << gumballMachine << '\n';

    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
	std::cout << gumballMachine;
    std::cout << "###" << std::endl;
    return EXIT_SUCCESS;
}
