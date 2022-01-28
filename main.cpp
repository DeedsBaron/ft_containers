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

		std::vector<int> myvec;
		for (int i = 0; i < 10; i++)
			myvec.push_back(i);
		print_info(myvec);
		std::vector<int>::iterator it = myvec.begin();
		std::vector<int>::const_iterator c_it = myvec.end();
		while (it < c_it){
			std::cout << *it << " " << std::endl;
			it++;
		}


	}
//
	std::cout << YELLOW << ":::::::::RELATIONAL_OPERATORS::::::::\n" << RES;
	{
		ft::vector<int> myvec;
		for (int i = 0; i < 10; i++)
			myvec.push_back(i);
		print_info(myvec);
		ft::vector<int>::const_iterator c_it = myvec.begin();
		ft::vector<int>::iterator it = myvec.end();
		ft::vector<int> myvec1(myvec);
		print_info(myvec1);
		*it = 123;
		while (c_it < it){
			std::cout << *c_it << " " << std::endl;
			c_it++;
		}
//		ft::map<int, char> mymap;
//		for (int i =0; i < 10; i++){
//			mymap.insert(ft::make_pair(i, 'a'));
//		}
//		print_info(mymap);
//		ft::map<int, char>::iterator it = mymap.begin();
//		ft::map<int, char>::const_iterator end = mymap.end();
//		while (it != end) {
//			std::cout << it->first << " ";
//			it++;
//		}
	}
	return 0;
}