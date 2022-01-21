#include "srcs/containers/Vector.hpp"
#include "srcs/utils/Colors.hpp"
#include "srcs/utils/RBTree.hpp"
#include "srcs/utils/Utils.hpp"
#include "srcs/utils/Print.hpp"
#include "srcs/containers/Stack.hpp"
#include "srcs/utils/RandIterator.hpp"
#include "srcs/utils/BidirectionalIter.hpp"
#include "srcs/containers/Map.hpp"
#include <map>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

int main()
{
	{
		std::cout << CYAN << "first \n" << RES;
		std::map<int, char> first;
		std::cout << CYAN << "first.insert(<'a', 0> ... <'a', 4>) \n" << RES;
		for (int i = 0; i < 5; i++)
			first.insert(std::make_pair(i, 'a'));
		print_info(first);
		std::cout << CYAN << "second(first.begin(),first.end())\n" << RES;
		std::map<int, char > second (first.begin(),first.end());
		print_info(second);
		std::cout << CYAN << "third(first.begin(),first.end())\n" << RES;
		std::map<int, char> third(second);
		print_info(third);
	}

	std::cout << YELLOW << "::::::::::::CONSTRUCTORS::::::::::::\n" << RES ;
	{
		std::cout << CYAN << "first \n" << RES;
		ft::map<int, char> first;
		std::cout << CYAN << "first.insert(<'a', 0> ... <'a', 4>) \n" << RES;
		for (int i = 0; i < 3; i++)
			first.insert(ft::make_pair(i, 'a'));
		print_info(first);
		std::cout << CYAN << "second(first.begin(),first.end())\n" << RES;
		ft::map<int, char> second(first.begin(), first.end());
		print_info(second);
		std::cout << CYAN << "third(second)\n" << RES;
		ft::map<int, char> third(first);
		third.print();
		print_info(third);
	}
	return 0;
}