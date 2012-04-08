#pragma once
#include <cstdlib>

namespace CS262 {
	template <typename Item, typename Key = Item>
	class BinarySearchTree {
		struct TreeNode {
			TreeNode(const Item& data = Item()) : data(data), left(NULL), right(NULL) { }
			Item data;
			TreeNode* left;   // left child
			TreeNode* right;  // right child
		};

		public:
			BinarySearchTree();
			~BinarySearchTree(void);
			BinarySearchTree(const BinarySearchTree& source);

			BinarySearchTree& operator =(const BinarySearchTree& RHS);

			void insert(const Item& value);
			void insert(const Item& value, TreeNode*&);
			bool remove(const Key& key);
			Item* search(const Key& key) const;
			Item* search(TreeNode* theRoot, const Key& key) const;

			std::size_t size() const { return nodeCount; }
			std::size_t height() const;
			std::size_t height(const TreeNode*, std::size_t) const;

			
			const Item& min() const;
			const Item& min(TreeNode* theRoot) const;
			const Item& max() const;
			const Item& max(TreeNode* theRoot) const;

			template <typename Function>
				bool apply(const Key& key, Function f);
			template <typename Function>
				void preorder(Function f) { preorder(f, root); }
			template <typename Function>
				void preorder(Function f, TreeNode*& ptr);
			template <typename Function>
				void inorder(Function f) { inorder(f, root); }
			template <typename Function>
				void inorder(Function f, TreeNode*& ptr);
			template <typename Function>
				void postorder(Function f) { postorder(f, root); }
			template <typename Function>
				void postorder(Function f, TreeNode*& ptr);

		private:
			void copy(TreeNode* ptr);
			void clearTree(TreeNode*& ptr);
			bool removeNode(TreeNode*& ptr, const Key& key);
			void removeMaxNode(TreeNode*& ptr, Item& data);
			//TreeNode* recurse(TreeNode*& ptr, const Key& key) const;

			TreeNode* root;
			std::size_t nodeCount;
	};
}

#include "BinarySearchTree.cpp"