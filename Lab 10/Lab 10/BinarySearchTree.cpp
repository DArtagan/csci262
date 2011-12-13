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
			nodeCount = 0;
			root = NULL;
			copy(source.root);
		}

	template <typename Item, typename Key>
		BinarySearchTree<Item, Key>& BinarySearchTree<Item, Key>::operator =(const BinarySearchTree& RHS) {
			if(root == RHS.root) return *this;
			clearTree(root);
			root = NULL;
			copy(RHS.root);
			nodeCount = RHS.size();
			return *this;
		}

	template <typename Item, typename Key>
		void BinarySearchTree<Item, Key>::insert(const Item& data) {
			TreeNode* ptr = root;
			if(root == NULL) {
				root = new TreeNode(data);
				nodeCount++;
				return;
			}
			while(ptr != NULL) {
				if(ptr->data == data) {
					break;
				} else if(ptr->data > data && ptr->left != NULL) {
					ptr=ptr->right;
					break;
				} else if(ptr->data < data && ptr->right == NULL) {
					ptr->right = new TreeNode(data);
					nodeCount++;
					break;
				}
			}
		}

	template <typename Item, typename Key>
		bool BinarySearchTree<Item,Key>::remove(const Key& key) {
			if(removeNode(root, key)) {
				nodeCount--;
				return true;
			}
			return false;
		}

	template <typename Item, typename Key>
		Item* BinarySearchTree<Item,Key>::search(const Key& key) const {
			return search(root, key);
		}

	template <typename Item, typename Key>
		Item* BinarySearchTree<Item,Key>::search(const TreeNode* theRoot, const Key& key) const {
			// if the Key is less than the current node
			if(key < theRoot->data) {
				search(theRoot->left, key);
			// if the Key is greater than the current node
			} else if(key > theRoot->data) {
				search(theRoot->right, key);
			// otherwise, they're equal
			} else if(key == theRoot->data) {
				Item* temp = &(root->data);
				return temp;
			} else {
				return NULL;
			}
		}

	template <typename Item, typename Key>
		std::size_t BinarySearchTree<Item,Key>::height(const TreeNode* theRoot) const{
			if(theRoot == NULL) theRoot = this->root;

			return 1 + std::max(height(theRoot->left), height(theRoot->right));
		}

	template <typename Item, typename Key>
		const Item& BinarySearchTree<Item,Key>::min() const{
			TreeNode* ptr = root;
			while (ptr->left != NULL) ptr=ptr->left;
			return ptr->data;
		}

	template <typename Item, typename Key>
		const Item& BinarySearchTree<Item,Key>::max() const{
			TreeNode* ptr = root;
			while (ptr->right != NULL) ptr=ptr->right;
			return ptr->data;
		}

	template <typename Item, typename Key>
		template <typename Function>
		bool BinarySearchTree<Item,Key>::apply(const Key& key, Function f){
			Item* n = search(key);
			if (n==NULL) {
				return false;
			} else {
				f(*n);
				return true;
			}
		}

	template <typename Item, typename Key>
		template <typename Function>
			void BinarySearchTree<Item, Key>::preorder(Function f, TreeNode* ptr) {
				if(ptr == NULL) ptr = this->root;
				f(ptr->data);
				preorder(f, ptr->left);
				preorder(f, ptr->right);
			}

	template <typename Item, typename Key>
		template <typename Function>
			void BinarySearchTree<Item, Key>::inorder(Function f, TreeNode* ptr) {
				if(ptr == NULL) ptr = this->root;
				inorder(f, ptr->left);
				f(ptr->data);
				inorder(f, ptr->right);
			}

	template <typename Item, typename Key>
		template <typename Function>
			void BinarySearchTree<Item, Key>::postorder(Function f, TreeNode* ptr) {
				if(ptr == NULL) ptr = this->root;
				postorder(f, ptr->left);
				postorder(f, ptr->right);
				f(ptr->data);
			}
	
	template <typename Item, typename Key>
		void BinarySearchTree<Item,Key>::copy(TreeNode* ptr){
			insert(ptr->data);
			if(ptr->left != NULL) copy(ptr->left);
			if(ptr->right != NULL) copy(ptr->right);
		}

	template <typename Item, typename Key>
		void BinarySearchTree<Item,Key>::clearTree(TreeNode*& ptr){
			if(ptr==NULL) return;
			else{
				if(ptr->left==NULL && ptr->right==NULL) {
					delete ptr;
				} else {
					if(ptr->left!=NULL) return clearTree(ptr->left);
					if(ptr->right != NULL) return clearTree(ptr->right);
				}
			}
		}

	template <typename Item, typename Key>
		bool BinarySearchTree<Item, Key>::removeNode(TreeNode*& ptr, const Key& key) {
			if (ptr == NULL) {
				return false;
			}
			if (key < ptr->data) {
				return removeNode(ptr->left, key);
			} else if (key > ptr->data) {
				return removeNode(ptr->right, key);
			} else {
				if (ptr->left == NULL) {
					TreeNode* temp = ptr;
					ptr = ptr->right;
					delete temp;
				} else {
					removeMaxNode(ptr->left, ptr->data);
				}
			}
			return true;
		}

	template <typename Item, typename Key>
		void BinarySearchTree<Item, Key>::removeMaxNode(TreeNode*& ptr, Item& data) {
			if (ptr->right == NULL) {
				TreeNode* temp = ptr;
				data = ptr->data;
				ptr = ptr->left;
				delete temp;
			} else {
				removeMaxNode(ptr->right, data);
			}
		}

	/*template <typename Item, typename Key>
		BinarySearchTree<Item, Key>::TreeNode<Item>*& BinarySearchTree<Item,Key>::recurse(TreeNode*& ptr,const Key& key) const{
			if (ptr!= NULL && key == ptr->data) {
					return ptr;
			} else if (ptr!= NULL && key < ptr->data && ptr->left !=NULL) {
				return recurse(ptr->left,key);
			} else if (ptr!= NULL && key > ptr->data && ptr->right !=NULL) {
				return recurse(ptr->right,key);
			} else {
				return NULL;
			}
		}*/
}