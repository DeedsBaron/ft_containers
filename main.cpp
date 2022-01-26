#include "srcs/containers/Vector.hpp"
#include "srcs/utils/Colors.hpp"
#include "srcs/utils/RBTree.hpp"
#include "srcs/utils/Utils.hpp"
#include "srcs/utils/Print.hpp"
#include "srcs/containers/Stack.hpp"
#include "srcs/utils/RandIterator.hpp"
#include "srcs/containers/Map.hpp"
#include <map>


const ft::map<char, int>& 	func(const ft::map<char, int>& ins) { return ins;}

int main()
{
	{
		std::map<int, char> map;
		map.insert(std::make_pair(1, 'a'));
		std::map<int, char> map2;
		map2.insert(std::make_pair(1, 'a'));
		if (map < map2) std::cout << "less\n";

	}
//
	std::cout << YELLOW << ":::::::::RELATIONAL_OPERATORS::::::::\n" << RES ;
	{
		ft::map<int, char> foo,bar;
		for (int i = 0; i < 10; i++)
			foo.insert(ft::make_pair(i, 'a'));
		print_info(foo);
	}
	return 0;
}