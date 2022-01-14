#pragma once

#include "BidirectionalIter.hpp"
#include "Node.hpp"

template <class T>
class TreeIter {
public:
	typedef	T															value_type;
	typedef T*															pointer;
	typedef T&															reference;
	typedef	Node<T>* 													node_pointer;
	typedef typename std::bidirectional_iterator_tag					iterator_category;
	typedef typename std::ptrdiff_t										difference_type;

	TreeIter(void) : _i_pointer(NULL) {}
	TreeIter(node_pointer x) : _i_pointer(x) {};
//	TreeIter(const node_pointer x) : BidirectionalIter<Node<T> >(x) {}
	~TreeIter(void) {}

//	Node<ft::pair<const int, char> > * <const ft::pair<const int, char> >
//	operator TreeIter<>() {return my_list_iterator<const Node>{pos_};}
	bool 					operator!=(const TreeIter& ins) { return (_i_pointer != ins._i_pointer); }

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

private:
	node_pointer _i_pointer;
};