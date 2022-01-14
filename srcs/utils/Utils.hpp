#pragma once

#include <iostream>
#include "Node.hpp"

namespace ft {
	template<bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };


	template<class T> struct remove_const { typedef T type; };

	template<class T> struct remove_const <const T> { typedef T type; };


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

	template <class Iterator>
	class iterator_traits{
	public:
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

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

	template <typename iter>
	class ReverseIterator {
	public:
		typedef iter													iterator_type;
		typedef typename iterator_traits<iter>::iterator_category		iterator_category;
		typedef typename iterator_traits<iter>::value_type 				value_type;
		typedef typename iterator_traits<iter>::difference_type 		difference_type;
		typedef typename iterator_traits<iter>::pointer 				pointer;
		typedef typename iterator_traits<iter>::reference 				reference;

		ReverseIterator() : _it() {};
		explicit ReverseIterator(iterator_type it) : _it(it) {};
		template <class Iter>
		ReverseIterator(const ReverseIterator<Iter>& rev_it) : _it(rev_it.base()) {};
		virtual ~ReverseIterator() {};

		iterator_type		base() const { return _it; };
		reference			operator*() const {
			iterator_type tmp = _it;
			return (*(--tmp));
		};
		ReverseIterator		operator+(difference_type n) const { return (ReverseIterator(_it - n)); };
		ReverseIterator& 	operator++() {
			--_it;
			return (*this);
		};
		ReverseIterator		operator++(int) {
			ReverseIterator tmp = *this;
			++(*this);
			return (tmp);
		};
		ReverseIterator&	operator+= (difference_type n) {
			_it -= n;
			return (*this);
		};
		ReverseIterator		operator-(difference_type n) const { return (ReverseIterator(_it + n)); };
		ReverseIterator&	operator--() {
			++_it;
			return (*this);
		};
		ReverseIterator		operator--(int) {
			ReverseIterator tmp = *this;
			--(*this);
			return (tmp);
		};
		ReverseIterator&	operator-= (difference_type n) {
			_it += n;
			return (*this);
		};
		bool 				operator!=(const ReverseIterator& ins) { return (_it != ins._it); }
		pointer				operator->() const { return &(operator*()); };
		reference			operator[](difference_type n) const { return (this->base()[-n - 1]); };
	private:
		iterator_type		_it;
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
			if (&pr == this)
				return (*this);
			first = pr.first;
			second = pr.second;
			return (*this);
		};
	};

	template <class T1,class T2>
	pair<T1, T2>		make_pair(T1 x, T2 y) { return (pair<T1, T2>(x,y)); }
};