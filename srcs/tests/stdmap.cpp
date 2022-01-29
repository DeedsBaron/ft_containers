#include "../utils/Colors.hpp"
#include "../utils/Print.hpp"
#include <iostream>
#include <map>
#include <iomanip>

int main (void){
	std::cout << GREEN << "-------------=STDMAP=-------------\n" << RES;
	//constructors
	std::cout << YELLOW << "::::::::::::CONSTRUCTORS::::::::::::\n" << RES ;
	{
		std::cout << CYAN << "first \n" << RES;
		std::map<int, char> first;
		std::cout << CYAN << "first.insert(<'a', 0> ... <'a', 4>) \n" << RES;
		for (int i = 0; i < 5; i++)
			first.insert(std::make_pair(i, 'a'));
		print_info(first);
		std::cout << CYAN << "second(first.begin(),first.end())\n" << RES;
		std::map<int, char> second(first.begin(), first.end());
		print_info(second);
		std::cout << CYAN << "third(second)\n" << RES;
		std::map<int, char> third(first);
		print_info(third);
	}

	std::cout << YELLOW << ":::::::::::::OPERATOR=::::::::::::::\n" << RES ;
	{
		std::cout << CYAN << "first \n" << RES;
		std::map<int, char> first;
		std::cout << CYAN << "first.insert(<'a', 0> ... <'a', 4>) \n" << RES;
		for (int i = 0; i < 5; i++)
			first.insert(std::make_pair(i, 'a'));
		print_info(first);
		std::cout << CYAN << "second \n" << RES;
		std::map<int, char> second;
		std::cout << CYAN << "second = first \n" << RES;
		second = first;
		std::cout << CYAN << "second: \n" << RES;
		print_info(second);
	}
	//iterators
	std::cout << YELLOW << ":::::::::::FORWARD_ITERS::::::::::::\n" << RES ;
	{
		std::cout << CYAN << "mymap \n" << RES;
		std::map<char,int> mymap;
		std::cout << CYAN << "mymap['b'] = 100; \n" << RES;
		std::cout << CYAN << "mymap['a'] = 200; \n" << RES;
		std::cout << CYAN << "mymap['c'] = 300; \n" << RES;
		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << CYAN << "ft::map<char, int>::const_iterator c_start(mymap.begin()); \n" << RES;
		std::map<char, int>::const_iterator c_start(mymap.begin());
		std::cout << c_start->first << " => " << c_start->second << '\n';
	}

	std::cout << YELLOW << ":::::::::::REVERSED_ITERS:::::::::::\n" << RES ;
	{
		std::cout << CYAN << "mymap \n" << RES;
		std::map<char,int> mymap;
		std::cout << CYAN << "mymap['x'] = 100; \n" << RES;
		std::cout << CYAN << "mymap['y'] = 200; \n" << RES;
		std::cout << CYAN << "mymap['z'] = 300; \n" << RES;
		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;
		std::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			std::cout << rit->first << " => " << rit->second << '\n';
		std::cout << CYAN << "ft::map<char, int>::const_reverse_iterator cr_rit(mymap.begin()); \n" << RES;
		std::map<char, int>::const_reverse_iterator c_rit(mymap.rbegin());
		std::cout << c_rit->first << " => " << c_rit->second << '\n';
	}
	//capacity
	std::cout << YELLOW << "::::::::::::EMPTY & SIZE::::::::::::\n" << RES ;
	{
		std::cout << CYAN << "mymap \n" << RES;
		std::map<char,int> mymap;
		std::cout << CYAN << "mymap.empty()\n" << RES;
		std::cout << mymap.empty() << std::endl;
		std::cout << CYAN << "mymap.size()\n" << RES;
		std::cout << mymap.size() << std::endl;
		std::cout << CYAN << "mymap['x'] = 100; \n" << RES;
		std::cout << CYAN << "mymap['y'] = 200; \n" << RES;
		std::cout << CYAN << "mymap['z'] = 300; \n" << RES;
		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;
		std::cout << CYAN << "mymap \n" << RES;
		print_info(mymap);
		std::cout << CYAN << "mymap.empty()\n" << RES;
		std::cout << mymap.empty() << std::endl;
		std::cout << CYAN << "mymap.size()\n" << RES;
		std::cout << mymap.size() << std::endl;
	}
	std::cout << YELLOW << ":::::::::::::MAX_SIZE:::::::::::::::\n" << RES ;
	{
		std::cout << CYAN << "mymap \n" << RES;
		std::map<char,int> mymap;
		std::cout << CYAN << "mymap.max_size() \n" << RES;
		std::cout << mymap.max_size() << std::endl;
	}
	//modifiers
	std::cout << YELLOW << "::::::::::::::INSERT::::::::::::::::\n" << RES ;
	{
		std::cout << CYAN << "mymap \n" << RES;
		std::map<char,int> mymap;
		std::cout << CYAN << "mymap.max_size() \n" << RES;
		std::cout << CYAN << "mymap.insert(ft::make_pair('a', 5)) \n" << RES;
		std::pair<std::map<char, int>::iterator, bool> ret = mymap.insert(std::make_pair('a', 5));
		std::cout << "ret first = " << "<" << ret.first->first << ", " << ret.first->second << "> " << "\nret second = " << ret.second << std::endl;
		std::cout << CYAN << "mymap \n" << RES;
		print_info(mymap);
		std::cout << CYAN << "mymap.insert(ft::make_pair('a', 5)) \n" << RES;
		ret = mymap.insert(std::make_pair('a', 5));
		std::cout << "ret first = " << "<" << ret.first->first << ", " << ret.first->second << "> " << "\nret second = " << ret.second << std::endl;
		std::cout << CYAN << "mymap \n" << RES;
		print_info(mymap);
		std::cout << CYAN << "mymap.insert(mymap.begin(), ft::make_pair('z',  6)) \n" << RES;
		std::map<char, int>::iterator ret_it = mymap.insert(mymap.begin(), std::make_pair('z',  6));
		std::cout << "ret first = " << ret_it->first << "\nret second = " << ret_it->second << std::endl;
		std::cout << CYAN << "mymap \n" << RES;
		print_info(mymap);
		std::cout << CYAN << "mymap.insert(mymap.begin(), ft::make_pair('z',  6)) \n" << RES;
		ret_it = mymap.insert(mymap.begin(), std::make_pair('z',  6));
		std::cout << "ret first = " << ret_it->first << "\nret second = " << ret_it->second << std::endl;
		std::cout << CYAN << "mymap \n" << RES;
		print_info(mymap);
		std::cout << CYAN << "secondmap \n" << RES;
		std::map<char,int> secondmap;
		std::cout << CYAN << "secondmap.insert(mymap.begin(), mymap.end()); \n" << RES;
		secondmap.insert(mymap.begin(), mymap.end());
		print_info(secondmap);
	}

	std::cout << YELLOW << "::::::::::::::ERASE:::::::::::::::::\n" << RES ;
	{
		std::cout << CYAN << "first \n" << RES;
		std::map<int, char> first;
		std::cout << CYAN << "first.insert(<'a', 0> ... <'a', 4>) \n" << RES;
		for (int i = 0; i < 5; i++)
			first.insert(std::make_pair(i, 'a'));
		print_info(first);
		std::cout << CYAN << "first.erase(--first.end()) \n" << RES;
		first.erase(--first.end());
		print_info(first);
		std::cout << CYAN << "first.erase(1) \n" << RES;
		first.erase(1);
		print_info(first);
		std::cout << CYAN << "first.erase(first.begin(), first.end()) \n" << RES;
		first.erase(first.begin(), first.end());
		std::cout << CYAN << "first \n" << RES;
		print_info(first);
	}

	std::cout << YELLOW << ":::::::::::::::SWAP:::::::::::::::::\n" << RES ;
	{
		std::map<char,int> foo,bar;
		foo['x']=100;
		foo['y']=200;
		bar['a']=11;
		bar['b']=22;
		bar['c']=33;
		std::cout << CYAN << "foo \n" << RES;
		print_info(foo);
		std::cout << CYAN << "bar \n" << RES;
		print_info(bar);
		foo.swap(bar);
		std::cout << CYAN << "foo \n" << RES;
		print_info(foo);
		std::cout << CYAN << "bar \n" << RES;
		print_info(bar);
	}

	std::cout << YELLOW << "::::::::::::::::FIND::::::::::::::::\n" << RES ;
	{
		std::map<char,int> mymap;
		std::cout << CYAN << "mymap \n" << RES;
		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;
		print_info(mymap);
		std::cout << CYAN << "ft::map<char,int>::iterator it = mymap.find('b') \n" << RES;
		std::map<char,int>::iterator it = mymap.find('b');
		std::cout << CYAN << "mymap.erase (it) \n" << RES;
		if (it != mymap.end())
			mymap.erase (it);
		std::cout << CYAN << "mymap \n" << RES;
		print_info(mymap);
	}

	std::cout << YELLOW << "::::::::::::::::COUNT:::::::::::::::\n" << RES ;
	{
		std::map<char,int> mymap;
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

	std::cout << YELLOW << "::::::::::::::::BOUNDS::::::::::::::\n" << RES ;
	{
		std::map<char,int> mymap;
		std::map<char,int>::iterator itlow,itup;
		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;
		std::cout << CYAN << "mymap \n" << RES;
		print_info(mymap);
		std::cout << CYAN << "ft::map<char,int>::iterator itlow = mymap.lower_bound ('b') \n" << RES;
		itlow=mymap.lower_bound ('b');
		itup=mymap.upper_bound ('d');
		std::cout << "itlow->first = " << itlow->first << std::endl;
		std::cout << CYAN << "ft::map<char,int>::iterator itlow = mymap.upper_bound ('d') \n" << RES;
		std::cout << "itup->first = " << itup->first << std::endl;
		mymap.erase(itlow,itup);
		std::cout << CYAN << "mymap.erase(itlow,itup); \n" << RES;
		std::cout << CYAN << "mymap \n" << RES;
		print_info(mymap);
	}

	std::cout << YELLOW << ":::::::::::::EQUAL_RANGE::::::::::::\n" << RES ;
	{
		std::map<char,int> mymap;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		std::cout << CYAN << "mymap \n" << RES;
		print_info(mymap);
		std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');
		std::cout << CYAN << "ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret = mymap.equal_range('b'); \n" << RES;
		std::cout << "ret.first = ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';
		std::cout << "ret.second = ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}

	std::cout << YELLOW << ":::::::::RELATIONAL_OPERATORS::::::::\n" << RES ;
	{
		std::map<char,int> foo,bar;
		foo['a']=100;
		foo['b']=200;
		bar['a']=10;
		bar['z']=1000;
		std::cout << CYAN << "foo \n" << RES;
		print_info(foo);
		std::cout << CYAN << "bar \n" << RES;
		print_info(bar);
		std::cout<<std::endl;
		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	std::cout << YELLOW << "::::::::::::::TIME_TESTS::::::::::::\n" << RES;
	{
		time_t 	start,end;
		std::map<int, char> mymap;
		time(&start);
		for(int i = 0; i <1000000; i++)
			mymap.insert(std::make_pair(i, 'a'));
		time(&end);
		std::cout << "Time taken by insert is : " << std::fixed << float(end - start) << std::setprecision(5) << " sec \n";
		time(&start);
		std::map<int, char> copy(mymap);
		time(&end);
		std::cout << "Time taken by deep copy is : " << std::fixed << float(end - start) << std::setprecision(5) << " sec \n";
		std::map<int, char> mymap2;
		time(&start);
		mymap2.insert(copy.begin(), copy.end());
		time(&end);
		std::cout << "Time taken by insert : " << std::fixed << float(end - start) << std::setprecision(5) << " sec \n";
		time(&start);
		mymap.erase(mymap.begin(), mymap.end());
		time(&end);
		std::cout << "Time taken by erase : " << std::fixed << float(end - start) << std::setprecision(5) << " sec \n";
	}
	return 0;
}