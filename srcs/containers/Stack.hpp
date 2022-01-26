#pragma once

#include "Vector.hpp"

namespace ft{
	template <class T, class Container = ft::vector<T> >
	class stack{
	public:
		typedef	T				value_type;
		typedef Container		container_type;
		typedef size_t 			size_type;

		explicit				stack(const container_type& ctnr = container_type()) : c(ctnr){};
		~stack() {};

		bool					empty() const { return (c.empty()); };
		size_type				size() const { return (c.size()); };
		value_type&				top() { return (c.back()); };
		const value_type& 		top() const { return (c.back()); };
		void					push (const value_type& val) { c.push_back(val); };
		void					pop() { c.pop_back(); };

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

	protected:
		container_type			c;
	};

	template <class TT, class Containerr>
	bool						operator==(const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs) {
		return (lhs.c == rhs.c);
	};
	template <class TT, class Containerr>
	bool						operator!=(const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs) {
		return (lhs.c != rhs.c);
	};
	template <class TT, class Containerr>
	bool						operator<(const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs) {
		return (lhs.c < rhs.c);
	};
	template <class TT, class Containerr>
	bool						operator<=(const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs) {
		return (lhs.c <= rhs.c);
	};
	template <class TT, class Containerr>
	bool						operator>(const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs) {
		return (lhs.c > rhs.c);
	};
	template <class TT, class Containerr>
	bool						operator>=(const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs) {
		return (lhs.c >= rhs.c);
	};
}