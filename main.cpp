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


template <typename T>
class Bst{
private:
	struct Node {
		T 		value;
		int 	color;
		Node 	*left;
		Node	*right;
		Node	*parent;
		int		balance_factor;

		Node() : left(NULL), right(NULL) {};
		Node(const T& value, int color) : value(value), color(color), left(NULL), right(NULL), parent(NULL), balance_factor(0) {};
		Node(const T& value, int color, int root) : value(value), color(color), left(NULL), right(NULL), parent(NULL), balance_factor(root) {};
		~Node() { delete left; delete right; }
	};

	Node*		_root;

public:
	Bst() : _root(NULL) {}
	~Bst() { delete _root; }

	bool 	empty() const { return (_root == NULL); }
	void 	insert(int val){
		_root = insert(val, _root);
	}

	void 	recolor(Node* node){
		if (node->color == BLACK_N)
			node->color = RED_N;
		else
			node->color = BLACK_N;
	}

	int		height(Node* node) {
	int		h = 0;
	if (node != NULL) {
		int l_height = height(node->left);
		int r_height = height(node->right);
		int max_height = std::max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
	}

	int		b_factor(Node* node) {
		int l_height = height(node->left);
		int r_height = height(node->right);
		int b_factor = l_height - r_height;
		return b_factor;
	}

	Node*	rr_rotat(Node* parent) {
		Node* t;
		t = parent->right;
		parent->right = t->left;
		t->left = parent;
		return t;
	}

	Node* 	ll_rotat(Node* parent) {
		Node* t;
		t = parent->left;
		parent->left = t->right;
		t->right = parent;
   		return t;
	}

	Node*	lr_rotat(Node* parent) {
		Node* t;
		t = parent->left;
		parent->left = rr_rotat(t);
		return ll_rotat(parent);
	}

	Node* 	rl_rotat(Node* parent) {
		Node* t;
		t = parent->right;
		parent->right = ll_rotat(t);
		return rr_rotat(parent);
	}

	Node* 	insert(int val, Node* root) {
		if (empty())
			return (new Node(val, BLACK_N));
		if (root == NULL)
			return (new Node(val, RED_N));
		else {
			if (val < root->value) {
				root->left = insert(val, root->left);
				root->left->parent = root;
				root->balance_factor = b_factor(root);
				if ((root->balance_factor == 0 || root->balance_factor == 1 || root->balance_factor == -1) && root->color == BLACK_N)
					return root;
				if (root->color == RED_N) {
					if (root->parent->left->color == RED_N){
						recolor(root);
						recolor(root->parent->left);
					} else if (root->parent->left == NULL || root->parent->left->color == BLACK_N) {
						if (root->balance_factor > 1) {
							if (b_factor(root->left) > 0)
								root = ll_rotat(root);
							else
								root = lr_rotat(root);
						} else if (root->balance_factor < -1){
							if (b_factor(root->right) > 0)
								root = rl_rotat(root);
							else
								root = rr_rotat(root);
						}
						return root;
					}
				}
			} else {
				root->right = insert(val, root->right);
				root->right->parent = root;
				root->balance_factor = b_factor(root);
				if (root->color == BLACK_N)
					return root;
				if (root->color == RED_N) {
					if (root->parent->right && root->parent->right->color == RED_N){
						recolor(root);
						recolor(root->parent->right);
					} else if (root->parent->right == NULL || root->parent->right->color == BLACK_N) {
						if (root->balance_factor > 1) {
							if (b_factor(root->left) > 0)
								root = ll_rotat(root);
							else
								root = lr_rotat(root);
						} else if (root->balance_factor < -1){
							if (b_factor(root->right) > 0)
								root = rl_rotat(root);
							else
								root = rr_rotat(root);
						}
						return root;
					}
				}
			}
		}
		return root;
	};

	void			updateBalance(Node* node) {
		if (node->parent != NULL){
			if (node->parent->right == node)
				node->parent->balance_factor -= 1;
			else if (node->parent->left == node)
				node->parent->balance_factor +=1;
			if (node->parent->balance_factor != 0)
				updateBalance(node->parent);
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
			std::cout << " " << RED << root->value << RES << "(" << root->balance_factor << ")" << std::endl;
		else
			std::cout << " " << root->value << "(" << root->balance_factor << ")" << std::endl;
		if (prev) {
			prev->str = prev_str;
		}
		trunk->str = "   |";
		printTree(root->left, trunk, false);
	}

};

int main() {
	Bst<int> tree;
	tree.insert(10);
	tree.insert(7);
	tree.insert(18);
	tree.insert(15);
	tree.insert(16);
	// tree.insert(33);
	// tree.insert(53);
	// tree.insert(9);
	// tree.insert(8);
	// tree.insert(21);
	// tree.insert(11);

	// tree.insert(61);

	tree.print();
	return 0;
}