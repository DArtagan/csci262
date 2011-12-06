#include "BinarySearchTree.h"

namespace CS262 {
	template <typename Item, typename Key>
		BinarySearchTree<Item, Key>::BinarySearchTree() {
			root = NULL;
			nodeCount = 0;
		}

	template <typename Item, typename Key>
		BinarySearchTree<Item, Key>::~BinarySearchTree() {
			clearTree(root);
		}

	template <typename Item, typename Key>
		BinarySearchTree<Item, Key>::BinarySearchTree(const BinarySearchTree<Item, Key>& source) {
			
		}

	template <typename Item, typename Key>
		bool BinarySearchTree<Item, Key>::insert(const Item& data) {
			if(!(root->left)) {
				root->left = new TreeNode(data);
				return true;
			} else if(!(root->right)) {
				root->right = new TreeNode(data);
				return true;
			} else {
				return false;
			}
		}

	template <typename Item, typename Key>
		template <typename Function>
			void BinarySearchTree<Item, Key>::preorder(Function m) {
				return;
			}

	template <typename Item, typename Key>
		template <typename Function>
			void BinarySearchTree<Item, Key>::inorder(Function m) {
				return;
			}

	template <typename Item, typename Key>
		template <typename Function>
			void BinarySearchTree<Item, Key>::postorder(Function m) {
				return;
			}

	/*template <typename Item, typename Key>
		bool BinarySearchTree<Item, Key>::isLeaf() {
			if(*root->left == NULL && *root->right == NULL) {
				return true;
			} else {
				return false;
			}
		}*/
}