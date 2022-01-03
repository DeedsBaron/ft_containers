#include "srcs/containers/Vector.hpp"
#include "srcs/utils/Colors.hpp"
#include "srcs/utils/Utils.hpp"
#include "srcs/utils/Print.hpp"
#include <vector>
#include <iostream>
#include "srcs/containers/Stack.hpp"
#include "srcs/utils/RandIterator.hpp"
#include "srcs/utils/BidirectionalIter.hpp"
#include "srcs/utils/RBTree.hpp"
#include "srcs/containers/Map.hpp"

int main() {

//	RBTree<int, char> my_tree;
//	for (int i = 0; i < 20; i++)
//		my_tree.insert(ft::make_pair(i, 'a'));
//	my_tree.print();
//	std::cout << "inorder suc = " << my_tree.findMinimum(my_tree.search(11))->_value->first << std::endl;
//	std::cout << "min node = " << my_tree.find_min()->_value->first << std::endl;
//	std::cout << "max node = " << my_tree.find_max()->_value->first << std::endl;
//	RBTree<int, char>::iterator start = my_tree.begin();
//	std::cout << "begin: key = " << start->first << " value = " << start->second << std::endl;

	ft::map<int, char> my_map;
	for (int i = 0; i < 20; i++)
		my_map.insert(ft::make_pair(i, 'a'));
	my_map.print();
	ft::map<int, char>::iterator start = my_map.begin();
	std::cout << "begin: key = " << start->first << " value = " << start->second << std::endl;
	++start;
	std::cout << "begin: key = " << start->first << " value = " << start->second << std::endl;

	return 0;
}