#include "srcs/containers/Vector.hpp"
#include "srcs/utils/Colors.hpp"
<<<<<<< HEAD
#include "srcs/utils/RBTree.hpp"
#include "srcs/utils/Utils.hpp"
#include "srcs/utils/Print.hpp"
#include "srcs/containers/Stack.hpp"
#include "srcs/utils/RandIterator.hpp"
#include "srcs/containers/Map.hpp"
#include "srcs/containers/Set.hpp"
#include <map>


const ft::map<char, int>& 	func(const ft::map<char, int>& ins) { return ins;}

int main() {
	{

		std::vector<int> myvec;
		for (int i = 0; i < 10; i++)
			myvec.push_back(i);
		print_info(myvec);
		std::vector<int>::iterator it = myvec.begin();
		std::vector<int>::const_iterator c_it = myvec.end();
		while (it < c_it){
			std::cout << *it << " " << std::endl;
			it++;
		}


	}
//
	std::cout << YELLOW << ":::::::::RELATIONAL_OPERATORS::::::::\n" << RES;
	{
		ft::vector<int> myvec;
		for (int i = 0; i < 10; i++)
			myvec.push_back(i);
		print_info(myvec);
		ft::vector<int>::const_iterator c_it = myvec.begin();
		ft::vector<int>::iterator it = myvec.end();
		ft::vector<int> myvec1(myvec);
		print_info(myvec1);
		*it = 123;
		while (c_it < it){
			std::cout << *c_it << " " << std::endl;
			c_it++;
		}
//		ft::map<int, char> mymap;
//		for (int i =0; i < 10; i++){
//			mymap.insert(ft::make_pair(i, 'a'));
//		}
//		print_info(mymap);
//		ft::map<int, char>::iterator it = mymap.begin();
//		ft::map<int, char>::const_iterator end = mymap.end();
//		while (it != end) {
//			std::cout << it->first << " ";
//			it++;
//		}
	}
=======
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
	if (p == nullptr) {
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
	Node* 	insert(int val, Node* root) {
		if (empty())
			return (new Node(val, BLACK_N));
		if (root == NULL)
			return (new Node(val, RED_N));
		else {
			if (val < root->value) {
				root->left = insert(val, root->left);
				root->left->parent = root;
				root->balance_factor += 1;
				if (root->color == BLACK_N)
					return root;
				if (root->color == RED_N) {
					if (root->parent->left->color == RED_N){
						recolor(root);
						recolor(root->parent->left);
					} else if (root->parent->left->color == BLACK_N || root->parent->left == NULL) {

					}
				}
			} else {
				root->right = insert(val, root->right);
				root->right->parent = root;
				root->balance_factor -= 1;
				if (root->color == BLACK_N)
					return root;
				if (root->color == RED_N) {
					if (root->parent->right && root->parent->right->color == RED_N){
						recolor(root);
						recolor(root->parent->right);
					} else if (root->parent->left->color == BLACK_N || root->parent->left == NULL) {
						std::cout << "Jopa";
					}
					}
				}
			}
		return root;
	};

	int height(Node* root) {
		if (root == NULL) {
			return 0;
		}
		return 1 + std::max(height(root->left), height(root->right));
	}

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
//	tree.insert(10);
//	tree.insert(7);
//	tree.insert(18);
//	tree.insert(15);
//	tree.insert(16);
	tree.insert(33);
	tree.insert(53);
	tree.insert(9);
	tree.insert(8);
	tree.insert(21);
	tree.insert(11);

	tree.insert(61);
	tree.insert(45);
	tree.insert(35);

	tree.print();
>>>>>>> 9f4e9a7... stack n vector done, welcome 2 red-black hell))))
	return 0;
}