#include <iostream>
#include "../utils/Colors.hpp"
#include "../utils/Print.hpp"
#include <vector>
#include <iomanip>

int main() {
	std::cout << GREEN << "-------------=STDVECTOR=-------------\n" << RES;
	//constructors
	std::cout << YELLOW << "::::::::::::CONSTRUCTORS::::::::::::\n" << RES ;
	{
		std::vector<int> first;
		std::vector<int> second (4,100);
		std::vector<int> third (second.begin(),second.end());  // iterating through second
		std::vector<int> fourth (third);
		std::cout << CYAN << "first \n" << RES;
		print_info(first);
		std::cout << CYAN << "second(4, 100)\n" << RES;
		print_info(second);
		std::cout << CYAN << "third(second.begin(), second.end())\n" << RES;
		print_info(third);
		std::cout << CYAN << "fourth(third)\n" << RES;
		print_info(fourth);
	}

	std::cout << YELLOW << ":::::::::::::OPERATOR=::::::::::::::\n" << RES ;
	{
		std::vector<int> foo (3,0);
		std::vector<int> bar (5,0);
		std::cout << CYAN << "foo(3, 0) \n" << RES;
		print_info(foo);
		std::cout << CYAN << "bar(5, 0)\n" << RES;
		print_info(bar);
		bar = foo;
		std::cout << CYAN << "bar = foo\n" << RES;
		std::cout << CYAN << "print bar\n" << RES;
		print_info(bar);
	}
	//iterators
	std::cout << YELLOW << ":::::::::::FORWARD_ITERS::::::::::::\n" << RES ;
	{
		ft::vector<int> myvector;
		std::cout << CYAN << "myvector \n" << RES;
		for (int i=1; i<=5; i++) myvector.push_back(i);
		std::cout << CYAN << "myvector.push_back(1..5) \n" << RES;
		std::cout << CYAN << "iterator it = begin() \n" << RES;
		std::cout << CYAN << "*it = " << RES << *myvector.begin() << std::endl;
		std::cout << "myvector contains:";
		for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
	}

	std::cout << YELLOW << ":::::::::::REVERSED_ITERS:::::::::::\n" << RES ;
	{
		std::vector<int> myvector (5);
		std::cout << CYAN << "myvector(5) \n" << RES;
		int i=0;
		std::cout << CYAN << "rit = myvector.rbegin() \n" << RES;
		std::cout << CYAN << "for (; rit != myvector.rend(); ++rit) *rit = ++i \n" << RES;
		std::vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit != myvector.rend(); ++rit)
			*rit = ++i;
		std::cout << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	//capacity
	std::cout << YELLOW << ":::::::::::::::SIZE:::::::::::::::::\n" << RES ;
	{
		std::vector<int> myints;
		std::cout << CYAN << "myints\n" << RES;
		std::cout << "size: " << myints.size() << '\n';

		for (int i = 0; i < 10; i++) myints.push_back(i);
		std::cout << CYAN << "myints.pushback [0..9]\n" << RES;
		std::cout << "size: " << myints.size() << '\n';

		std::cout << CYAN << "myints.insert(myints.end(), 10, 100)\n" << RES;
		myints.insert(myints.end(), 10, 100);
		std::cout << "size: " << myints.size() << '\n';
		std::cout << CYAN << "myints.pop_back()\n" << RES;
		myints.pop_back();
		std::cout << "size: " << myints.size() << '\n';
	}

	std::cout << YELLOW << ":::::::::::::MAX_SIZE:::::::::::::::\n" << RES ;
	{
		std::vector<int> myvector;

		for (int i=0; i<100; i++) myvector.push_back(i);
		std::cout << CYAN << "myvector.pushback [0..99]\n" << RES;
		std::cout << "size: " << myvector.size() << "\n";
		std::cout << "capacity: " << myvector.capacity() << "\n";
		std::cout << "max_size: " << myvector.max_size() << "\n";

	}

	std::cout << YELLOW << "::::::::::::::RESIZE::::::::::::::::\n" << RES ;
	{
		std::vector<int> myvector;

		for (int i=1;i<10;i++) myvector.push_back(i);
		std::cout << CYAN << "myints.pushback [0..9]\n" << RES;
		print_info(myvector);
		std::cout << CYAN << "myints.resize(5)\n" << RES;
		myvector.resize(5);
		print_info(myvector);
		std::cout << CYAN << "myints.resize(8, 100)\n" << RES;
		myvector.resize(8,100);
		print_info(myvector);
		std::cout << CYAN << "myints.resize(12)\n" << RES;
		myvector.resize(12);
		print_info(myvector);
	}

	std::cout << YELLOW << ":::::::::::::::CAPACITY:::::::::::::\n" << RES ;
	{
		std::vector<int> myvector;
		std::cout << CYAN << "myvector(0, 0)\n" << RES;
		std::cout << "size: " << myvector.size() << '\n';
		std::cout << "capacity: " << myvector.capacity() << '\n';

		for (int i=0; i<100; i++) myvector.push_back(i);
		std::cout << CYAN << "myvector.pushback [0..99]\n" << RES;
		std::cout << "size: " << myvector.size() << '\n';
		std::cout << "capacity: " << myvector.capacity() << '\n';
		std::cout << "max_size: " << myvector.max_size() << '\n';
	}

	std::cout << YELLOW << "::::::::::::::::EMPTY:::::::::::::::\n" << RES ;
	{

		std::vector<int> myvector;
		std::cout << CYAN << "myvector(0, 0)\n" << RES;
		std::cout << CYAN << "myvector.empty(): " << RES << myvector.empty() << std::endl << RES;
		std::cout << CYAN << "myvector.pushback [0..99]\n" << RES;
		for (int i=0; i<100; i++) myvector.push_back(i);
		std::cout << CYAN << "myvector.empty(): " << RES << myvector.empty() << std::endl << RES;
	}

	std::cout << YELLOW << ":::::::::::::::RESERVE::::::::::::::\n" << RES ;
	{
		std::vector<int>::size_type sz;
		std::vector<int> foo;
		sz = foo.capacity();
		std::cout << CYAN << "foo(0, 0)\n" << RES;
		std::cout << CYAN << "foo.pushback [0..99]\n" << RES;
		for (int i = 0; i < 100; ++i) {
			foo.push_back(i);
			if (sz != foo.capacity()) {
				sz = foo.capacity();
				std::cout << "capacity changed: " << sz << '\n';
			}
		}
		std::vector<int> bar;
		std::cout << CYAN << "bar(0, 0)\n" << RES;
		std::cout << CYAN << "bar.reserve(100)\n" << RES;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		for (int i = 0; i < 100; ++i) {
			bar.push_back(i);
			if (sz != bar.capacity()) {
				sz = bar.capacity();
				std::cout << "capacity changed: " << sz << '\n';
			}
		}
	}
	//element_access
	std::cout << YELLOW << ":::::::::::::OPERATOR_[]::::::::::::\n" << RES ;
	{
		std::vector<int> foo;
		std::cout << CYAN << "foo(0, 0)\n" << RES;
		std::cout << CYAN << "foo.pushback [0..99]\n" << RES;
		for (int i = 0; i < 100; i++) foo.push_back(i);
		print_info(foo);
		std::cout << CYAN << "foo[0]:" << RES << foo[0] << std::endl;
		std::cout << CYAN << "foo[99]:" << RES << foo[99] << std::endl;
		const std::vector<int> bar(5, 5);
		std::cout << CYAN << "const bar(5, 5)\n" << RES;
		std::cout << CYAN << "bar[0]:" << RES << bar[0] << std::endl;
		std::cout << CYAN << "bar[4]:" << RES << bar[4] << std::endl;
	}

	std::cout << YELLOW << ":::::::::::::OPERATOR_AT::::::::::::\n" << RES ;
	{
		std::vector<int> foo;
		std::cout << CYAN << "foo(0, 0)\n" << RES;
		std::cout << CYAN << "foo.pushback [0..99]\n" << RES;
		for (int i = 0; i < 100; i++) foo.push_back(i);
		print_info(foo);
		std::cout << CYAN << "foo.at(0):" << RES << foo.at(0) << std::endl;
		std::cout << CYAN << "foo.at(99):" << RES << foo.at(99) << std::endl;
		const std::vector<int> bar(5, 5);
		std::cout << CYAN << "const bar(5, 5)\n" << RES;
		std::cout << CYAN << "bar.at(0):" << RES << bar.at(0) << std::endl;
		try{
			std::cout << CYAN << "bar.at(5):" << RES << bar.at(5) << std::endl;
		}
		catch (const std::out_of_range& oor) {
			std::cerr << RED << "Out of Range error: " << oor.what() << '\n' << RES;
		}
	}

	std::cout << YELLOW << "::::::::::::::::FRONT:::::::::::::::\n" << RES ;
	{
		std::vector<int> foo;
		std::cout << CYAN << "foo(0, 0)\n" << RES;
		std::cout << CYAN << "foo.pushback [0..99]\n" << RES;
		for (int i = 0; i < 100; i++) foo.push_back(i);
		std::cout << CYAN << "foo.front(): " << RES << foo.front() << std::endl;
		const std::vector<int> bar(5, 5);
		std::cout << CYAN << "const bar(5, 5)\n" << RES;
		std::cout << CYAN << "bar.front(): " << RES << bar.front() << std::endl;
	}

	std::cout << YELLOW << "::::::::::::::::BACK::::::::::::::::\n" << RES ;
	{
		std::vector<int> foo;
		std::cout << CYAN << "foo(0, 0)\n" << RES;
		std::cout << CYAN << "foo.pushback [0..99]\n" << RES;
		for (int i = 0; i < 100; i++) foo.push_back(i);
		std::cout << CYAN << "foo.front(): " << RES << foo.back() << std::endl;
		const std::vector<int> bar(5, 5);
		std::cout << CYAN << "const bar(5, 5)\n" << RES;
		std::cout << CYAN << "bar.front(): " << RES << bar.back() << std::endl;
	}
	//modifiers
	std::cout << YELLOW << ":::::::::::::::ASSIGN:::::::::::::::\n" << RES ;
	{
		std::vector<int> first;
		std::vector<int> second;
		std::vector<int> third;
		std::cout << CYAN << "first(0, 0)\n" << RES;
		std::cout << CYAN << "second(0, 0)\n" << RES;
		std::cout << CYAN << "third(0, 0)\n" << RES;
		std::cout << CYAN << "first.assign(7, 100)\n" << RES;
		first.assign (7,100);         // 7 ints with a value of 100
		print_info(first);
		std::vector<int>::iterator it;
		it = first.begin()+1;
		std::cout << CYAN << "second.assign(first.begin() + 1, first.end() - 1)\n" << RES;
		second.assign (it,first.end()-1); // the 5 central values of first
		print_info(second);
		int myints[] = {1776,7,4};
		std::cout << CYAN << "myints = {1776, 7, 4}\n" << RES;
		std::cout << CYAN << "third.assign(myints, myints + 3)\n" << RES;
		third.assign (myints,myints+3);   // assigning from array.
		print_info(third);
	}

	std::cout << YELLOW << ":::::::::::::PUSH_BACK::::::::::::::\n" << RES ;
	{
		std::vector<int> myvector;
		std::cout << CYAN << "myvector \n" << RES;
		for (int i = 0; i < 4; i++) {
			std::cout << CYAN << "myvector.pushback(" << i << ")\n" << RES;
			myvector.push_back(i);
			for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		}
		print_info(myvector);
	}

	std::cout << YELLOW << ":::::::::::::POP_BACK:::::::::::::::\n" << RES ;
	{
		std::vector<int> myvector;
		for (int i = 0; i < 4; i++) myvector.push_back(i);
		std::cout << CYAN << "myvector \n" << RES;
		print_info(myvector);
		for (int i = 0; i < 4; i++) {
			std::cout << CYAN << "myvector.popback()\n" << RES;
			myvector.pop_back();
			for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		}
		print_info(myvector);
	}

	std::cout << YELLOW << "::::::::::::::INSERT::::::::::::::::\n" << RES ;
	{
		std::vector<int> myvector(3,100);
		std::cout << CYAN << "myvector(3, 100)\n" << RES;
		std::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );
		std::cout << CYAN << "insert(myvector.begin(), 200):\n" << RES;
		print_info(myvector);

		myvector.insert(it,2,300);
		std::cout << CYAN << "insert(myvector.begin(), 2, 300):\n" << RES;
		print_info(myvector);

		it = myvector.begin();

		std::vector<int> anothervector (2,400);
		std::cout << CYAN << "anothervector(2, 400)\n" << RES;
		std::cout << CYAN << "insert(myvector.begin() + 2, anothervector.begin(), anothervector.end()):\n" << RES;
		myvector.insert (it+2,anothervector.begin(),anothervector.end());
		print_info(myvector);

		int myarray [] = { 501,502,503 };
		std::cout << CYAN << "int myarray = {501, 502, 503}\n" << RES;
		myvector.insert (myvector.begin(), myarray, myarray+3);
		std::cout << CYAN << "insert(myvector.begin(), myarray, myarray + 3):\n" << RES;
		print_info(myvector);
	}

	std::cout << YELLOW << ":::::::::::::::ERASE::::::::::::::::\n" << RES ;
	{
		std::vector<int> myvector;
		std::cout << CYAN << "myvector \n" << RES;
		for (int i=1; i<=10; i++) myvector.push_back(i);
		print_info(myvector);
		std::cout << CYAN << "myvector.erase (myvector.begin()+5) \n" << RES;
		myvector.erase (myvector.begin()+5);
		print_info(myvector);
		std::cout << CYAN << "myvector.erase (myvector.begin(),myvector.begin()+3) \n" << RES;
		myvector.erase (myvector.begin(),myvector.begin()+3);
		print_info(myvector);
	}

	std::cout << YELLOW << "::::::::::::::::SWAP::::::::::::::::\n" << RES ;
	{
		std::vector<int> foo;
		for (int i=1; i<=10; i++) foo.push_back(i);
		std::vector<int> bar;
		for (int i=10; i>=1; i--) bar.push_back(i);
		std::cout << CYAN << "foo \n" << RES;
		print_info(foo);
		std::cout << CYAN << "bar \n" << RES;
		print_info(bar);
		std::cout << CYAN << "foo.swap(bar)\n" << RES;
		foo.swap(bar);
		std::cout << CYAN << "foo \n" << RES;
		print_info(foo);
		std::cout << CYAN << "bar \n" << RES;
		print_info(bar);
	}

	std::cout << YELLOW << "::::::::::::::::CLEAR:::::::::::::::\n" << RES ;
	{
		std::vector<int> foo;
		for (int i=1; i<=10; i++) foo.push_back(i);
		std::cout << CYAN << "foo \n" << RES;
		print_info(foo);
		std::cout << CYAN << "foo.clear()\n" << RES;
		foo.clear();
		print_info(foo);
	}

	std::cout << YELLOW << ":::::RELATIONAL_NON_MEMBER_FUNC:::::\n" << RES;
	{
		std::vector<int> foo(3, 666);
		std::cout << CYAN << "foo\n" << RES;
		print_info(foo);
		std::vector<int> bar(2, 1337);
		std::cout << CYAN << "bar\n" << RES;
		print_info(bar);
		std::cout << CYAN << "foo == bar \n" << RES;
		if (foo==bar) std::cout << "foo and bar are equal\n";
		std::cout << CYAN << "foo != bar \n" << RES;
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		std::cout << CYAN << "foo < bar \n" << RES;
		if (foo < bar) std::cout << "foo is less than bar\n";
		std::cout << CYAN << "foo > bar \n" << RES;
		if (foo > bar) std::cout << "foo is greater than bar\n";
		std::cout << CYAN << "foo <= bar \n" << RES;
		if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
		std::cout << CYAN << "foo >= bar \n" << RES;
		if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";

	}

	std::cout << YELLOW << ":::::::::SWAP_NON_MEMBER_FUNC:::::::\n" << RES;
	{
		std::vector<int> foo(3, 666);
		std::cout << CYAN << "foo\n" << RES;
		print_info(foo);
		std::vector<int> bar(2, 1337);
		std::cout << CYAN << "bar\n" << RES;
		print_info(bar);
		swap(foo,bar);
		std::cout << CYAN << "swap(foo, bar) \n" << RES;
		std::cout << CYAN << "foo\n" << RES;
		print_info(foo);
		std::cout << CYAN << "bar\n" << RES;
		print_info(bar);
	}
	std::cout << YELLOW << "::::::::::::::TIME_TESTS::::::::::::\n" << RES;
	{
		time_t 	start,end;
		std::vector<int> myvec;
		time(&start);
		for(int i = 0; i <100000000; i++)
			myvec.push_back(i);
		time(&end);
		std::cout << "Time taken by push_back is : " << std::fixed << float(end - start) << std::setprecision(5) << " sec \n";
		time(&start);
		std::vector<int> copy(myvec);
		time(&end);
		std::cout << "Time taken by deep copy is : " << std::fixed << float(end - start) << std::setprecision(5) << " sec \n";
		std::vector<int> myvec2;
		time(&start);
		myvec2.insert(myvec2.begin(), copy.begin(), copy.end());
		time(&end);
		std::cout << "Time taken by insert : " << std::fixed << float(end - start) << std::setprecision(5) << " sec \n";
		time(&start);
		myvec.erase(myvec.begin(), myvec.end());
		time(&end);
		std::cout << "Time taken by erase : " << std::fixed << float(end - start) << std::setprecision(5) << " sec \n";
	}
	return (0);
}