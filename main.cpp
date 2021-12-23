#include "srcs/containers/Vector.hpp"
#include "srcs/utils/Colors.hpp"
#include "srcs/utils/Utils.hpp"
#include "srcs/utils/Print.hpp"
#include <vector>
#include <iostream>
#include "srcs/containers/Stack.hpp"
#include "srcs/utils/RandIterator.hpp"
#include "srcs/utils/BidirectionalIter.hpp"

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



template <class T, class Alloc = std::allocator<T> >
class Bst{
private:

	typedef T			value_type;
	typedef Alloc		allocator_type;
	
	struct Node {
		value_type 		value;
		int 			color;
		Node 			*left;
		Node			*right;
		Node			*parent;

		Node() : left(NULL), right(NULL) {};
		Node(const T& value, int color) : value(value), color(color), left(NULL), right(NULL), parent(NULL) {};
		virtual ~Node() { delete left; delete right; }
	};

	struct NilNode : public Node {
		NilNode() : Node(1337, BLACK_N) {}
		~NilNode() {} 
	};

	Node*				_root;
	allocator_type		_alloc;


public:
	Bst() : _root(NULL){}
	~Bst() { delete _root; }

	void 		insert(int val){
		insert(val, _root);
	}

	void		leftRotate(Node* node)
	{
		Node* parent = node->parent;
		Node* rightChild = node->right;

		node->right = rightChild->left;
		if (rightChild->left != NULL) {
			rightChild->left->parent = node;
		}
		rightChild->left = node;
		node->parent = rightChild;
		replaceParentsChild(parent, node, rightChild);
	}

	void		rightRotate(Node* node)
	{
		Node* parent = node->parent;
		Node* leftChild = node->left;

		node->left = leftChild->right;
		if (leftChild->right != NULL) {
			leftChild->right->parent = node;
		}
		leftChild->right = node;
		node->parent = leftChild;
		replaceParentsChild(parent, node, leftChild);
	}

	void		replaceParentsChild(Node* parent, Node* oldChild, Node* newChild){
		if (parent == NULL) {
			_root = newChild;
		} else if (parent->left == oldChild) {
			parent->left = newChild;
		} else if (parent->right == oldChild) {
			parent->right = newChild;
		} 
		if (newChild != NULL) {
			newChild->parent = parent;
		}
	}

	Node*		getUncle(Node* parent){
		Node*	grandparent = parent->parent;
		if (grandparent->left == parent) {
			return grandparent->right;
		} else if (grandparent->right == parent) {
			return grandparent->left;
		}
		return NULL;
	}

	void		fix_insert(Node* node){
		Node* parent = node->parent;
		// Case 1: Parent is null, we've reached the root, the end of the recursion
		if (parent == NULL) {
		// Uncomment the following line if you want to enforce black roots (rule 2):
			node->color = BLACK_N;
			return;
		}
		// Parent is black --> nothing to do
		if (parent->color == BLACK_N) {
			return;
		}
		// From here on, parent is red
		Node* grandparent = parent->parent;
		Node* uncle = getUncle(parent);
		// Case 3: Uncle is red -> recolor parent, grandparent and uncle
		if (uncle != NULL && uncle->color == RED_N) {
			parent->color = BLACK_N;
			grandparent->color = RED_N;
			uncle->color = BLACK_N;

		// Call recursively for grandparent, which is now red.
		// It might be root or have a red parent, in which case we need to fix more...
		fix_insert(grandparent);
		}

		// Parent is left child of grandparent
		else if (parent == grandparent->left) {
		// Case 4a: Uncle is black and node is left->right "inner child" of its grandparent
		if (node == parent->right) {
			leftRotate(parent);
			// Let "parent" point to the new root node of the rotated sub-tree.
			// It will be recolored in the next step, which we're going to fall-through to.
			parent = node;
		}

			// Case 5a: Uncle is black and node is left->left "outer child" of its grandparent
			rightRotate(grandparent);

			// Recolor original parent and grandparent
			parent->color = BLACK_N;
			grandparent->color = RED_N;
		}

		// Parent is right child of grandparent
		else {
			// Case 4b: Uncle is black and node is right->left "inner child" of its grandparent
			if (node == parent->left) {
				rightRotate(parent);

			// Let "parent" point to the new root node of the rotated sub-tree.
			// It will be recolored in the next step, which we're going to fall-through to.
			parent = node;
			}

			// Case 5b: Uncle is black and node is right->right "outer child" of its grandparent
		leftRotate(grandparent);

		// Recolor original parent and grandparent
		parent->color = BLACK_N;
		grandparent->color = RED_N;
		}
	}

	void		insert(int val, Node* root) {
		Node*	new_node = new Node(val, RED_N);
		Node*	current = root;
		Node*	parent = NULL;

		while (current != NULL){
			parent = current;
			if (new_node->value < current->value)
				current = current->left;
			else if (new_node->value >= current->value)
				current = current->right;
		}
		new_node->parent = parent;
		if (parent == NULL)
			_root = new_node;
		else if (new_node->value < parent->value)
			parent->left = new_node;
		else
			parent->right = new_node;
		fix_insert(new_node);
	}

	Node*		findMinimum(Node* node){
		while (node->left != NULL)
			node = node->left;
		return node;
	}

	bool		isBlack(Node* node){
		return (node == NULL || node->color == BLACK_N);
	}

