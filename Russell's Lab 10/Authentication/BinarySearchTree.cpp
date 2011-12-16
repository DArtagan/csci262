namespace CS262{
	template <typename Item, typename Key>
	BinarySearchTree<Item, Key>::~BinarySearchTree(){
		if (root == NULL) {delete root; return;}
		delete root;
		treesize=0;
	}

	template <typename Item, typename Key>
	BinarySearchTree<Item, Key>::BinarySearchTree(const BinarySearchTree<Item, Key>& bstree){
		treesize = 0;
		if (bstree.root == NULL) {root = NULL; return;}
		root = new TreeNode<Item>(bstree.root->data);
		++treesize;
		copynode(root->left, bstree.root->left);
		copynode(root->right, bstree.root->right);
	}

	template <typename Item, typename Key>
	BinarySearchTree<Item,Key>& BinarySearchTree<Item, Key>::operator =(const BinarySearchTree<Item, Key>& bstree){
		treesize = 0;
		if (bstree.root == NULL) {root = NULL; return *this;}
		root = new TreeNode<Item>(bstree.root->data);
		++treesize;
		copynode(root->left, bstree.root->left);
		copynode(root->right, bstree.root->right);
		return *this;
	}

	// returns the minimum value in the tree
	template <typename Item, typename Key>
	const Item& BinarySearchTree<Item, Key>::min() const{
		if (root -> left == NULL) {return root -> data;}
		return min(root->left);
	}

	// returns the maximum value in the tree
	template <typename Item, typename Key>
	const Item& BinarySearchTree<Item, Key>::max() const{
		if (root -> right == NULL) {return root -> data;}
		return max(root->right);
	}

	// inserts a copy of the given value into the tree, unless one already exists
	template <typename Item, typename Key>
	void BinarySearchTree<Item, Key>::insert(const Item& value){
		// if root is NULL
		if (root == NULL) {
			// set root to a node containing the new value
			root = new TreeNode<Item>(value);
			++treesize;
		// else if entry < root->data
		} else if (value < root->data){
			// insert value into left subtree
			insert(value, root->left);
		// else if entry > root->data
		} else if (value > root->data){
			// insert value into right subtree
			insert(value, root->right);
		} else {
			return;
		}
	}

	// removes an entry with the given key, if present in the tree
	template <typename Item, typename Key>
	bool BinarySearchTree<Item, Key>::remove(const Key& key){
		// if root is NULL
		if (root == NULL) {
			// all done
			return false;
		// else if target < root->data
		} else if (key < root->data) {
			// call delete with left pointer
			return remove(key, root->left);
			// else if target > root->data
		} else if (key > root->data) {
			// call delete with right pointer
			return remove(key, root->right);
			// else when target == root->data
		} else {
			// if no left child
			if (root->left == NULL) {
				// delete root; make right child new root
				TreeNode<Item>* temp = root->right;
				delete root;
				root = temp;
				--treesize;
				return true;
				// else
			} else {
				//replace root with largest from left subtree
				deletemaxnode(root->left, root->data);
				return true;
			}
		}
	}

	// returns a pointer to an entry with the given key (if it exists), or NULL
	template <typename Item, typename Key>
	Item* BinarySearchTree<Item, Key>::search(const Key& key) const{
		if (root == NULL) {
			return NULL;
		} else if ( key < root -> data) {
			return search(key, root->left);
		} else if ( key > root -> data) {
			return search(key, root->right);
		} else {
			return &(root -> data);
		}
	}

	// if an entry with the key exists, applies the function
	template <typename Item, typename Key>
	template <typename Function>
	bool BinarySearchTree<Item, Key>::apply(const Key& key, Function f){
		Item* temp(search(key));
		if (temp ==NULL) {
			return false;
		}
		f(*temp);
		return true;
	}

	// applies a function to each value in the tree, via preorder traversal
	template <typename Item, typename Key>
	template <typename Function>
	void BinarySearchTree<Item, Key>::preorder(Function f){
		if (root == NULL) return;
		f(root->data); // apply the method
		preorder(f, root->left);
		preorder(f, root->right);
	}

	// applies a function to each value in the tree, via inorder traversal
	template <typename Item, typename Key>
	template <typename Function>
	void BinarySearchTree<Item, Key>::inorder(Function f){
		if (root == NULL) return;
		inorder(f, root->left);
		f(root->data); // apply the method
		inorder(f, root->right);
	}

	// applies a function to each value in the tree, via postorder traversal
	template <typename Item, typename Key>
	template <typename Function>
	void BinarySearchTree<Item, Key>::postorder(Function f){
		if (root == NULL) return;
		postorder(f, root->left);
		postorder(f, root->right);
		f(root->data); // apply the method
	}

	//With TreeNode
	template <typename Item, typename Key>
	void BinarySearchTree<Item, Key>::deletenode(TreeNode<Item>*& t){
		if (t == NULL) {delete t; return;}
		delete t; // apply the method
		--treesize;
	}

	template <typename Item, typename Key>
	void BinarySearchTree<Item, Key>::copynode(TreeNode<Item>*& t, const TreeNode<Item>* b){
		if (b == NULL) {t = NULL; return;}
		t = new TreeNode<Item>(b->data);
		++treesize;
		copynode(t->left, b->left);
		copynode(t->right, b->right);
	}

	// returns the minimum value in the tree
	template <typename Item, typename Key>
	const Item& BinarySearchTree<Item, Key>::min(const TreeNode<Item>* t) const{
		if (t -> left == NULL) {return t -> data;}
		return min(t -> left);
	}

	// returns the maximum value in the tree
	template <typename Item, typename Key>
	const Item& BinarySearchTree<Item, Key>::max(const TreeNode<Item>* t) const{
		if (t -> right == NULL) {return t -> data;}
		return max(t->right);
	}

	// inserts a copy of the given value into the tree, unless one already exists
	template <typename Item, typename Key>
	void BinarySearchTree<Item, Key>::insert(const Item& value, TreeNode<Item>*& t){
		// if root is NULL
		if (t == NULL) {
			// set root to a node containing the new value
			t = new TreeNode<Item>(value);
			++treesize;
		// else if entry < root->data
		} else if (value < t->data){
			// insert value into left subtree
			insert(value, t->left);
		// else if entry > root->data
		} else if (value > t->data){
			// insert value into right subtree
			insert(value, t->right);
		} else {
			return;
		}
	}

	// removes an entry with the given key, if present in the tree
	template <typename Item, typename Key>
	bool BinarySearchTree<Item, Key>::remove(const Key& key, TreeNode<Item>*& t){
		// if root is NULL
		if (t == NULL) {
			// all done
			return false;
		// else if target < root->data
		} else if (key < t->data) {
			// call delete with left pointer
			return remove(key, t->left);
			// else if target > root->data
		} else if (key > t->data) {
			// call delete with right pointer
			return remove(key, t -> right);
			// else when target == root->data
		} else {
			// if no left child
			if (t->left == NULL) {
				// delete root; make right child new root
				TreeNode<Item>* temp = t->right;
				delete t;
				t = temp;
				--treesize;
				return true;
				// else
			} else {
				//replace root with largest from left subtree
				deletemaxnode(t->left, t->data);
				return true;
			}
		}
	}

	// returns a pointer to an entry with the given key (if it exists), or NULL
	template <typename Item, typename Key>
	Item* BinarySearchTree<Item, Key>::search(const Key& key, TreeNode<Item>*& t) const{
		if (t == NULL) {
			return NULL;
		} else if (key > t -> data) {
			return search(key, t->right);
		} else if (key < t -> data) {
			return search(key, t->left);
		} else {
			return &(t -> data);
		}
	}

	// applies a function to each value in the tree, via preorder traversal
	template <typename Item, typename Key>
	template <typename Function>
	void BinarySearchTree<Item, Key>::preorder(Function f, TreeNode<Item>*& t){
		if (t == NULL) return;
		f(t->data); // apply the method
		preorder(f, t->left);
		preorder(f, t->right);
	}

	// applies a function to each value in the tree, via inorder traversal
	template <typename Item, typename Key>
	template <typename Function>
	void BinarySearchTree<Item, Key>::inorder(Function f, TreeNode<Item>*& t){
		if (t == NULL) return;
		inorder(f, t->left);
		f(t->data); // apply the method
		inorder(f, t->right);
	}

	// applies a function to each value in the tree, via postorder traversal
	template <typename Item, typename Key>
	template <typename Function>
	void BinarySearchTree<Item, Key>::postorder(Function f, TreeNode<Item>*& t){
		if (t == NULL) return;
		postorder(f, t->left);
		postorder(f, t->right);
		f(t->data); // apply the method
	}

	template <typename Item, typename Key>
	void BinarySearchTree<Item, Key>::deletemaxnode(TreeNode<Item>*& t, Item& rdat){
		if (t->right == NULL) {
			rdat = t->data;
			delete t;
			--treesize;
		} else {
			deletemaxnode(t->right,rdat);
		}
	}

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
	std::size_t BinarySearchTree<Item,Key>::height(const TreeNode<Item>* t, std::size_t count) const{
		if (t == NULL) {return count;}
		++count;
		std::size_t lh(height(t->left, count)), rh(height(t->right,count));
		if (lh > rh) {
			return lh;
		}
		return rh;
	}

}