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
//		std::map<char,int> foo,bar;
//		foo['a']=100;
//		bar['a']=100;
//		std::cout << CYAN << "foo \n" << RES;
//		print_info(foo);
//		std::cout << CYAN << "bar \n" << RES;
//		print_info(bar);
//		if (foo==bar) std::cout << "foo and bar are equal\n";
//		if (foo!=bar) std::cout << "foo and bar are not equal\n";
//		if (foo< bar) std::cout << "foo is less than bar\n";
//		if (foo> bar) std::cout << "foo is greater than bar\n";
//		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	}
//
	std::cout << YELLOW << ":::::::::::::EQUAL_RANGE::::::::::::\n" << RES ;
	{
		ft::map<int, char> mymap;
		for (int i = 0; i < 10; i++)
			mymap.insert(ft::make_pair(i, 'a'));
		print_info(mymap);
		mymap.erase(mymap.begin(), mymap.end());
		print_info(mymap);
	}
	return 0;
}