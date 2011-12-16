#pragma once
#include <iostream>
using namespace std;
namespace CS262 {
template <typename Item>
struct TreeNode {
        TreeNode(const Item& data = Item()) :
            data(data), left(NULL), right(NULL) { }

        Item data;
        TreeNode* left;   // left child
        TreeNode* right;  // right child
};
	
template <typename Item, typename Key = Item>
class BinarySearchTree{
	public:
		TreeNode<Item>* root;
		~BinarySearchTree(void);
		BinarySearchTree(const BinarySearchTree&);
		BinarySearchTree& operator =(const BinarySearchTree&);

		// creates an empty tree
		BinarySearchTree(): root(NULL), treesize(0){};

		// returns the number of nodes in the tree
		std::size_t size() const {return treesize;}

		// returns the height of the tree
		std::size_t height() const;

		// returns the minimum value in the tree
		const Item& min() const;

		// returns the maximum value in the tree
		const Item& max() const;

		// inserts a copy of the given value into the tree, unless one already exists
		void insert(const Item& value);

		// removes an entry with the given key, if present in the tree
		bool remove(const Key& key);

		// returns a pointer to an entry with the given key (if it exists), or NULL
		Item* search(const Key& key) const;

		// if an entry with the key exists, applies the function
		template <typename Function>
		bool apply(const Key& key, Function f);

		// applies a function to each value in the tree, via preorder traversal
		template <typename Function>
		void preorder(Function f);

		// applies a function to each value in the tree, via inorder traversal
		template <typename Function>
		void inorder(Function f);

		// applies a function to each value in the tree, via postorder traversal
		template <typename Function>
		void postorder(Function f);

		//With treenode implementation
		void deletenode(TreeNode<Item>*&);
		void copynode(TreeNode<Item>*& t, const TreeNode<Item>* b);

		// returns the number of nodes in the tree
		std::size_t size(const TreeNode<Item>*&) const {return treesize;}

		// returns the height of the tree
		std::size_t height(const TreeNode<Item>*) const {return treeheight;}

		// returns the minimum value in the tree
		const Item& min(const TreeNode<Item>*) const;

		// returns the maximum value in the tree
		const Item& max(const TreeNode<Item>*) const;

		// inserts a copy of the given value into the tree, unless one already exists
		void insert(const Item& value, TreeNode<Item>*&);

		// removes an entry with the given key, if present in the tree
		bool remove(const Key& key, TreeNode<Item>*&);

		// returns a pointer to an entry with the given key (if it exists), or NULL
		Item* search(const Key& key, TreeNode<Item>*&) const;

		// applies a function to each value in the tree, via preorder traversal
		template <typename Function>
		void preorder(Function f, TreeNode<Item>*&);

		// applies a function to each value in the tree, via inorder traversal
		template <typename Function>
		void inorder(Function f, TreeNode<Item>*&);

		// applies a function to each value in the tree, via postorder traversal
		template <typename Function>
		void postorder(Function f, TreeNode<Item>*&);

		void deletemaxnode(TreeNode<Item>*&, Item&);

		// returns the height of the tree
		std::size_t height(const TreeNode<Item>*, std::size_t) const;

	private:
		std::size_t treesize;

};

}
#include "BinarySearchTree.cpp"