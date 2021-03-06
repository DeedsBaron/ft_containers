#pragma once

#include <iterator>

template < class T >
class BidirectionalIter {
public:
	typedef T												value_type;
	typedef typename std::ptrdiff_t							difference_type;
	typedef T*												pointer;
	typedef T&												reference;
	typedef typename std::bidirectional_iterator_tag		iterator_category;
	//constructors && destructor
	BidirectionalIter(void) : _i_pointer(NULL) {}
	BidirectionalIter(pointer x) : _i_pointer(x) {}
	BidirectionalIter(const BidirectionalIter& iter) { *this = iter; }
	virtual ~BidirectionalIter(void) {}
	//overloaded functions
	BidirectionalIter&		operator=(const BidirectionalIter& ins) {
		if (this == &ins)
			return *this;
		_i_pointer = ins._i_pointer;
		return *this;
	}
	bool 					operator==(const BidirectionalIter& ins) { return (_i_pointer == ins._i_pointer); }
	bool 					operator!=(const BidirectionalIter& ins) { return (_i_pointer != ins._i_pointer); }
	reference 				operator*() const { return *_i_pointer; }
	pointer 				operator->() { return _i_pointer; }
	BidirectionalIter&		operator++() { ++_i_pointer; return (*this); }
	BidirectionalIter		operator++(int) { BidirectionalIter tmp(*this); ++(*this); return tmp; }
	BidirectionalIter&		operator--() { --_i_pointer; return (*this); }
	BidirectionalIter		operator--(int) { BidirectionalIter tmp(*this); --(*this); return tmp; }
	pointer 				getP() const { return (_i_pointer); }
protected:
	pointer _i_pointer;
};