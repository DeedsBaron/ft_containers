#pragma once
#include "../utils/Utils.hpp"
<<<<<<< HEAD
#include "../utils/Bidirectionalterator.hpp"
#include "../utils/RBTree.hpp"
#include "../utils/TreeIter.hpp"
#include "../utils/ReverseIterator.hpp"

namespace ft {

	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {
	public:
		typedef Key 												key_type;
		typedef T 													mapped_type;
		typedef pair<const key_type, mapped_type> 					value_type;
		typedef Compare 											key_compare;
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
		class value_compare {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			friend class map;
		protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {}
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
		};

		RBTree<value_type, value_compare, allocator_type> _rbtree;
		allocator_type _alloc;
		key_compare _comp;

	public:
		//constructors
		explicit map(const key_compare& comp = key_compare(), const allocator_type &alloc = allocator_type()) :
				_rbtree(comp, alloc), _alloc(alloc), _comp(comp) {}

		template<class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type()) :
				_rbtree(comp, alloc), _alloc(alloc), _comp(comp) { _rbtree.insert(first, last); }

		map(const map& x) : _rbtree(x._comp, x._alloc) { *this = x; }

		map&	operator=(const map& ins) {
			if (this == &ins)
				return *this;
			_comp = ins._comp;
			_alloc = ins._alloc;
			_rbtree = ins._rbtree;

			return *this;
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
		//element access
		mapped_type 							&operator[](const key_type &k) {
			return (((this->insert(ft::make_pair(k, mapped_type()))).first))->second;
		}
		//modifiers
		ft::pair<iterator, bool> 				insert(const value_type &val) { return (_rbtree.insert(val)); }
		iterator								insert(iterator position, const value_type &val) { return (_rbtree.insert(position, val)); };
		template<class InputIterator>
		void 									insert(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
			_rbtree.insert(first, last);
		}
		void									erase(iterator position) { _rbtree.erase(position); }
		size_type								erase(const Key &key) { return (_rbtree.erase(ft::make_pair(key, mapped_type()))); }
		void									erase(iterator first, iterator last) { return (_rbtree.erase(first, last)); };
		void 									swap(map& x) { _rbtree.swap(x._rbtree); };
		void									clear() { _rbtree.clear(); };
		//observers
		key_compare								key_comp() const { return (_comp); }
		value_compare							value_comp() const { return (value_compare(key_compare())); }
		//operations
		iterator								find(const key_type& k) { return (_rbtree.find(ft::make_pair(k, mapped_type()))); }
		const_iterator							find(const key_type& k) const { return (_rbtree.find(ft::make_pair(k, mapped_type()))); }
		size_type								count(const key_type& k) const { return (_rbtree.search(ft::make_pair(k, mapped_type())) == NULL ? 0 : 1); }
		iterator 								lower_bound(const key_type& k) { return (_rbtree.lower_bound(ft::make_pair(k, mapped_type()))); }
		const_iterator 							lower_bound(const key_type& k) const { return (_rbtree.lower_bound(ft::make_pair(k, mapped_type()))); }
		iterator 								upper_bound(const key_type& k) { return (_rbtree.upper_bound(ft::make_pair(k, mapped_type()))); }
		const_iterator 							upper_bound(const key_type& k) const { return (_rbtree.upper_bound(ft::make_pair(k, mapped_type()))); }
		ft::pair<iterator, iterator> 			equal_range(const key_type &k) { return (_rbtree.equal_range(ft::make_pair(k, mapped_type()))); }
		ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const { return (_rbtree.equal_range(ft::make_pair(k, mapped_type()))); }
		//allocator
		allocator_type 							get_allocator() const { return (_alloc); };
	};

	template<class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs){
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));;
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs){
		return !(lhs == rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs){
		return (rhs < lhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs){
		return !(lhs > rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs){
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) {
		x.swap(y);
	}
=======
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
>>>>>>> 9f4e9a7... stack n vector done, welcome 2 red-black hell))))
};