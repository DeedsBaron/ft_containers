#pragma once
#include "../utils/Utils.hpp"
#include "../utils/BidirectionalIter.hpp"

namespace ft{

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map{
	public:
		typedef	Key													key_type;
		typedef T													mapped_type;
		typedef pair<const key_type, mapped_type>					value_type;
		typedef Compare												key_compare;
		//typedef value_compare
		typedef Alloc												allocator_type;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef BidirectionalIter<mapped_type>						iterator;
		typedef BidirectionalIter<const mapped_type>				const_iterator;
		typedef ReverseIterator<iterator>							reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type difference_type;
		typedef size_t												size_type;

	private:
		allocator_type		_alloc;
		key_compare			_comp;


	};
};