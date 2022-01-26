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
		Node<int>* p1 = new Node<int>(1);
		Node<ft::pair<int, char> >* p2 =  new Node<ft::pair<int, char> >(ft::make_pair(1, 'a'));
		ft::pair<int, char>* p3 = new ft::pair<int, char> (1, 'a');
		std::cout << *p1->_value << std::endl;
		std::cout << **p3 << std::endl;
		std::cout << **(p2->_value) << std::endl;
	}
	return 0;
}