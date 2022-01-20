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

//ft::map<int, char>::const_iterator		func(const ft::map<int, char>& map){
//	return map.begin();
//}


int main()
{
	{
//		std::map<int, char> mymap;
//		for (int i = 0; i < 10; i++)
//			mymap.insert(std::make_pair(i, 'a'));
////		for (std::map<int, char>::iterator start = mymap.begin(); start != mymap.end(); start++)
////			std::cout << "first = " << start->first << "\nsecond = " << start->second << std::endl;
//		std::map<int, char>::iterator end = mymap.end();
//		--end;
//		std::cout << "first = " << end->first << "\nsecond = " << end->second << std::endl;
//		//	for (int i = 0; i < 10; i++)
////		mymap.erase(i);
	}
	std::cout << GREEN << "::::::::::::::::::::::::::::::\n" << RES;
	{
		ft::map<int, char> mymap;
		for (int i = 0; i < 10; i++)
			mymap.insert(ft::make_pair(i, 'a'));
//		for (ft::map<int, char>::iterator start = mymap.begin(); start != mymap.end(); start++)
//			std::cout << "first = " << start->first << "\nsecond = " << start->second << std::endl;
		ft::map<int, char>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			std::cout << rit->first << " => " << rit->second << '\n';

//		std::cout << "first = " << end->first << "\nsecond = " << start->second << std::endl;
		//	for (int i = 0; i < 10; i++)
//		mymap.erase(i);
		mymap.print();
	}

//	for (ft::map<int, char>::iterator start = mymap.begin(); start != mymap.end(); start++){
//		std::cout << "first = " << start->first << "\nsecond = " << start->second << std::endl;
//	}
//	ft::map<int, char>::iterator start = mymap.begin();
//	start->second = 'H';
//	mymap.print();
//	ft::map<int, char>::const_iterator start1 = start;
//	std::cout << "first = " << start1->first << "\nsecond = " << start1->second << std::endl;
//	std::cout << (*start).second;
	//	std::cout << "const first = " << start1->first << "\nsecond = " << start1->second << std::endl;
//	std::vector<int> myvec;
//	for (int i = 0; i < 10; i++)
//		myvec.push_back(i);
//	print_info(myvec);
//	std::vector<int>::iterator non_const_start = myvec.begin();
//	std::vector<int>::const_iterator const_start = myvec.begin();
//	non_const_start++;
//	std::cout << "non_const iter = " << *non_const_start << std::endl;
//	std::cout << "const iter = " << *const_start << std::endl;
//	*non_const_start = 55;
//	*const_start = 1335;
	return 0;
}