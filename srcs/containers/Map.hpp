#pragma once
#include "../utils/Utils.hpp"
#include "../utils/BidirectionalIter.hpp"
#include "../utils/RBTree.hpp"
#include "../utils/TreeIter.hpp"

namespace ft{

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
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
		typedef TreeIter<value_type>								iterator;
		typedef TreeIter<const value_type>							const_iterator;
		typedef ReverseIterator<iterator>							reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type difference_type;
		typedef size_t												size_type;

	private:
		RBTree<key_type, mapped_type, key_compare, allocator_type>	_rbtree;
		allocator_type												_alloc;
		key_compare													_comp;
		size_type													_size;
	public:
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			_rbtree(), _alloc(alloc), _comp(comp), _size(0) {};

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			_rbtree(), _alloc(alloc), _comp(comp), _size(0) { _rbtree.insert(first, last); };
		map (const map& x) ;



		ft::pair<iterator, bool>	insert(const value_type& val) { return (_rbtree.insert(val)); };
		iterator					insert(iterator position, const value_type& val) { return (_rbtree.insert(position, val)); };
		template <class InputIterator>
		void						insert(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) { _rbtree.insert(first, last); };

		void						erase(iterator position) { _rbtree.erase(position); };
		size_type					erase(const Key& key) { return _rbtree.erase(key); };
		void						erase(iterator first, iterator last) { return _rbtree.erase(first, last); };



		iterator					begin() { return (_rbtree.begin()); };
		iterator					end() { return (_rbtree.end()); };
		mapped_type& 				operator[](const key_type& k) {return (((this->insert(ft::make_pair(k, mapped_type()))).first))->second; };
		size_type 					size()	const { return _rbtree.get_size(); };
		bool						empty() const { return _rbtree.isEmpty(); };
		key_compare 				key_comp() const { return _comp; };
		void 	print(void) { _rbtree.print(); };
	};
};