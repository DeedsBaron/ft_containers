#include "../containers/Set.hpp"
#include "../utils/Print.hpp"
#include <iostream>

int main (void) {
	std::cout << GREEN << "-------------=MYSET=-------------\n" << RES;
	//constructors
	std::cout << YELLOW << "::::::::::::CONSTRUCTORS::::::::::::\n" << RES ;
	{
		std::cout << CYAN << "first \n" << RES;
		ft::set<int> first;
		std::cout << CYAN << "first.insert(0 ... 4) \n" << RES;
		for (int i = 0; i < 5; i++)
			first.insert(i);
		print_info(first);
		std::cout << CYAN << "second(first.begin(),first.end())\n" << RES;
		ft::set<int> second(first.begin(), first.end());
		print_info(second);
		std::cout << CYAN << "third(second)\n" << RES;
		ft::set<int> third(first);
		print_info(third);
	}

	std::cout << YELLOW << ":::::::::::::OPERATOR=::::::::::::::\n" << RES ;
	{
		std::cout << CYAN << "first \n" << RES;
		ft::set<int> first;
		std::cout << CYAN << "first.insert(0 ... 4) \n" << RES;
		for (int i = 0; i < 5; i++)
			first.insert(i);
		print_info(first);
		std::cout << CYAN << "second \n" << RES;
		ft::set<int> second;
		std::cout << CYAN << "second = first \n" << RES;
		second = first;
		std::cout << CYAN << "second: \n" << RES;
		print_info(second);
	}
	//iterators
	std::cout << YELLOW << ":::::::::::FORWARD_ITERS::::::::::::\n" << RES ;
	{
		std::cout << CYAN << "myset \n" << RES;
		ft::set<int> myset;
		std::cout << CYAN << "first.insert(0 ... 4) \n" << RES;
		for (int i = 0; i < 5; i++)
			myset.insert(i);
		for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << "Val = " << *it << std::endl;
		std::cout << CYAN << "ft::set<int>::const_iterator c_start(myset.begin()); \n" << RES;
		ft::set<int>::const_iterator c_start(myset.begin());
		std::cout << "Val = " << *c_start << std::endl;
	}

	std::cout << YELLOW << ":::::::::::REVERSED_ITERS:::::::::::\n" << RES ;
	{
		std::cout << CYAN << "myset \n" << RES;
		ft::set<int> myset;
		std::cout << CYAN << "first.insert(0 ... 4) \n" << RES;
		for (int i = 0; i < 5; i++)
			myset.insert(i);
		ft::set<int>::reverse_iterator rit;
		for (rit=myset.rbegin(); rit!=myset.rend(); ++rit)
			std::cout << "Val = " << *rit << std::endl;;
		std::cout << CYAN << "ft::set<int>::const_reverse_iterator cr_rit(myset.begin()); \n" << RES;
		ft::set<int>::const_reverse_iterator c_rit(myset.rbegin());
		std::cout << "Val = " << *c_rit << std::endl;;
	}
	//capacity
	std::cout << YELLOW << "::::::::::::EMPTY & SIZE::::::::::::\n" << RES ;
	{
		std::cout << CYAN << "myset \n" << RES;
		ft::set<int> myset;
		std::cout << CYAN << "myset.empty()\n" << RES;
		std::cout << myset.empty() << std::endl;
		std::cout << CYAN << "myset.size()\n" << RES;
		std::cout << myset.size() << std::endl;
		std::cout << CYAN << "first.insert(0 ... 4) \n" << RES;
		for (int i = 0; i < 5; i++)
			myset.insert(i);
		std::cout << CYAN << "myset \n" << RES;
		print_info(myset);
		std::cout << CYAN << "myset.empty()\n" << RES;
		std::cout << myset.empty() << std::endl;
		std::cout << CYAN << "myset.size()\n" << RES;
		std::cout << myset.size() << std::endl;
	}
	std::cout << YELLOW << ":::::::::::::MAX_SIZE:::::::::::::::\n" << RES ;
	{
		std::cout << CYAN << "myset \n" << RES;
		ft::set<int> myset;
		std::cout << CYAN << "myset.max_size() \n" << RES;
		std::cout << myset.max_size() << std::endl;
	}
	//modifiers
	std::cout << YELLOW << "::::::::::::::INSERT::::::::::::::::\n" << RES ;
	{
		std::cout << CYAN << "myset \n" << RES;
		ft::set<int> myset;
		std::cout << CYAN << "myset.max_size() \n" << RES;
		std::cout << CYAN << "myset.insert(1337) \n" << RES;
		ft::pair<ft::set<int>::iterator, bool> ret = myset.insert(1337);
		std::cout << "ret first = " << *ret.first << "\nret second = " << ret.second << std::endl;
		std::cout << CYAN << "myset \n" << RES;
		print_info(myset);
		std::cout << CYAN << "myset.insert(1337) \n" << RES;
		ret = myset.insert(1337);
		std::cout << "ret first = " << *ret.first << "\nret second = " << ret.second << std::endl;
		std::cout << CYAN << "myset \n" << RES;
		print_info(myset);
		std::cout << CYAN << "myset.insert(myset.begin(), 42) \n" << RES;
		ft::set<int>::iterator ret_it = myset.insert(myset.begin(), 42);
		std::cout << "ret = " << *ret_it << std::endl;
		std::cout << CYAN << "myset \n" << RES;
		print_info(myset);
		std::cout << CYAN << "myset.insert(myset.begin(), 42) \n" << RES;
		ret_it = myset.insert(myset.begin(), 42);
		std::cout << "ret = " << *ret_it << std::endl;
		std::cout << CYAN << "myset \n" << RES;
		print_info(myset);
		std::cout << CYAN << "secondset \n" << RES;
		ft::set<int> secondset;
		std::cout << CYAN << "secondset.insert(myset.begin(), myset.end()); \n" << RES;
		secondset.insert(myset.begin(), myset.end());
		print_info(secondset);
	}

	std::cout << YELLOW << "::::::::::::::ERASE:::::::::::::::::\n" << RES ;
	{
		std::cout << CYAN << "first \n" << RES;
		ft::set<int> first;
		std::cout << CYAN << "first.insert(0 ... 4) \n" << RES;
		for (int i = 0; i < 5; i++)
			first.insert(i);
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
		std::set<int> foo,bar;
		std::cout << CYAN << "foo.insert(0 ... 4) \n" << RES;
		for (int i = 0; i < 5; i++)
			foo.insert(i);
		std::cout << CYAN << "foo.insert(555 ... 560) \n" << RES;
		for (int i = 555; i < 560; i++)
			bar.insert(i);
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
		ft::set<int> myset;
		std::cout << CYAN << "foo.insert(0 ... 4) \n" << RES;
		for (int i = 0; i < 5; i++)
			myset.insert(i);
		std::cout << CYAN << "myset \n" << RES;
		print_info(myset);
		std::cout << CYAN << "ft::set<int>::iterator it = myset.find(4) \n" << RES;
		ft::set<int>::iterator it = myset.find(4);
		std::cout << CYAN << "myset.erase (it) \n" << RES;
		if (it != myset.end())
			myset.erase (it);
		std::cout << CYAN << "myset \n" << RES;
		print_info(myset);
	}

	std::cout << YELLOW << "::::::::::::::::COUNT:::::::::::::::\n" << RES ;
	{
		ft::set<int> myset;
		std::cout << CYAN << "foo.insert(0 ... 4) \n" << RES;
		for (int i = 0; i < 5; i++)
			myset.insert(i);
		std::cout << CYAN << "myset \n" << RES;
		print_info(myset);
		std::cout << CYAN << "myset.count(1) \n" << RES;
		std::cout << myset.count(1) << std::endl;
		std::cout << CYAN << "myset.count(5) \n" << RES;
		std::cout << myset.count(5) << std::endl;
	}

	std::cout << YELLOW << "::::::::::::::::BOUNDS::::::::::::::\n" << RES ;
	{
		ft::set<int> myset;
		ft::set<int>::iterator itlow,itup;
		std::cout << CYAN << "foo.insert(0 ... 4) \n" << RES;
		for (int i = 0; i < 5; i++)
			myset.insert(i);
		std::cout << CYAN << "myset \n" << RES;
		print_info(myset);
		std::cout << CYAN << "ft::set<int>::iterator itlow = myset.lower_bound (2) \n" << RES;
		itlow=myset.lower_bound (2);
		itup=myset.upper_bound (4);
		std::cout << "itlow = " << *itlow << std::endl;
		std::cout << CYAN << "ft::set<int>::iterator itlow = myset.upper_bound (4) \n" << RES;
		std::cout << "itup = myset.end()" << std::endl;
		myset.erase(itlow,itup);
		std::cout << CYAN << "myset.erase(itlow,itup); \n" << RES;
		std::cout << CYAN << "myset \n" << RES;
		print_info(myset);
	}

	std::cout << YELLOW << ":::::::::::::EQUAL_RANGE::::::::::::\n" << RES ;
	{
		ft::set<int> myset;
		std::cout << CYAN << "foo.insert(0 ... 4) \n" << RES;
		for (int i = 0; i < 5; i++)
			myset.insert(i);
		std::cout << CYAN << "myset \n" << RES;
		print_info(myset);
		ft::pair<ft::set<int>::iterator,ft::set<int>::iterator> ret;
		ret = myset.equal_range(2);
		std::cout << CYAN << "ft::pair<ft::set<int>::iterator,ft::set<int>::iterator> ret = myset.equal_range(2); \n" << RES;
		std::cout << "ret.first = ";
		std::cout << *ret.first << '\n';
		std::cout << "ret.second = ";
		std::cout << *ret.second << '\n';
	}

	std::cout << YELLOW << ":::::::::RELATIONAL_OPERATORS::::::::\n" << RES ;
	{
		ft::set<char> foo,bar;
		foo.insert('a');
		foo.insert('b');
		bar.insert('a');
		bar.insert('z');
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

	return 0;
}