	Node*		getSibling(Node* node) {
		Node*	parent = node->parent;

		if (node == parent->left) {
			return parent->right;
		} else if (node == parent->right) {
			return parent->left;
		}
		return NULL;
	}

	void		handleRedSibling(Node* node, Node* sibling) {
		// Recolor...
		sibling->color = BLACK_N;
		node->parent->color = RED_N;
		// ... and rotate
		if (node == node->parent->left) {
			leftRotate(node->parent);
		} else {
			rightRotate(node->parent);
		}
	}

	void	handleBlackSiblingWithAtLeastOneRedChild(Node* node, Node* sibling) {
		bool nodeIsLeftChild = (node == node->parent->left);

		// Case 5: Black sibling with at least one red child + "outer nephew" is black
		// --> Recolor sibling and its child, and rotate around sibling
		if (nodeIsLeftChild && isBlack(sibling->right)) {
			sibling->left->color = BLACK_N;
			sibling->color = RED_N;
			rightRotate(sibling);
			sibling = node->parent->right;
		} else if (!nodeIsLeftChild && isBlack(sibling->left)) {
			sibling->right->color = BLACK_N;
			sibling->color = RED_N;
			leftRotate(sibling);
			sibling = node->parent->left;
		}

		// Fall-through to case 6...

		// Case 6: Black sibling with at least one red child + "outer nephew" is red
		// --> Recolor sibling + parent + sibling's child, and rotate around parent
		sibling->color = node->parent->color;
		node->parent->color = BLACK_N;
		if (nodeIsLeftChild) {
			sibling->right->color = BLACK_N;
			leftRotate(node->parent);
		} else {
			sibling->left->color = BLACK_N;
			rightRotate(node->parent);
		}
	}

	void		 fixRedBlackPropertiesAfterDelete(Node* node) {
		if (node == _root) {
			node->color = BLACK_N;
			return ;
		}
		Node*	sibling = getSibling(node);

		// Case 2: Red sibling
		if (sibling->color == RED_N) {
			handleRedSibling(node, sibling);
			sibling = getSibling(node); // Get new sibling for fall-through to cases 3-6
		}

		// Cases 3+4: Black sibling with two black children
		if (isBlack(sibling->left) && isBlack(sibling->right)) {
			sibling->color = RED_N;

			// Case 3: Black sibling with two black children + red parent
			if (node->parent->color == RED_N) {
				node->parent->color = BLACK_N;
			}

			// Case 4: Black sibling with two black children + black parent
			else 
				fixRedBlackPropertiesAfterDelete(node->parent);
		}
		// Case 5+6: Black sibling with at least one red child
		else
			handleBlackSiblingWithAtLeastOneRedChild(node, sibling);
	}

	Node*		deleteNodeZeroOrOneC(Node* node) {
		if (node->left != NULL) {
			replaceParentsChild(node->parent, node, node->left);
			return node->left;
		} else if (node->right != NULL) {
			replaceParentsChild(node->parent, node, node->right);
			return node->right;
		} else {
			Node* newChild = node->color == BLACK_N ? new NilNode() : NULL;
			replaceParentsChild(node->parent, node, newChild);
			return newChild;
		}
		return NULL;
	}

	void		deleteNode(int val) {
		Node*	node = _root;
		while (node != NULL && node->value != val){
			if (val < node->value)
				node = node->left;
			else
				node = node->right;
		}
		if (node == NULL)
			return ;
		Node*	movedUpNode = NULL;
		bool	deletedNodeColor;
		if (node->left == NULL || node->right == NULL){
			movedUpNode = deleteNodeZeroOrOneC(node);
			deletedNodeColor = node->color;
			delete node;
		} else {
			Node*	inOrderSuccessor = findMinimum(node->right);
			int val = inOrderSuccessor->value;
			movedUpNode = deleteNodeZeroOrOneC(inOrderSuccessor);
			deletedNodeColor = inOrderSuccessor->color;
			delete inOrderSuccessor;
			node->value = val;
		}
		if (deletedNodeColor == BLACK_N) {
			fixRedBlackPropertiesAfterDelete(movedUpNode);
			// Remove the temporary NIL node
			if (dynamic_cast<NilNode*>(movedUpNode)) {
				replaceParentsChild(movedUpNode->parent, movedUpNode, NULL);
				delete movedUpNode;
			}
		}
	}

	void	print(){
		printTree(_root, NULL, false);
	};
	void 	printTree(Node* root, Trunk *prev, bool isLeft)
	{
		if (root == NULL) {
			return;
		}
		std::string prev_str = "    ";
		Trunk *trunk = new Trunk(prev, prev_str);
		printTree(root->right, trunk, true);
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
		if (root->color == RED_N)
			std::cout << " " << RED << root->value << RES << std::endl;
		else
			std::cout << " " << root->value << std::endl;
		if (prev) {
			prev->str = prev_str;
		}
		trunk->str = "   |";
		printTree(root->left, trunk, false);
		delete trunk;
	}
};

int main() {
	Bst<int> tree;
	tree.insert(10);
	tree.insert(18);
	tree.insert(7);
	tree.insert(15);
	tree.insert(16);
	tree.insert(30);
	tree.insert(25);
	tree.insert(40);
	tree.insert(60);
	tree.insert(21);
	tree.insert(70);
	// tree.insert(61);
	std::cout << "JOPA\n";
	tree.print();
	return 0;
}