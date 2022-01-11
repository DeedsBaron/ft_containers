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




int main() {
	ft::map<int , char> mymap;
	for (int i = 0; i < 10; i++)
		mymap.insert(ft::make_pair(i, 'a'));
	mymap.print();
	std::cout << "size = " << mymap.size() << std::endl;
	mymap.erase(++mymap.begin());
	mymap.print();
	std::cout << "size = " << mymap.size() << std::endl;
	std::cout << "erase ret = " << mymap.erase(19) << std::endl;
	mymap.print();
	std::cout << "erase ret = " << mymap.erase(5) << std::endl;
	mymap.print();
	mymap.erase(mymap.begin(), mymap.end());
	mymap.print();
	return 0;
}