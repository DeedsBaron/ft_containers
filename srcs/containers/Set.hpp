#pragma once

#include <iostream>
#include "../utils/TreeIter.hpp"
#include "../utils/ReverseIterator.hpp"


namespace ft {

	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set {
	public:
		typedef T 													key_type;
		typedef T 													value_type;
		typedef Compare 											key_compare;
		typedef	Compare												value_compare;
		typedef Alloc 												allocator_type;
		typedef typename allocator_type::reference 					reference;
		typedef typename allocator_type::const_reference 			const_reference;
		typedef typename allocator_type::pointer 					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef TreeIter<value_type>								iterator;
		typedef TreeIter<const value_type>							const_iterator;
		typedef	ReverseIterator<iterator>							reverse_iterator;
		typedef	ReverseIterator<const_iterator>						const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type difference_type;
		typedef size_t 												size_type;
	private:
		RBTree<key_type, mapped_type, key_compare, allocator_type> _rbtree;
		allocator_type _alloc;
		key_compare _comp;
	};
}