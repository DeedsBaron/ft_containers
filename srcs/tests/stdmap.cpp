#include "../utils/Colors.hpp"
#include "../utils/Print.hpp"
#include <iostream>
#include <map>

int main (void){
	std::cout << GREEN << "-------------=STDMAP=-------------\n" << RES;
	//constructors
	std::cout << YELLOW << "::::::::::::CONSTRUCTORS::::::::::::\n" << RES ;
	{
		std::cout << CYAN << "first \n" << RES;
		std::map<int, char> first;
		std::cout << CYAN << "first.insert(<'a', 0> ... <'a', 4>) \n" << RES;
		for (int i = 0; i < 5; i++)
			first.insert(std::make_pair(i, 'a'));
		print_info(first);
		std::cout << CYAN << "second(first.begin(),first.end())\n" << RES;
		std::map<int, char> second(first.begin(), first.end());
		print_info(second);
		std::cout << CYAN << "third(second)\n" << RES;
		std::map<int, char> third(first);
		print_info(third);
	}
	return 0;
}