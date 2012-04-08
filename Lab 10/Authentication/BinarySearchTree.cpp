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
		void BinarySearchTree<Item, Key>::insert(const Item& value){
			if(root==NULL) {
				root = new TreeNode(value);
				nodeCount++;
				return;
			}
			TreeNode* ptr = root;
			while (ptr!=NULL){
				if (ptr->data == value) break;
				else if(value < ptr->data && ptr->left != NULL) ptr=ptr->left;
				else if(value < ptr->data && ptr->left == NULL){ 
					ptr->left = new TreeNode(value);
					nodeCount++;
					break;
				}
				else if(value > ptr->data && ptr->right != NULL) ptr=ptr->right;
				else if(value > ptr->data && ptr->right == NULL){
					ptr->right = new TreeNode(value);
					nodeCount++;
					break;
				}
			}
		}

	template <typename Item, typename Key>
		void BinarySearchTree<Item, Key>::insert(const Item& value, TreeNode*& t) {
			if (t == NULL) {
				t = new TreeNode(value);
				++nodeCount;
			} else if (value < t->data){
				insert(value, t->left);
			} else if (value > t->data){
				insert(value, t->right);
			} else {
				return;
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
		Item* BinarySearchTree<Item,Key>::search(TreeNode* theRoot, const Key& key) const {
			if(theRoot == NULL) return NULL;
			if(key < theRoot->data) {
				return search(theRoot->left, key);
			} else if(key > theRoot->data) {
				return search(theRoot->right, key);
			} else if(key == theRoot->data) {
				Item* temp = &(theRoot->data);
				return temp;
			} else {
				return NULL;
			}
		}

	/*template <typename Item, typename Key>
		std::size_t BinarySearchTree<Item,Key>::height(const TreeNode* theRoot) const {
			if(theRoot == NULL) return 0;

			return 1 + std::max(height(theRoot->left), height(theRoot->right));
		}*/

	template <typename Item, typename Key>
		std::size_t BinarySearchTree<Item,Key>::height() const{
			if (root == NULL) {return 0;}
			std::size_t count(1);
			std::size_t lh(height(root->left, count)), rh(height(root->right,count));
			if (lh > rh) {
				return lh;
			}
			return rh;
		}

	template <typename Item, typename Key>
		std::size_t BinarySearchTree<Item,Key>::height(const TreeNode* t, std::size_t count) const{
			if (t == NULL) {return count;}
			++count;
			std::size_t lh(height(t->left, count)), rh(height(t->right,count));
			if (lh > rh) {
				return lh;
			}
			return rh;
		}

	template <typename Item, typename Key>
		const Item& BinarySearchTree<Item, Key>::min() const{
			return min(root);
		}

	template <typename Item, typename Key>
		const Item& BinarySearchTree<Item, Key>::min(TreeNode* theRoot) const {
			TreeNode* ptr = theRoot;
			while (ptr->left != NULL) ptr = ptr->left;
			return ptr->data;
		}

	template <typename Item, typename Key>
		const Item& BinarySearchTree<Item, Key>::max() const{
			return max(root);
		}

	template <typename Item, typename Key>
		const Item& BinarySearchTree<Item,Key>::max(TreeNode* theRoot) const{
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
			void BinarySearchTree<Item, Key>::preorder(Function f, TreeNode*& ptr) {
				if(ptr == NULL) return;
				f(ptr->data);
				preorder(f, ptr->left);
				preorder(f, ptr->right);
			}

	template <typename Item, typename Key>
		template <typename Function>
			void BinarySearchTree<Item, Key>::inorder(Function f, TreeNode*& ptr) {
				if(ptr == NULL) return;
				inorder(f, ptr->left);
				f(ptr->data);
				inorder(f, ptr->right);
			}

	template <typename Item, typename Key>
		template <typename Function>
			void BinarySearchTree<Item, Key>::postorder(Function f, TreeNode*& ptr) {
				if(ptr == NULL) return;
				postorder(f, ptr->left);
				postorder(f, ptr->right);
				f(ptr->data);
			}
	
	template <typename Item, typename Key>
		void BinarySearchTree<Item,Key>::copy(TreeNode* ptr){
			if(ptr == NULL) return;
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