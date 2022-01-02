#pragma once
#include "Colors.hpp"
#include <iostream>
#include "Utils.hpp"

#define RED_N 0
#define BLACK_N 1

struct Trunk
{
	Trunk *prev;
	std::string str;

	Trunk(Trunk *prev, std::string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

void showTrunks(Trunk *p)
{
	if (p == NULL) {
		return;
	}

	showTrunks(p->prev);
	std::cout << p->str;
}

template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class RBTree {
private:

	template <class N_Key, class N_T>
	struct Node {
		typedef	ft::pair<const N_Key, N_T>				value_type;
		typedef std::allocator<value_type>				allocator_type;
		typedef	typename allocator_type::pointer		pointer;

		allocator_type				_alloc;
		pointer						_value;
		int 						_color;
		Node<const N_Key, N_T>*		_left;
		Node<const N_Key, N_T>*		_right;
		Node<const N_Key, N_T>*		_parent;

		Node(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _value(NULL), _color(BLACK_N), _left(NULL), _right(NULL), _parent(NULL) {};
		Node(const value_type& value, int _color, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _color(_color), _left(NULL), _right(NULL), _parent(NULL) { _value = _alloc.allocate(1); _alloc.construct(_value, value); };
		virtual ~Node() {}
	};

	template <class Nn_Key, class Nn_T>
	struct NilNode : public Node<const Nn_Key, Nn_T> {
		NilNode() : Node<const Nn_Key, Nn_T>() {}
		~NilNode() {}
	};

	typedef ft::pair<const Key, T>													value_type;
	typedef Alloc																	allocator_type;
	typedef typename allocator_type::template rebind<Node<const Key, T> >::other	node_alloc;
	typedef typename node_alloc::pointer											node_pointer;
	typedef	Compare																	compare_obj;

	node_pointer						_root;
	node_alloc							_node_alloc;
	compare_obj							_compare;

public:
	RBTree(const compare_obj& compare = compare_obj(), const node_alloc& n_alloc = node_alloc()) : _root(NULL), _node_alloc(n_alloc), _compare(compare) {}
	~RBTree() {
		deallocateNode(_root);
	}

	void				deallocateNodeValue(node_pointer node) {
		node->_alloc.destroy(node->_value);
		node->_alloc.deallocate(node->_value, 1);
	}

	void				deallocateNode(node_pointer node) {
		if (node == NULL)
			return ;
		deallocateNode(node->_left);
		deallocateNode(node->_right);
		deallocateNodeValue(node);
		_node_alloc.destroy(node);
		_node_alloc.deallocate(node, 1);
	}

	void 				insert(const value_type& val){
		insert(val, _root);
	}

	void				leftRotate(node_pointer node)
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

	void				rightRotate(node_pointer node)
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

	void				replaceParentsChild(node_pointer parent, node_pointer oldChild, node_pointer newChild){
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

	node_pointer		getUncle(node_pointer parent){
		node_pointer	grand_parent = parent->_parent;
		if (grand_parent->_left == parent) {
			return grand_parent->_right;
		} else if (grand_parent->_right == parent) {
			return grand_parent->_left;
		}
		return NULL;
	}

	void				fix_insert(node_pointer node){
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

	node_pointer		create_nil_node(void) {
		node_pointer	new_node = _node_alloc.allocate(1);
		_node_alloc.construct(new_node, NilNode<const Key, T>());
		return (new_node);
	}

	void				insert(const value_type& val, node_pointer root) {
		node_pointer	current = root;
		node_pointer	parent = NULL;
		node_pointer	new_node = _node_alloc.allocate(1);

		_node_alloc.construct(new_node, Node<const Key, T>(val, RED_N));
		while (current != NULL){
			if (!current->_left && !current->_right && !current->_value)
				break;
			parent = current;
			if (_compare(new_node->_value->first, current->_value->first))
				current = current->_left;
			else if (_compare(current->_value->first, new_node->_value->first))
				current = current->_right;
		}
		new_node->_parent = parent;
		if (parent == NULL)
			_root = new_node;
		else if (_compare(new_node->_value->first, parent->_value->first))
			parent->_left = new_node;
		else
			parent->_right = new_node;
		fix_insert(new_node);
	}

	node_pointer		findMinimum(node_pointer node){
		while (node->_left != NULL)
			node = node->_left;
		return node;
	}

	bool				isBlack(node_pointer node){
		return (node == NULL || node->_color == BLACK_N);
	}

	node_pointer		getSibling(node_pointer node) {
		node_pointer	parent = node->_parent;

		if (node == parent->_left) {
			return parent->_right;
		} else if (node == parent->_right) {
			return parent->_left;
		}
		return NULL;
	}

	void				handleRedSibling(node_pointer node, node_pointer sibling) {
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

	void				handleBlackSiblingWithAtLeastOneRedChild(node_pointer node, node_pointer sibling) {
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

	void				fixRedBlackPropertiesAfterDelete(node_pointer node) {
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

	node_pointer		deleteNodeZeroOrOneC(node_pointer node) {
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

	node_pointer		search(const value_type& value) {
		return search(value, _root);
	}

	node_pointer		search(const Key& value, node_pointer node) const {
		if(!node)
			return NULL;
		if (_compare(value, node->_value->first))
			return search(value, node->_left);
		if (_compare(node->_value->first, value))
			return search(value, node->_right);
		return node;
	}

	void				deleteNode(const Key& k) {
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
	}

	void				print(){
		printTree(_root, NULL, false);
	};

	void 				printTree(node_pointer root, Trunk *prev, bool isLeft)
	{
		if (_root == NULL || (!_root->_left && !_root->_right && !_root->_value)) {
			std::cout << GREEN << "Tree is empty\n" << RES;
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
			std::cout << " " << root->_value->first << ", " << root->_value->second << std::endl;
		}
		if (prev) {
			prev->str = prev_str;
		}
		trunk->str = "   |";
		printTree(root->_left, trunk, false);
		delete trunk;
	}
};