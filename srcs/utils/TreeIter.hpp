#pragma once

#include "BidirectionalIter.hpp"
#include "Node.hpp"

template <class T>
class TreeIter : public BidirectionalIter<T> {
public:
	typedef typename BidirectionalIter<T>::value_type 			value_type;
	typedef typename BidirectionalIter<T>::difference_type		difference_type;
	typedef typename BidirectionalIter<T>::pointer 				pointer;
	typedef typename BidirectionalIter<T>::reference 			reference;
	typedef typename std::bidirectional_iterator_tag			iterator_category;
	TreeIter(void) : BidirectionalIter<T>() {}
	TreeIter(pointer x) : BidirectionalIter<T>(x) {}
	~TreeIter() {}
	TreeIter&		operator++() {
		Node<T>*	node = BidirectionalIter<T>::_i_pointer;
		if (node->_right){
			node = node->_right;
			while (node->_left != NULL)
				node = node->_left;
		} else {
			Node<T>*	parent = node->_parent;
			while (parent != NULL && node == parent->_right){
				node = parent;
				parent = parent->_parent;
			}
		}
		return (*this);
	};
};