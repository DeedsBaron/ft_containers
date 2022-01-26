#pragma once

#include <iterator>
#include "Utils.hpp"

template < class T >
class Bidirectionalterator {
public:
	typedef T												value_type;
	typedef typename std::ptrdiff_t							difference_type;
	typedef T*												pointer;
	typedef T&												reference;
	typedef const T&										const_reference;
	typedef typename std::bidirectional_iterator_tag		iterator_category;
	//constructors && destructor
	Bidirectionalterator(void) : _i_pointer(NULL) {}
	Bidirectionalterator(pointer x) : _i_pointer(x) {}
	Bidirectionalterator(const Bidirectionalterator<typename ft::remove_const<T>::type>& iter) { *this = iter; }
	virtual ~Bidirectionalterator(void) {}
	//overloaded functions
	Bidirectionalterator&		operator=(const Bidirectionalterator<typename ft::remove_const<T>::type>& ins) {
		_i_pointer = ins.getP();
		return *this;
	}
	bool 						operator==(const Bidirectionalterator& ins) { return (_i_pointer == ins._i_pointer); }
	bool 						operator!=(const Bidirectionalterator& ins) { return (_i_pointer != ins._i_pointer); }
	reference 					operator*() { return *_i_pointer; }
	const_reference 			operator*() const { return *_i_pointer; }
	pointer 					operator->() { return _i_pointer; }
	Bidirectionalterator&		operator++() { ++_i_pointer; return (*this); }
	Bidirectionalterator		operator++(int) { Bidirectionalterator tmp(*this); ++(*this); return tmp; }
	Bidirectionalterator&		operator--() { --_i_pointer; return (*this); }
	Bidirectionalterator		operator--(int) { Bidirectionalterator tmp(*this); --(*this); return tmp; }
	pointer 					getP() const { return (_i_pointer); }
protected:
	pointer _i_pointer;
};