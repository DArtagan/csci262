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

			bool insert(const Item& data);

			std::size_t size() const;
			std::size_t height() const;
			
			const Item& min() const;
			const Item& max() const;

			bool remove(const Key& key) const;
			Item* search(const Key& key) const;
			
			template <typename Function>
				bool apply(const Key& key, Function f);
			template <typename Function>
				void preorder(Function f);
			template <typename Function>
				void inorder(Function f);
			template <typename Function>
				void postorder(Function f);

			bool isLeaf();

		private:
			void clearTree(TreeNode*& ptr);

			TreeNode *root;
			std::size_t nodeCount;
			//Matt says consider keeping track of height
	};
}

#include "BinarySearchTree.cpp"