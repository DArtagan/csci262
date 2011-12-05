#include "BinarySearchTree.h"

namespace CS262 {
	template <typename Item, typename Key>
		BinarySearchTree<Item, Key>::BinarySearchTree() {
			root = new TreeNode<Item>(NULL);
			nodeCount = 0;
		}
	
	template <typename Item, typename Key>
		bool BinarySearchTree<Item, Key>::operator <(const Item& R) { 
			return L < R.name;
		}
	
	template <typename Item, typename Key>
		bool BinarySearchTree<Item, Key>::operator >(const Item& R) { 
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