#pragma once

#include <iostream>
#include "../utils/TreeIter.hpp"
#include "../utils/ReverseIterator.hpp"
#include "../utils/RBTree.hpp"

namespace ft {

	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set {
	public:
		typedef T 																		key_type;
		typedef T 																		value_type;
		typedef Compare 																key_compare;
		typedef	Compare																	value_compare;
		typedef Alloc 																	allocator_type;
		typedef typename allocator_type::reference 										reference;
		typedef typename allocator_type::const_reference 								const_reference;
		typedef typename allocator_type::pointer 										pointer;
		typedef typename allocator_type::const_pointer									const_pointer;
		typedef TreeIter<value_type>													iterator;
		typedef TreeIter<const value_type>												const_iterator;
		typedef	ReverseIterator<iterator>												reverse_iterator;
		typedef	ReverseIterator<const_iterator>											const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type 					difference_type;
		typedef size_t 																	size_type;
	private:
		value_compare									_comp;
		allocator_type									_alloc;
		RBTree<key_type, key_compare, allocator_type>	_rbtree;

	public:
		explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_comp(comp), _alloc(alloc), _rbtree(comp, alloc) {};
		template <class InputIterator>
		set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type()) :
			 	_comp(comp), _alloc(alloc), _rbtree(comp, alloc) { _rbtree.insert(first, last); }
		set(const set& x) : _rbtree(x._comp, x._alloc) { *this = x; }

		set&	operator=(const set& ins) {
			if (this == &ins)
				return (*this);
			_comp = ins._comp;
			_alloc = ins._alloc;
			_rbtree = ins._rbtree;
			return (*this);
		}
		//iterators
		iterator 								begin() { return(_rbtree.begin()); }
		const_iterator 							begin() const { return _rbtree.begin(); }
		iterator 								end() { return(_rbtree.end()); };
		const_iterator 							end() const { return(_rbtree.end()); }
		reverse_iterator						rbegin() { return (_rbtree.rbegin()); }
		const_reverse_iterator					rbegin() const { return (_rbtree.rbegin()); }
		reverse_iterator 						rend() { return (_rbtree.rend()); }
		const_reverse_iterator 					rend() const { return (const_reverse_iterator(begin())); }
		//capacity
		bool 									empty() const { return (_rbtree.get_size() == 0 ? true : false); }
		size_type 								size() const { return (_rbtree.get_size()); }
		size_type 								max_size() const { return (_rbtree.max_size()); };
		//modifiers
		ft::pair<iterator, bool> 				insert(const value_type &val) { return (_rbtree.insert(val)); }
		iterator								insert(iterator position, const value_type &val) { return (_rbtree.insert(position, val)); };
		template<class InputIterator>
		void 									insert(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
			_rbtree.insert(first, last);
		}
		void									erase(iterator position) { _rbtree.erase(position); }
		size_type								erase(const value_type& key) { return (_rbtree.erase(key)); }
		void									erase(iterator first, iterator last) { return (_rbtree.erase(first, last)); };
		void 									swap(set& x) { _rbtree.swap(x._rbtree); };
		void									clear() { _rbtree.clear(); };
		//observers
		key_compare								key_comp() const { return (_comp); }
		value_compare							value_comp() const { return (_comp); }
		//operations
		iterator								find(const key_type& k) { return (_rbtree.find(k)); }
		const_iterator							find(const key_type& k) const { return (_rbtree.find(k)); }
		size_type								count(const key_type& k) const { return (_rbtree.search(k) == NULL ? 0 : 1); }
		iterator 								lower_bound(const key_type& k) { return (_rbtree.lower_bound(k)); }
		const_iterator 							lower_bound(const key_type& k) const { return (_rbtree.lower_bound(k)); }
		iterator 								upper_bound(const key_type& k) { return (_rbtree.upper_bound(k)); }
		const_iterator 							upper_bound(const key_type& k) const { return (_rbtree.upper_bound(k)); }
		ft::pair<iterator, iterator> 			equal_range(const key_type &k) { return (_rbtree.equal_range(k)); }
		ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const { return (_rbtree.equal_range(k)); }
		//allocator
		allocator_type 							get_allocator() const { return (_alloc); };
	};

	template< class T, class Compare, class Alloc>
	bool operator==(const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs){
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));;
	}

	template< class T, class Compare, class Alloc>
	bool operator!=(const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs){
		return !(lhs == rhs);
	}

	template< class T, class Compare, class Alloc>
	bool operator<(const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class T, class Compare, class Alloc>
	bool operator>(const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs){
		return (rhs < lhs);
	}

	template< class T, class Compare, class Alloc>
	bool operator<=(const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs){
		return !(lhs > rhs);
	}

	template< class T, class Compare, class Alloc>
	bool operator>=(const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs){
		return !(lhs < rhs);
	}

	template < class T, class Compare, class Alloc>
	void swap(set<T, Compare, Alloc>& x, set<T, Compare, Alloc>& y) {
		x.swap(y);
	}
}