#include "srcs/containers/Vector.hpp"
#include "srcs/utils/Colors.hpp"
#include "srcs/utils/RBTree.hpp"
#include "srcs/utils/Utils.hpp"
#include "srcs/utils/Print.hpp"
#include "srcs/containers/Stack.hpp"
#include "srcs/utils/RandIterator.hpp"
#include "srcs/containers/Map.hpp"
#include "srcs/containers/Set.hpp"
#include <map>


const ft::map<char, int>& 	func(const ft::map<char, int>& ins) { return ins;}

int main() {
	{
		std::cout << CYAN << "first \n" << RES;
		std::map<int, char> first;
		std::cout << CYAN << "first.insert(<'a', 0> ... <'a', 4>) \n" << RES;
		for (int i = 0; i < 5; i++)
			first.insert(std::make_pair(i, 'a'));
		print_info(first);
		std::cout << CYAN << "second \n" << RES;
		std::map<int, char> second;
		std::cout << CYAN << "second = first \n" << RES;
		second = first;
		std::cout << CYAN << "second: \n" << RES;
		print_info(second);

	}
//
	std::cout << YELLOW << ":::::::::RELATIONAL_OPERATORS::::::::\n" << RES;
	{
		std::cout << CYAN << "first \n" << RES;
		ft::set<int> first;
		std::cout << CYAN << "first.insert(0 ... 4) \n" << RES;
		for (int i = 0; i < 5; i++)
			first.insert(i);
		print_info(first);
		std::cout << CYAN << "second(first.begin(),first.end())\n" << RES;
		ft::set<int> second(first.begin(), first.end());
		print_info(second);
		std::cout << CYAN << "third(second)\n" << RES;
		ft::set<int> third(first);
		print_info(third);
	}
	return 0;
}