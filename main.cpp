#include "SimpleNavigator.h"

//c++ SimpleNavigator.h BreadthFirstSearch.h Graph.h main.cpp -o test

int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << "Error: Used => ./nameprog filename\n";
		return 0;
	}
	SimpleNavigator sn(av[1]);
	sn.StartMenu();
}