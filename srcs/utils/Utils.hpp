#pragma once

#include <iostream>
#include "Node.hpp"

namespace ft {
	template<bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };


	template<class T>
	struct remove_const { typedef T type; };

	template<class T>
	struct remove_const <const T> { typedef T type; };


	template <typename T>
	struct is_integral { static const bool value = false; };

	template <>
	struct is_integral<bool> { static const bool value = true; };

	template <>
	struct is_integral<char> { static const bool value = true; };

	template <>
	struct is_integral<short> { static const bool value = true; };

	template <>
	struct is_integral<int> { static const bool value = true; };

	template <>
	struct is_integral<long> { static const bool value = true; };

	template <>
	struct is_integral<long long> { static const bool value = true; };

	template <>
	struct is_integral<unsigned char> { static const bool value = true; };

	template <>
	struct is_integral<unsigned short> { static const bool value = true; };

	template <>
	struct is_integral<unsigned int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long long> { static const bool value = true; };

	template <class InputIterator1, class InputIterator2>
	bool		lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2){
		while (first1 != last1){
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			else {
				first1++;
				first2++;
			}
		}
		return (first2 != first1);
	};

	template <class T1, class T2>
	struct pair{
		typedef T1		first_type;
		typedef T2		second_type;

		first_type		first;
		second_type		second;

		pair() : first(T1()), second(T2()) {};
		pair(const first_type& a, const second_type& b) : first(a), second(b) {};
		template<class U, class V>
		pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {};
		~pair() {};

		pair&	operator=(const pair& pr) {
			if (this == &pr)
				return (*this);
			first = pr.first;
			second = pr.second;
			return (*this);
		};
	};

	template <class T1,class T2>
	pair<T1, T2>		make_pair(T1 x, T2 y) { return (pair<T1, T2>(x,y)); }
};

struct Trunk
{
	Trunk *prev;
	std::string str;

	Trunk(Trunk *prev, std::string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

void showTrunks(Trunk *p)
{
	if (p == NULL) {
		return;
	}

	showTrunks(p->prev);
	std::cout << p->str;
}