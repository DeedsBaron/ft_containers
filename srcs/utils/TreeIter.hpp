#pragma once

#include "Bidirectionalterator.hpp"
#include "Node.hpp"

template < class T >
class TreeIter : public Bidirectionalterator< Node<typename ft::remove_const<T>::type> > {
public:
	typedef	T															value_type;
	typedef T*															pointer;
	typedef T&															reference;
	typedef const T&													const_reference;
	typedef	Node<typename ft::remove_const<T>::type>* 					node_pointer;
	typedef typename std::bidirectional_iterator_tag					iterator_category;
	typedef typename std::ptrdiff_t										difference_type;
	//constructors & destructor
	TreeIter(void) : Bidirectionalterator< Node<typename ft::remove_const<T>::type> > (NULL) {}
	TreeIter(node_pointer x) : Bidirectionalterator< Node<typename ft::remove_const<T>::type> >(x) {}
	TreeIter(const TreeIter<typename ft::remove_const<T>::type>& ins) :
				Bidirectionalterator< Node<typename ft::remove_const<T>::type> >(ins) {}
	~TreeIter(void) {}
	//operator overloads
	reference 				operator*() { return *(this->_i_pointer->_value); }
	const_reference 		operator*() const { return *(this->_i_pointer->_value); }
	pointer					operator->() { return (this->_i_pointer->_value); }
	TreeIter& 				operator++() {
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
	}
	TreeIter&				operator--() {
		node_pointer 	node = this->_i_pointer;
		if (node->_left){
			node = node->_left;
			while (node->_right != NULL)
				node = node->_right;
			this->_i_pointer = node;
		} else {
			node_pointer	parent = node->_parent;
			while (parent != NULL && node == parent->_left){
				node = parent;
				parent = parent->_parent;
			}
			this->_i_pointer = parent;
		}
		return (*this);
	}
	TreeIter				operator++(int) { TreeIter tmp(*this); ++(*this); return tmp; }
};
