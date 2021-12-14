#pragma once
#include "../containers/Vector.hpp"
#include "../containers/Stack.hpp"
<<<<<<< HEAD
#include "../containers/Map.hpp"
#include "../containers/Set.hpp"
#include <vector>
#include <map>
#include <set>
=======
#include <vector>
>>>>>>> 9f4e9a7... stack n vector done, welcome 2 red-black hell))))

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
<<<<<<< HEAD

template <typename Key, typename T>
void 	print_info(std::map<Key, T>& map1){
	for (typename std::map<Key, T>::iterator it = map1.begin(); it != map1.end(); it++){
		std::cout << "Key = " << it->first << " Val = " << it->second << std::endl;
	}
}

template <typename Key, typename T>
void 	print_info(ft::map<Key, T>& map1){
	for (typename ft::map<Key, T>::iterator it = map1.begin(); it != map1.end(); it++){
		std::cout << "Key = " << it->first << " Val = " << it->second << std::endl;
	}
}

template <typename Key>
void 	print_info(std::set<Key>& map1){
	for (typename std::set<Key>::iterator it = map1.begin(); it != map1.end(); it++){
		std::cout << "Val = " << *it << std::endl;
	}
}

template <typename Key>
void 	print_info(ft::set<Key>& map1){
	for (typename ft::set<Key>::iterator it = map1.begin(); it != map1.end(); it++){
		std::cout << "Val = " << *it << std::endl;
	}
}
=======
>>>>>>> 9f4e9a7... stack n vector done, welcome 2 red-black hell))))
