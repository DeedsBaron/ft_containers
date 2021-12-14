#include "../containers/Vector.hpp"
#include "../utils/Colors.hpp"
#include "../utils/Utils.hpp"
#include "../utils/Print.hpp"
#include <iostream>
#include <stack>
#include <vector>

int main() {
	std::cout << GREEN << "-------------=STDSTACK=-------------\n" << RES;

	std::cout << YELLOW << "::::::::::::CONSTRUCTORS::::::::::::\n" << RES;
	{
		std::vector<int> myvector(2, 200);
		std::stack<int> first;
		std::cout << CYAN << "ft::stack<int> first; \n" << RES;
		std::stack<int, std::vector<int> > second(myvector);
		std::cout << CYAN << "myvector(2,200) \n" << RES;
		std::cout << CYAN << "ft::stack<int> second(myvector) \n" << RES;
		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
	}

	std::cout << YELLOW << ":::::::::::::::::EMPTY::::::::::::::\n" << RES ;
	{
		std::vector<int> myvector(2, 200);
		std::stack<int> first;
		std::cout << CYAN << "ft::stack<int> first; \n" << RES;
		std::stack<int, std::vector<int> > second(myvector);
		std::cout << CYAN << "myvector(2,200) \n" << RES;
		std::cout << CYAN << "ft::stack<int> second(myvector) \n" << RES;
		std::cout << "empty(): " << first.empty() << '\n';
		std::cout << "empty(): " << second.empty() << '\n';
	}

	std::cout << YELLOW << ":::::::SIZE_POP_PUSH_TOP::::::::::::\n" << RES ;
	{
		std::stack<int> myints;
		std::cout << CYAN << "myints \n" << RES;
		std::cout << "size: " << myints.size() << '\n';
		std::cout << CYAN << "myints.push(i):\n" << RES;
		for (int i=0; i<5; i++) {
			myints.push(i);
			std::cout << i << " " << RES;
		}
		std::cout << std::endl;
		std::cout << "size: " << myints.size() << '\n';
		std::cout << CYAN << "myints.pop():\n" << RES;
		myints.pop();
		std::cout << "size: " << myints.size() << '\n';
		std::cout << CYAN << "myints.top(): \n" << RES << myints.top() << std::endl;
	}
	return 0;
}