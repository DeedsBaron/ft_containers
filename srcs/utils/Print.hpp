#pragma once
#include "../containers/Vector.hpp"
#include "../containers/Stack.hpp"
#include <vector>

template < typename T>
void 	print_cap(std::vector<T>& a1){
	std::cout << "cap = " << a1.capacity() << std::endl;
}

template < typename T>
void 	print_size(std::vector<T>& a1){
	std::cout << "size = " << a1.size() << std::endl;
}

template < typename T>
void 	print_cap(ft::vector<T>& a1){
	std::cout << "cap = " << a1.capacity() << std::endl;
}

template < typename T>
void 	print_size(ft::vector<T>& a1){
	std::cout << "size = " << a1.size() << std::endl;
}

template <typename T>
void 	print(ft::vector<T>& a1){
	for (typename ft::vector<T>::iterator it = a1.begin(); it != a1.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void 	print(std::vector<T>& a1){
	for (typename std::vector<T>::iterator it = a1.begin(); it != a1.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


template < typename T>
void	print_info(std::vector<T>& a1){
	std::cout << PURPLE << "::::::::::::::::::::::::::::::::::::\n" << RES;
	print(a1);
	print_size(a1);
	print_cap(a1);
	std::cout << PURPLE << "::::::::::::::::::::::::::::::::::::\n" << RES;
}

template < typename T>
void 	print_info(ft::vector<T>& a1){
	std::cout << PURPLE << "::::::::::::::::::::::::::::::::::::\n" << RES;
	print(a1);
	print_size(a1);
	print_cap(a1);
	std::cout << PURPLE << "::::::::::::::::::::::::::::::::::::\n" << RES;
}

template < typename T>
void	print_info(ft::stack<T>& a1){
	std::cout << PURPLE << "::::::::::::::::::::::::::::::::::::\n" << RES;
	print(a1);
	print_size(a1);
	print_cap(a1);
	std::cout << PURPLE << "::::::::::::::::::::::::::::::::::::\n" << RES;
}
