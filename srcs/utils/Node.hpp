#pragma once

#include <iostream>
#include "Utils.hpp"
#define BLACK_N 1

template <class T>
struct Node {
	typedef	T										value_type;
	typedef std::allocator<value_type>				allocator_type;
	typedef	typename allocator_type::pointer		pointer;

	allocator_type				_alloc;
	pointer						_value;
	int 						_color;
	Node<T>*					_left;
	Node<T>*					_right;
	Node<T>*					_parent;

	Node(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _value(NULL), _color(BLACK_N), _left(NULL), _right(NULL), _parent(NULL) {};
	Node(const value_type& value, int _color, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _color(_color), _left(NULL), _right(NULL), _parent(NULL) { _value = _alloc.allocate(1); _alloc.construct(_value, value); };
	virtual ~Node() {}
};

template <class T>
struct NilNode : public Node<T> {
	NilNode() : Node<T>() {}
	~NilNode() {}
};