#pragma once

#include <iostream>
#include "../utils/RandIterator.hpp"
#include "../utils/Utils.hpp"
#include "../utils/ReverseIterator.hpp"

namespace ft{

    template < class T, class Alloc = std::allocator<T> >
    class vector{
    public:
        typedef	T                                           value_type;
        typedef	Alloc                                 		allocator_type;
		typedef typename allocator_type::reference			reference;
        typedef typename allocator_type::const_reference	const_reference;
        typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer      const_pointer;
		typedef	RandIterator<value_type>					iterator;
		typedef	RandIterator<const value_type>				const_iterator;
		typedef	ReverseIterator<iterator>					reverse_iterator;
		typedef	ReverseIterator<const_iterator>				const_reverse_iterator;
		typedef size_t 										size_type;
		//constructors
		vector(const vector& ins) : _alloc(ins._alloc), _start(NULL), _end(NULL), _end_capacity(NULL) { *this = ins; }
		explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _start(NULL), _end(NULL), _end_capacity(NULL) {};
        explicit vector(size_t n, const T& val = T(), const Alloc& alloc = allocator_type()) : _alloc(alloc) {
			_start = _alloc.allocate(n);
			_end = _start;
			_end_capacity = _start + n;
			while (n--){
				_alloc.construct(_end, val);
				_end++;
			}
		};
		template <class InputIterator>
		vector(InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type()) : _alloc(alloc) {
			size_type len = static_cast<size_type>(last - first);
			_start = _alloc.allocate(len);
			_end = _start;
			_end_capacity = _start + len;
			while (len--)
			{
				_alloc.construct(_end, *first++);
				_end++;
			}
		};
		//iterators
		iterator					begin(void) { return (_start); };
		iterator					end(void) { return (_end); };
		const_iterator				begin(void) const { return (_start); }
		const_iterator				end(void) const { return (_end); };
		reverse_iterator			rbegin() { return (reverse_iterator(this->end())); }
		reverse_iterator			rend() { return (reverse_iterator(this->begin())); };
		const_reverse_iterator		rbegin() const { return (reverse_iterator(this->end())); };
		const_reverse_iterator		rend() const { return (reverse_iterator(this->begin())); };
		//capacity
		size_type					max_size(void) const { return _alloc.max_size(); };
		size_type					size(void) const { return _end - _start; };
		void						resize(size_type n, value_type val = value_type()){
			if (n > capacity())
				reserve(n);
			if (n < size()){
				for (iterator buf = begin() + n; buf != end(); buf++){
					_alloc.destroy(&(*buf));
				}
				_end -= n - 1;
			} else {
				pointer buf = _end;
				_end += (n - size());
				while (buf != _end){
					_alloc.construct(buf, val);
					buf++;
				}
			}
		};
		size_type					capacity(void) const { return _end_capacity - _start; };
		bool						empty(void) const { return (size() == 0 ? true : false); };
		void						reserve (size_type n){
			if (n > this->max_size())
				throw (std::length_error("vector::reserve"));
			else if (n > capacity()){
				pointer new_start = _alloc.allocate(n);
				pointer new_end = new_start;
				pointer new_end_capacity = new_start + n;
				pointer iter = _start;
				size_type size = this->size();
				while (size--){
					_alloc.construct(new_end, *iter);
					new_end++;
					iter++;
				}
				clear();
				_alloc.deallocate(_start, capacity());
				_start = new_start;
				_end = new_end;
				_end_capacity = new_end_capacity;
			}
		};
		//element_access
		reference					operator[] (size_type n){
			return (*(_start + n));
		};
		const_reference				operator[] (size_type n) const{
			return (*(_start + n));
		};
		reference					at(size_type n){
			if (n >= size())
				throw std::out_of_range("vector");
			return ((*this)[n]);
		};
		const_reference				at(size_type n) const{
			if (n >= size())
				throw std::out_of_range("vector");
			return ((*this)[n]);
		};
		reference					front(void) { return (*_start); };
		const_reference				front(void) const { return (*_start); };
		reference					back() { return (*(_end - 1)); };
		const_reference 			back() const { return (*(_end - 1)); };
		//modifiers
		void 						assign(size_type n, const value_type& val) {
			this->clear();
			if (n > capacity())
				reserve(n);
			for (size_type i = 0; i < n; i++){
				_alloc.construct(_end, val);
				_end++;
			}
		};
		template <class InputIterator>
		void						assign(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
			size_type	len = last - first;
			this->clear();
			if (len > capacity())
				reserve(len);
			iterator	it = begin();
			while (first != last){
				_alloc.construct(&(*it), *first);
				first++;
				it++;
			}
			_end = &(*it);
		};
		void						push_back(const value_type& val) {
			if (size() + 1 <= capacity()){
				_alloc.construct(_start + size(), val);
				_end++;
			}
			else{
				this->reserve(2 * size() == 0 ? 1 : 2 * size());
				_alloc.construct(_start + size(), val);
				_end++;
			}
		};
		void						pop_back(){
			if (this->size() != 0){
				_alloc.destroy(_end - 1);
				_end--;
			}
		};
		iterator					insert(iterator position, const value_type& val){
			size_type	posi = position - begin();
			if (size() + 1 <= capacity()) {
				_end += 1;
				for (pointer buf = _end - 1; buf != &(*position); buf--) {
					_alloc.construct(&(*buf), *(buf - 1));
				}
				_alloc.construct(&(*position), val);
			} else {
				reserve(size() > 0 ? 2 * capacity() : 1);
				insert(begin() + posi, val);
			}
			return (begin() + posi);
		};
		void						insert (iterator position, size_type n, const value_type& val){
			size_type	posi = position - begin();
			if (size() + n <= capacity()) {
				_end += n;
				pointer buf = _end - 1;
				while((buf - &(*position)) >= static_cast<long> (n)) {
					_alloc.construct(buf, *(buf-n));
					buf--;
				}
				while(n--) {
					_alloc.construct(&(*position) + n, val);
				}
			} else {
				this->reserve(size() > 0 ? capacity() * 2 : n);
				this->insert(begin() + posi, n,  val);
			}
		};
		template <class InputIterator>
		void						insert (iterator position, InputIterator first, InputIterator last,
										typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
			size_type	posi = position - begin();
			size_type	len = last - first;
			if (size() + len <= capacity()) {
				_end += len;
				pointer buf = _end - 1;
				while((buf - &(*position)) >= static_cast<long> (len)) {
					_alloc.construct(buf, *(buf - len));
					buf--;
				}
				while(first != last) {
					_alloc.construct(&(*position), *(first));
					position++;
					first++;
				}
			} else {
				this->reserve(size() > 0 ? capacity() * 2 : len);
				this->insert(begin() + posi, first, last);
			}
		};
		void 						clear(void) {
			size_type size = this->size();
			for (size_type i = 0;  i < size; i++){
				_end--;
				_alloc.destroy(_end);
			}
		};
		iterator					erase(iterator position){
			if (position + 1 == end()){
				this->pop_back();
				return (end());
			}
			for (iterator buf(position); buf != end(); buf++){
				_alloc.destroy(&(*buf));
				_alloc.construct(&(*buf), *(buf + 1));
			}
			_end--;
			return (position);
		};
		iterator					erase(iterator first, iterator last){
			for (iterator buf(first); buf != end(); buf++){
				_alloc.construct(&(*buf), *(buf + (last - first)));
			}
			_end -= last - first;
			return (first);
		};
		void						swap(vector& x){
			if (this == &x)
				return ;
			pointer buf_st = x._start;
			pointer buf_end = x._end;
			pointer buf_end_cap = x._end_capacity;
			allocator_type buf_alloc = x._alloc;

			x._start = this->_start;
			x._end = this->_end;
			x._end_capacity = this->_end_capacity;
			x._alloc = this->_alloc;

			this->_start = buf_st;
			this->_end = buf_end;
			this->_end_capacity = buf_end_cap;
			this->_alloc = buf_alloc;
		};
		//utils
		vector&						operator=(const vector& ins){
			if (this == &ins)
				return (*this);
			this->assign(ins.begin(), ins.end());
			return (*this);
		};
		allocator_type				get_allocator() const { return _alloc; };
		~vector() {
			clear();
			_alloc.deallocate(_start, capacity());
		};
	private:
		allocator_type	_alloc;
		pointer			_start;
		pointer			_end;
		pointer			_end_capacity;
	};

	template <class T, class Alloc>
	bool		operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::vector<T>::const_iterator first1 = lhs.begin();
		typename ft::vector<T>::const_iterator first2 = rhs.begin();
		while (first1 != lhs.end())
		{
			if (first2 == rhs.end() || *first1 != *first2)
				return (false);
			++first1;
			++first2;
		}
		return (true);
	};

	template <class T, class Alloc>
	bool		operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (!(lhs == rhs));
	};

	template <class T, class Alloc>
	bool		operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template <class T, class Alloc>
	bool		operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (!(rhs < lhs));
	};

	template <class T, class Alloc>
	bool		operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (rhs < lhs);
	};

	template <class T, class Alloc>
	bool		operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (!(lhs < rhs));
	};

	template <class T, class Alloc>
	void		swap(vector<T,Alloc>& x, vector<T,Alloc>& y){
		x.swap(y);
	};
};

