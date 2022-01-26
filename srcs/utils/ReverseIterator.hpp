#pragma once

#include "Utils.hpp"

template <class Iterator>
class iterator_traits {
public:
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};

template <class T>
class iterator_traits<T*> {
public:
	typedef std::ptrdiff_t							difference_type;
	typedef T										value_type;
	typedef T*										pointer;
	typedef T&										reference;
	typedef	std::random_access_iterator_tag			iterator_category;
};

template <class T>
class iterator_traits<const T*> {
public:
	typedef std::ptrdiff_t							difference_type;
	typedef const T									value_type;
	typedef const T*								pointer;
	typedef const T&								reference;
	typedef	std::random_access_iterator_tag			iterator_category;
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