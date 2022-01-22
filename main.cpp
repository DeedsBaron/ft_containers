#include "srcs/containers/Vector.hpp"
#include "srcs/utils/Colors.hpp"
#include "srcs/utils/RBTree.hpp"
#include "srcs/utils/Utils.hpp"
#include "srcs/utils/Print.hpp"
#include "srcs/containers/Stack.hpp"
#include "srcs/utils/RandIterator.hpp"
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
		ft::map<int, char> first;
		std::cout << CYAN << "first.insert(<'a', 0> ... <'a', 4>) \n" << RES;
		for (int i = 0; i < 5; i++)
			first.insert(ft::make_pair(i, 'a'));
		print_info(first);
		std::cout << "JOPA\n";
		first.erase(first.find(4));
		print_info(first);
	}
//
	std::cout << YELLOW << "::::::::::::::::COUNT:::::::::::::::\n" << RES ;
	{
		ft::map<char,int> mymap;
		std::cout << CYAN << "mymap \n" << RES;
		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;
		print_info(mymap);
		std::cout << CYAN << "mymap.count('1') \n" << RES;
		std::cout << mymap.count('1') << std::endl;
		std::cout << CYAN << "mymap.count('5') \n" << RES;
		std::cout << mymap.count('5') << std::endl;
	}
	return 0;
}