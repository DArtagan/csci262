#pragma once
#include <cstdlib>
namespace CS262{

template <typename Item, typename Key = Item>
class BST
{
	struct Node {
		Node(const Item& Data = Item()):data(Data),left(NULL),right(NULL){}
		Item data;
		Node* left;
		Node* right;
	};
public:
	BST(BST& Original);
	BST();
	std::size_t size() const { return Size; }
	std::size_t height() const;
	const Item& min() const;
	const Item& max() const;
	void insert(const Item& value);
	bool remove(const Key& key);
	Item* search(const Key& key) const;
	template <typename Function>
	bool apply(const Key& key, Function f);
	template <typename Function>
	void preorder(Function f);
	template <typename Function>
	void inorder(Function f);
	template <typename Function>
	void postorder(Function f);
	~BST(void);
	BST& operator =(const BST& rhs);
private:
	bool remove_node(Node*& ptr, const Key& key);
	void remove_max_node(Node*& ptr, Item& data);
	void del(Node*& ptr);
	void copy(Node* ptr);
	std::size_t tree_height(const Node* root) const;
	template <typename Function>
	void preorderTrav(Node* ptr,Function n);
	template <typename Function>
	void inorderTrav(Node* ptr,Function n);
	template <typename Function>
	void postorderTrav(Node* ptr,Function n);
	Node* recurse(Node*& ptr,const Key& key) const;
	Node* root;
	std::size_t Size;
};
}

#include "BST.cpp"
