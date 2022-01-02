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
	RBTree<int, char> my_tree;
	for (int i = 0; i < 20; i++)
		my_tree.insert(ft::make_pair(i, 'a'));
	my_tree.print();
	ft::map<int, int> my_map;
	my_map.print();
	return 0;
}