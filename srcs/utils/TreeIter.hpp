#pragma once

#include "BidirectionalIter.hpp"
#include "Node.hpp"

template <class T>
class TreeIter : public BidirectionalIter<Node<T> > {
public:
	typedef	T															value_type;
	typedef T*															pointer;
	typedef T&															reference;
	typedef	Node<T> 													node;
	typedef typename BidirectionalIter<Node<T> >::value_type 			node_value_type;
	typedef typename BidirectionalIter<Node<T> >::difference_type		node_difference_type;
	typedef typename BidirectionalIter<Node<T> >::pointer 				node_pointer;
	typedef typename BidirectionalIter<Node<T> >::reference 			node_reference;
	typedef typename std::bidirectional_iterator_tag					iterator_category;

	TreeIter(void) : BidirectionalIter<Node<T> >() {}
	TreeIter(node_pointer x) : BidirectionalIter<Node<T> >(x) {}
//	TreeIter(const node_pointer x) : BidirectionalIter<Node<T> >(x) {}
	~TreeIter(void) {}

	TreeIter& 		operator++() {
		node_pointer 	node = this->_i_pointer;
		if (node->_right){
			node = node->_right;
			while (node->_left != NULL)
				node = node->_left;
			this->_i_pointer = node;
		} else {
			node_pointer	parent = node->_parent;
			while (parent != NULL && node == parent->_right){
				node = parent;
				parent = parent->_parent;
			}
			this->_i_pointer = parent;
		}
		return (*this);
	};

	TreeIter		operator++(int) { TreeIter tmp(*this); ++(*this); return tmp; }

	pointer			operator->() { return (this->_i_pointer->_value); }
};