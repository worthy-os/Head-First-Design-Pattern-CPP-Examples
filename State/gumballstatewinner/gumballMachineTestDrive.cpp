#include "GumballMachine.h"
#include <iostream>

int main() {
    auto gumballMachine{ GumballMachine {10} };

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
	std::cout << gumballMachine << '\n';
    std::cout << "###" << std::endl;
    return EXIT_SUCCESS;
}
