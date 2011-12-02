#include "BinarySearchTree.h"

namespace CS262 {
	template <typename Item, typename Key>
		BinarySearchTree<Item, Key>::BinarySearchTree() {
			nodeCount = 0;
			root = new TreeNode<Item>(Item& data);
			TreeNode* left = 0;
			TreeNode* right = 0;
		}
	
	template <typename Item, typename Key>
		BinarySearchTree<Item, Key>::bool operator <(const Key& L, const Item& R) { 
			return L < R.name;
		}
	
	template <typename Item, typename Key>
		BinarySearchTree<Item, Key>::bool operator >(const Key& L, const Item& R) { 
			return L > R.name;
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
}