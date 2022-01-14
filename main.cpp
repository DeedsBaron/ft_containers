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

ft::map<int, char>::const_iterator		func(const ft::map<int, char>& map){
	return map.begin();
}


int main() {
	ft::map<int , char> mymap;
	for (int i = 0; i < 10; i++)
		mymap.insert(ft::make_pair(i, 'a'));
	mymap.print();
	for (ft::map<int, char>::iterator start = mymap.begin(); start != mymap.end(); start++){
		std::cout << "first = " << start->first << "\nsecond = " << start->second << std::endl;
	}
	ft::map<int, char>::iterator start = mymap.begin();
	start->second = 'H';
	mymap.print();
	ft::map<int, char>::const_iterator start1 = func(mymap);
	std::cout << "const first = " << start1->first << "\nsecond = " << start1->second << std::endl;
	return 0;
}