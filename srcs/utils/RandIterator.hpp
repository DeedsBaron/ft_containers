#pragma once

#include "Bidirectionalterator.hpp"

template < class T >
class RandIterator : public Bidirectionalterator<T>{
public:
	typedef typename Bidirectionalterator<T>::value_type 		value_type;
	typedef typename Bidirectionalterator<T>::difference_type	difference_type;
	typedef typename Bidirectionalterator<T>::pointer 			pointer;
	typedef typename Bidirectionalterator<T>::reference 		reference;
	typedef typename Bidirectionalterator<T>::const_reference 	const_reference;
	typedef typename std::random_access_iterator_tag			iterator_category;
	//constructors && destructor
	RandIterator(void) : Bidirectionalterator<T>() {}
	RandIterator(pointer x) : Bidirectionalterator<T>(x) {}
	RandIterator(const RandIterator<typename ft::remove_const<T>::type>& iter) : Bidirectionalterator<T>(iter) {}
	~RandIterator(void) {}
	//overloaded functions

	reference 				operator*() { return *this->getP(); }
	const_reference 		operator*() const { return *this->getP(); }
	RandIterator 			operator+(difference_type n) const { return (this->getP() + n); }
	friend RandIterator		operator+(difference_type n, const RandIterator& ins) { return (ins._i_pointer + n); }
	RandIterator 			operator-(difference_type n) const { return (this->getP() - n); }
	difference_type 		operator-(const RandIterator& ins) const { return (this->getP() - ins._i_pointer); }
	template <class A, class B>
	friend bool 			operator<(const RandIterator<A>& lhs, const RandIterator<B>& rhs);
	template <class A, class B>
	friend bool 			operator>(const RandIterator<A>& lhs, const RandIterator<B>& rhs);
	template <class A, class B>
	friend bool 			operator<=(const RandIterator<A>& lhs, const RandIterator<B>& rhs);
	template <class A, class B>
	friend bool 			operator>=(const RandIterator<A>& lhs, const RandIterator<B>& rhs);
	template <class A, class B>
	friend bool 			operator<(const RandIterator<A>& lhs, const RandIterator<B>& rhs);
	RandIterator&			operator+=(difference_type n) { this->getP() += n; return (*this); }
	RandIterator&			operator-=(difference_type n) { this->getP() -= n; return (*this); }
	reference 				operator[](difference_type n) { return (*operator+(n)); }

};

template<class A, class B>
bool operator<(const RandIterator<A>& lhs, const RandIterator<B>& rhs) {
	return (lhs.getP() < rhs.getP());
}

template<class A, class B>
bool operator>(const RandIterator<A>& lhs, const RandIterator<B>& rhs) {
	return (lhs.getP() > rhs.getP());
}

template<class A, class B>
bool operator<=(const RandIterator<A>& lhs, const RandIterator<B>& rhs) {
	return (lhs.getP() <= rhs.getP());
}

template<class A, class B>
bool operator>=(const RandIterator<A>& lhs, const RandIterator<B>& rhs) {
	return (lhs.getP() >= rhs.getP());
}


