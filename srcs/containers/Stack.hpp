#pragma once

#include "Vector.hpp"

namespace ft{
	template <class T, class Container = ft::vector<T> >
	class stack{
	public:
		typedef	T				value_type;
		typedef Container		container_type;
		typedef size_t 			size_type;

		explicit				stack(const container_type& ctnr = container_type()) : _cntr(ctnr){};
		~stack() {};

		bool					empty() const { return (_cntr.empty()); };
		size_type				size() const { return (_cntr.size()); };
		value_type&				top() { return (_cntr.back()); };
		const value_type& 		top() const { return (_cntr.back()); };
		void					push (const value_type& val) { _cntr.push_back(val); };
		void					pop() { _cntr.pop_back(); };

		template <class TT, class Containerr>
		friend bool				operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
		template <class TT, class Containerr>
		friend bool				operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
		template <class TT, class Containerr>
		friend bool				operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
		template <class TT, class Containerr>
		friend bool				operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
		template <class TT, class Containerr>
		friend bool				operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
		template <class TT, class Containerr>
		friend bool				operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	private:
		container_type			_cntr;
	};

	template <class TT, class Containerr>
	bool						operator==(const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs) {
		return (lhs._cntr == rhs._cntr);
	};
	template <class TT, class Containerr>
	bool						operator!=(const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs) {
		return (lhs._cntr != rhs._cntr);
	};
	template <class TT, class Containerr>
	bool						operator<(const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs) {
		return (lhs._cntr < rhs._cntr);
	};
	template <class TT, class Containerr>
	bool						operator<=(const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs) {
		return (lhs._cntr <= rhs._cntr);
	};
	template <class TT, class Containerr>
	bool						operator>(const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs) {
		return (lhs._cntr > rhs._cntr);
	};
	template <class TT, class Containerr>
	bool						operator>=(const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs) {
		return (lhs._cntr >= rhs._cntr);
	};
}