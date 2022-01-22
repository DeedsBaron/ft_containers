#pragma once

#include "Colors.hpp"
#include <iostream>
#include "Utils.hpp"
#include "Node.hpp"
#include "TreeIter.hpp"
#include "ReverseIterator.hpp"

#define RED_N 0
#define BLACK_N 1



template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class RBTree {
public:
	typedef T																		mapped_type;
	typedef Key																		key_type;
	typedef ft::pair<const Key, T>													value_type;
	typedef Alloc																	allocator_type;
	typedef typename allocator_type::template rebind<Node<value_type> >::other		node_alloc;
	typedef typename node_alloc::pointer											node_pointer;
	typedef	Compare																	compare_obj;
	typedef TreeIter<value_type>													iterator;
	typedef TreeIter<const value_type>												const_iterator;
	typedef	 ReverseIterator<iterator>												reverse_iterator;
	typedef	 ReverseIterator<const_iterator>										const_reverse_iterator;
	typedef size_t 																	size_type;

private:
	size_type							_size;
	node_pointer						_end;
	node_pointer						_root;
	node_alloc							_node_alloc;
	compare_obj							_compare;

public:
	//constructors & destructors & operator=
	RBTree(const compare_obj& compare = compare_obj(), const node_alloc& n_alloc = node_alloc()) :
			_size(0), _end(create_nil_node()), _root(_end), _node_alloc(n_alloc), _compare(compare) {}
	RBTree(const RBTree& x) { *this = x; }
	node_pointer	cloneNode(node_pointer Node2Clone) {
		node_pointer ClonedNode = NULL;
		if (Node2Clone){
			ClonedNode = _node_alloc.allocate(1);
			_node_alloc.construct(ClonedNode, Node<value_type>(*Node2Clone));
		}
		return ClonedNode;
	}
	node_pointer 	copyInOrder(node_pointer Tree2Copy){
		if (Tree2Copy == NULL || (Tree2Copy->_left == NULL && Tree2Copy->_right == NULL && Tree2Copy->_value == NULL))
			return NULL;
		node_pointer new_node = cloneNode(Tree2Copy);
		new_node->_left = copyInOrder(Tree2Copy->_left);
		if (new_node->_left)
			new_node->_left->_parent = new_node;
		new_node->_right = copyInOrder(Tree2Copy->_right);
		if (new_node->_right)
			new_node->_right->_parent = new_node;
		return new_node;
	}
	RBTree&			operator=(const RBTree& ins) {
		if (this == &ins)
			return *this;
		_node_alloc = ins._node_alloc;
		_compare = ins._compare;
		_size = ins._size;
		if (ins.isEmpty())
			_root = _end;
		else
			_root = copyInOrder(ins._root);
		setEnd();
		return *this;
	}
	~RBTree() {
		deallocateNode(_root);
	}

	void 							clear() { deallocateNode(_root); }
	//iterators
	iterator 						begin() {
		return (isEmpty() ? iterator(_end) : iterator(find_min()));
	}
	const_iterator					begin() const {
		return (isEmpty() ? const_iterator(_end) : const_iterator(find_min()));
	}
	iterator 						end() {
		return (isEmpty() ? iterator(_end) : iterator(_end));
	}
	const_iterator 					end() const {
		return (isEmpty() ? const_iterator(_end) : const_iterator(_end));
	}
	reverse_iterator				rbegin(){
		return (reverse_iterator(end()));
	}
	const_reverse_iterator			rbegin() const{
		return (const_reverse_iterator(end()));
	}
	reverse_iterator 				rend(){
		return (reverse_iterator(begin()));
	}
	const_reverse_iterator 			rend() const{
		return (const_reverse_iterator(begin()));
	}

	iterator						find(const key_type& k) {
		node_pointer buf = search(k);
		return buf != NULL ? iterator(buf) : end();
	}
	const_iterator					find(const key_type& k) const {
		node_pointer buf = search(k);
		return buf != NULL ? const_iterator(buf) : end();
	}
	size_type						max_size() const { return _node_alloc.max_size(); }
	size_type						get_size() const { return _size; }
	node_pointer					find_min(void) const {
		return findMinimum(_root);
	}
	node_pointer					find_max(void){
		return findMaximum(_root);
	}
	void							deallocateNodeValue(node_pointer node) {
		node->_alloc.destroy(node->_value);
		node->_alloc.deallocate(node->_value, 1);
	}

	void							deallocateNode(node_pointer node) {
		if (node == NULL)
			return ;
		deallocateNode(node->_left);
		deallocateNode(node->_right);
		_node_alloc.destroy(node);
		_node_alloc.deallocate(node, 1);
	}

	iterator						insert(iterator position, const value_type& val) {
		iterator		ret = insert_hint(position, val);
		setEnd();
		return (ret);
	}

	void 							setEnd(void) {
		node_pointer max = this->find_max();
		if (isEmpty()) {
			_end = max;
			return ;
		}
		max->_right = this->_end;
		this->_end->_parent = max;
	}

	ft::pair<iterator, bool> 		insert(const value_type& val) {
		ft::pair<iterator, bool> ret = insert(val, _root);
		setEnd();
		return (ret);
	}

	ft::pair<iterator, bool>		insert(const value_type& val, node_pointer root) {
		node_pointer	current = root;
		node_pointer	parent = NULL;
		node_pointer	new_node = _node_alloc.allocate(1);

		_node_alloc.construct(new_node, Node<value_type>(val, RED_N));
		while (current != NULL){
			if (!current->_left && !current->_right && !current->_value)
				break;
			parent = current;
			if (_compare(new_node->_value->first, current->_value->first))
				current = current->_left;
			else if (_compare(current->_value->first, new_node->_value->first))
				current = current->_right;
			else {
				deallocateNode(new_node);
				return (ft::make_pair(iterator(current), false));
			}
		}
		new_node->_parent = parent;
		if (parent == NULL)
			_root = new_node;
		else if (_compare(new_node->_value->first, parent->_value->first))
			parent->_left = new_node;
		else
			parent->_right = new_node;
		fix_insert(new_node);
		_size+=1;
		return ft::make_pair(iterator(new_node), true);
	}

	iterator 						insert_hint(iterator position, const value_type& val) {
		node_pointer	buf = search(val.first);
		if (buf)
			return (iterator(buf));
		node_pointer	current = position.getP();
		node_pointer	parent = NULL;
		if (current)
			parent = current->_parent;
		node_pointer	new_node = _node_alloc.allocate(1);
		_node_alloc.construct(new_node, Node<value_type>(val, RED_N));
		while (current != NULL){
			if (!current->_left && !current->_right && !current->_value)
				break;
			parent = current;
			if (_compare(new_node->_value->first, current->_value->first))
				current = current->_left;
			else if (_compare(current->_value->first, new_node->_value->first))
				current = current->_right;
			else {
				deallocateNode(new_node);
				return (iterator(current));
			}
		}
		new_node->_parent = parent;
		if (parent == NULL)
			_root = new_node;
		else if (_compare(new_node->_value->first, parent->_value->first))
			parent->_left = new_node;
		else
			parent->_right = new_node;
		fix_insert(new_node);
		_size += 1;
		return iterator(new_node);
	}

	template <class InputIterator>
	void							insert(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
		for (; first != last; first++)
			insert(*first);
	};

	void 							erase(iterator position) {
		deleteNode(position->first);
		_end = find_max()->_right;
	}

	size_type						erase(const Key& key) {
		size_type tmp_size = _size;
		deleteNode(key);
		_end = find_max()->_right;
		return (tmp_size == _size ? 0 : 1);
	}

	void							erase(iterator first, iterator last) {
		for ( ; first != last; first++) {
			deleteNode(first->first);
		}
		_end = find_max()->right;
	};

	void							deleteNode(const Key& k) {
		node_pointer	node = search(k, _root);
		node_pointer	movedUpNode = NULL;

		if (node == NULL)
			return ;
		bool	deletedNodeColor;
		if (node->_left == NULL || node->_right == NULL){
			movedUpNode = deleteNodeZeroOrOneC(node);
			deletedNodeColor = node->_color;
			deallocateNodeValue(node);
			_node_alloc.deallocate(node, 1);
		} else {
			node_pointer	inOrderSuccessor = findMinimum(node->_right);
			value_type* 	val = inOrderSuccessor->_value;

			movedUpNode = deleteNodeZeroOrOneC(inOrderSuccessor);
			deletedNodeColor = inOrderSuccessor->_color;
			deallocateNodeValue(node);
			node->_value = val;
			_node_alloc.deallocate(inOrderSuccessor, 1);
		}
		if (deletedNodeColor == BLACK_N) {
			fixRedBlackPropertiesAfterDelete(movedUpNode);
			// Remove the temporary NIL node
			if (!movedUpNode->_value) {
				replaceParentsChild(movedUpNode->_parent, movedUpNode, NULL);
				_node_alloc.deallocate(movedUpNode, 1);
			}
		}
		_end = find_max();
		_size -= 1;
	}

	void							leftRotate(node_pointer node)
	{
		node_pointer parent = node->_parent;
		node_pointer rightChild = node->_right;

		node->_right = rightChild->_left;
		if (rightChild->_left != NULL) {
			rightChild->_left->_parent = node;
		}
		rightChild->_left = node;
		node->_parent = rightChild;
		replaceParentsChild(parent, node, rightChild);
	}

	void							rightRotate(node_pointer node)
	{
		node_pointer parent = node->_parent;
		node_pointer leftChild = node->_left;

		node->_left = leftChild->_right;
		if (leftChild->_right != NULL) {
			leftChild->_right->_parent = node;
		}
		leftChild->_right = node;
		node->_parent = leftChild;
		replaceParentsChild(parent, node, leftChild);
	}

	void							replaceParentsChild(node_pointer parent, node_pointer oldChild, node_pointer newChild){
		if (parent == NULL) {
			_root = newChild;
		} else if (parent->_left == oldChild) {
			parent->_left = newChild;
		} else if (parent->_right == oldChild) {
			parent->_right = newChild;
		}
		if (newChild != NULL) {
			newChild->_parent = parent;
		}
	}

	node_pointer					getUncle(node_pointer parent){
		node_pointer	grand_parent = parent->_parent;
		if (grand_parent->_left == parent) {
			return grand_parent->_right;
		} else if (grand_parent->_right == parent) {
			return grand_parent->_left;
		}
		return NULL;
	}

	void							fix_insert(node_pointer node){
		node_pointer parent = node->_parent;
		// Case 1: Parent is null, we've reached the root, the end of the recursion
		if (parent == NULL) {
			// Uncomment the following line if you want to enforce black roots (rule 2):
			node->_color = BLACK_N;
			return;
		}
		// Parent is black --> nothing to do
		if (parent->_color == BLACK_N) {
			return;
		}
		// From here on, _parent is red
		node_pointer grand_parent = parent->_parent;
		node_pointer uncle = getUncle(parent);
		// Case 3: Uncle is red -> re_color _parent, grand_parent and uncle
		if (uncle != NULL && uncle->_color == RED_N) {
			parent->_color = BLACK_N;
			grand_parent->_color = RED_N;
			uncle->_color = BLACK_N;

			// Call recursively for grand_parent, which is now red.
			// It might be root or have a red _parent, in which case we need to fix more...
			fix_insert(grand_parent);
		}

			// Parent is __left child of grand_parent
		else if (parent == grand_parent->_left) {
			// Case 4a: Uncle is black and node is __left->_right "inner child" of its grand_parent
			if (node == parent->_right) {
				leftRotate(parent);
				// Let "_parent" point to the new root node of the rotated sub-tree.
				// It will be re_colored in the next step, which we're going to fall-through to.
				parent = node;
			}

			// Case 5a: Uncle is black and node is __left->__left "outer child" of its grand_parent
			rightRotate(grand_parent);

			// Re_color original _parent and grand_parent
			parent->_color = BLACK_N;
			grand_parent->_color = RED_N;
		}

			// Parent is _right child of grand_parent
		else {
			// Case 4b: Uncle is black and node is _right->__left "inner child" of its grand_parent
			if (node == parent->_left) {
				rightRotate(parent);

				// Let "_parent" point to the new root node of the rotated sub-tree.
				// It will be re_colored in the next step, which we're going to fall-through to.
				parent = node;
			}

			// Case 5b: Uncle is black and node is _right->_right "outer child" of its grand_parent
			leftRotate(grand_parent);

			// Re_color original _parent and grand_parent
			parent->_color = BLACK_N;
			grand_parent->_color = RED_N;
		}
	}

	node_pointer					create_nil_node(void) {
		node_pointer	new_node = _node_alloc.allocate(1);
		_node_alloc.construct(new_node, NilNode<value_type>());
		return (new_node);
	}

	node_pointer					findMaximum(node_pointer node) {
		if (!node)
			return NULL;
		while(node->_right != NULL && node->_right->_value != NULL)
			node = node->_right;
		return node;
	}

	node_pointer					findMinimum(node_pointer node) const {
		while (node->_left != NULL)
			node = node->_left;
		return node;
	}

	bool							isBlack(node_pointer node){
		return (node == NULL || node->_color == BLACK_N);
	}

	node_pointer					getSibling(node_pointer node) {
		node_pointer	parent = node->_parent;

		if (node == parent->_left) {
			return parent->_right;
		} else if (node == parent->_right) {
			return parent->_left;
		}
		return NULL;
	}

	void							handleRedSibling(node_pointer node, node_pointer sibling) {
		// Re_color...
		sibling->_color = BLACK_N;
		node->_parent->_color = RED_N;
		// ... and rotate
		if (node == node->_parent->_left) {
			leftRotate(node->_parent);
		} else {
			rightRotate(node->_parent);
		}
	}

	void							handleBlackSiblingWithAtLeastOneRedChild(node_pointer node, node_pointer sibling) {
		bool nodeIsLeftChild = (node == node->_parent->_left);

		// Case 5: Black sibling with at least one red child + "outer nephew" is black
		// --> Re_color sibling and its child, and rotate around sibling
		if (nodeIsLeftChild && isBlack(sibling->_right)) {
			sibling->_left->_color = BLACK_N;
			sibling->_color = RED_N;
			rightRotate(sibling);
			sibling = node->_parent->_right;
		} else if (!nodeIsLeftChild && isBlack(sibling->_left)) {
			sibling->_right->_color = BLACK_N;
			sibling->_color = RED_N;
			leftRotate(sibling);
			sibling = node->_parent->_left;
		}

		// Fall-through to case 6...

		// Case 6: Black sibling with at least one red child + "outer nephew" is red
		// --> Re_color sibling + _parent + sibling's child, and rotate around _parent
		sibling->_color = node->_parent->_color;
		node->_parent->_color = BLACK_N;
		if (nodeIsLeftChild) {
			sibling->_right->_color = BLACK_N;
			leftRotate(node->_parent);
		} else {
			sibling->_left->_color = BLACK_N;
			rightRotate(node->_parent);
		}
	}

	void							fixRedBlackPropertiesAfterDelete(node_pointer node) {
		if (node == _root) {
			node->_color = BLACK_N;
			return ;
		}
		node_pointer	sibling = getSibling(node);

		// Case 2: Red sibling
		if (sibling->_color == RED_N) {
			handleRedSibling(node, sibling);
			sibling = getSibling(node); // Get new sibling for fall-through to cases 3-6
		}

		// Cases 3+4: Black sibling with two black children
		if (isBlack(sibling->_left) && isBlack(sibling->_right)) {
			sibling->_color = RED_N;

			// Case 3: Black sibling with two black children + red _parent
			if (node->_parent->_color == RED_N) {
				node->_parent->_color = BLACK_N;
			}

				// Case 4: Black sibling with two black children + black _parent
			else
				fixRedBlackPropertiesAfterDelete(node->_parent);
		}
			// Case 5+6: Black sibling with at least one red child
		else
			handleBlackSiblingWithAtLeastOneRedChild(node, sibling);
	}

	node_pointer					deleteNodeZeroOrOneC(node_pointer node) {
		if (node->_left != NULL) {
			replaceParentsChild(node->_parent, node, node->_left);
			return node->_left;
		} else if (node->_right != NULL) {
			replaceParentsChild(node->_parent, node, node->_right);
			return node->_right;
		} else {
			node_pointer newChild = node->_color == BLACK_N ? create_nil_node() : NULL;
			replaceParentsChild(node->_parent, node, newChild);
			return newChild;
		}
		return NULL;
	}

	node_pointer					search(const Key& value) const {
		return search(value, _root);
	}

	node_pointer					search(const Key& value, node_pointer node) const {
		if(!node || !node->_value)
			return NULL;
		if (_compare(value, node->_value->first))
			return search(value, node->_left);
		if (_compare(node->_value->first, value))
			return search(value, node->_right);
		return node;
	}

	void							print(){
		printTree(_root, NULL, false);
	};

	bool 							isEmpty() const {
		return (_root == NULL || (!_root->_left && !_root->_right && !_root->_value));
	}

	void 							printTree(node_pointer root, Trunk *prev, bool isLeft)
	{
		if (isEmpty()) {
			std::cout << GREEN << "Map is empty\n" << RES;
			std::cout << " nil_node\n";
			return;
		}
		if (root == NULL ) {
			return;
		}
		std::string prev_str = "    ";
		Trunk *trunk = new Trunk(prev, prev_str);
		printTree(root->_right, trunk, true);
		if (!prev) {
			trunk->str = "———";
		}
		else if (isLeft){
			trunk->str = ".———";
			prev_str = "   |";
		} else {
			trunk->str = "`———";
			prev->str = prev_str;
		}
		showTrunks(trunk);
		if (root->_color == RED_N) {
			std::cout << " " << RED << root->_value->first << RES << ", " << root->_value->second << std::endl;
		}
		else {
			if (root->_value)
				std::cout << " " << root->_value->first << ", " << root->_value->second << std::endl;
			else
				std::cout << " nil_node\n";
		}
		if (prev) {
			prev->str = prev_str;
		}
		trunk->str = "   |";
		printTree(root->_left, trunk, false);
		delete trunk;
	}

	void 							swap(RBTree& x) {
		std::swap(_size, x._size);
		std::swap(_end, x._end);
		std::swap(_root, x._root);
	}
};