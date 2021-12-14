#pragma once

#include "Vector.hpp"

namespace ft{
	template <class T, class Container = ft::vector<T> >
	class stack{
	public:
		typedef	T				value_type;
		typedef Container		container_type;
		typedef size_t 			size_type;

<<<<<<< HEAD
		explicit				stack(const container_type& ctnr = container_type()) : c(ctnr){};
		~stack() {};

		bool					empty() const { return (c.empty()); };
		size_type				size() const { return (c.size()); };
		value_type&				top() { return (c.back()); };
		const value_type& 		top() const { return (c.back()); };
		void					push (const value_type& val) { c.push_back(val); };
		void					pop() { c.pop_back(); };
=======
		explicit				stack(const container_type& ctnr = container_type()) : _cntr(ctnr){};
		~stack() {};

		bool					empty() const { return (_cntr.empty()); };
		size_type				size() const { return (_cntr.size()); };
		value_type&				top() { return (_cntr.back()); };
		const value_type& 		top() const { return (_cntr.back()); };
		void					push (const value_type& val) { _cntr.push_back(val); };
		void					pop() { _cntr.pop_back(); };
>>>>>>> 9f4e9a7... stack n vector done, welcome 2 red-black hell))))

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

<<<<<<< HEAD
	protected:
		container_type			c;
=======
	private:
		container_type			_cntr;
>>>>>>> 9f4e9a7... stack n vector done, welcome 2 red-black hell))))
	};

	template <class TT, class Containerr>
	bool						operator==(const stack<TT, Containerr>& lhs, const stack<TT, Containerr>& rhs) {
<<<<<<< HEAD
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
=======
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
>>>>>>> 9f4e9a7... stack n vector done, welcome 2 red-black hell))))
	};
}