namespace CS262{

template <typename Item, typename Key>
BST<Item,Key>::BST()
{
	Size = 0;
	root = NULL;
}

template <typename Item, typename Key>
void BST<Item,Key>::insert(const Item& value){
	Node* ptr = root;
	if(root==NULL) {
		root=new Node(value);
		Size++;
		return;
	}

	while (ptr!=NULL){
		if (ptr->data == value) break;
		else if(ptr->data > value && ptr->left != NULL) ptr=ptr->left;
		else if (ptr->data > value && ptr->left == NULL){ 
			ptr->left = new Node(value);
			Size++;
			break;
		}
		else if (ptr->data < value && ptr->right != NULL) ptr=ptr->right;
		else if (ptr->data < value && ptr->right ==NULL){
			ptr->right = new Node(value);
			Size++;
			break;
		}
	}
}

template <typename Item, typename Key>
typename BST<Item,Key>::Node* BST<Item,Key>::recurse(Node*& ptr,const Key& key) const{
	if (ptr!= NULL && key == ptr->data) return ptr;
	else if (ptr!= NULL && key < ptr->data && ptr->left !=NULL) return recurse(ptr->left,key);
	else if (ptr!= NULL && key > ptr->data && ptr->right !=NULL) return recurse(ptr->right,key);
	else {
		return NULL;
	}
}

template <typename Item, typename Key>
Item* BST<Item,Key>::search(const Key& key) const{
	Node* ptr=root;
	ptr=recurse(ptr,key);
	if (ptr==NULL) return NULL;
	Item* dat=&(ptr->data);
	return dat;
}

template <typename Item, typename Key>
bool BST<Item, Key>::remove_node(Node*& ptr, const Key& key) {
    if (ptr == NULL) {
        return false;
    }
    if (key < ptr->data) {
        return remove_node(ptr->left, key);
    } else if (key > ptr->data) {
        return remove_node(ptr->right, key);
        
    } else {
        if (ptr->left == NULL) {
            Node* temp = ptr;
            ptr = ptr->right;
            delete temp;
        } else {
            remove_max_node(ptr->left, ptr->data);
        }
    }
    return true;
}

template <typename Item, typename Key>
void BST<Item, Key>::remove_max_node(Node*& ptr, Item& data) {
    if (ptr->right == NULL) {
        Node* temp = ptr;
        data = ptr->data;
        ptr = ptr->left;
        delete temp;
    } else {
        remove_max_node(ptr->right, data);
    }
}
template <typename Item, typename Key>
bool BST<Item,Key>::remove(const Key& key){
    if (remove_node(root, key)) {
        Size--;
        return true;
    }
    
    return false;
}

template <typename Item, typename Key>
const Item& BST<Item,Key>::min() const{
	Node* ptr = root;
	while (ptr->left != NULL) ptr=ptr->left;
	return ptr->data;
}

template <typename Item, typename Key>
const Item& BST<Item,Key>::max() const{
	Node* ptr = root;
	while (ptr->right != NULL) ptr=ptr->right;
	return ptr->data;
}

template <typename Item, typename Key>
std::size_t BST<Item, Key>::tree_height(const Node* root) const{
    if (root == NULL) return 0;

    return 1 + std::max(tree_height(root->left), tree_height(root->right));
}

template <typename Item, typename Key>
std::size_t BST<Item,Key>::height() const{
	return tree_height(root);
}

template <typename Item, typename Key>
template <typename Function>
void BST<Item, Key>::preorder(Function m) {
	preorderTrav(root,m);
}
template <typename Item, typename Key>
template <typename Function>
void BST<Item, Key>::preorderTrav(Node* ptr,Function n) {
	if (ptr == NULL) return;
	n(ptr->data);
	preorderTrav(ptr->left,n);
	preorderTrav(ptr->right,n);
}

template <typename Item, typename Key>
template <typename Function>
void BST<Item, Key>::inorderTrav(Node* ptr,Function n) {
	if (ptr == NULL) return;
	inorderTrav(ptr->left,n);
	n(ptr->data);
	inorderTrav(ptr->right,n);
}

template <typename Item, typename Key>
template <typename Function>
void BST<Item, Key>::postorderTrav(Node* ptr,Function n) {
	if (ptr == NULL) return;
	postorderTrav(ptr->left,n);
	postorderTrav(ptr->right,n);
	n(ptr->data);
}

template <typename Item, typename Key>
template <typename Function>
void BST<Item, Key>::inorder(Function m) {
	inorderTrav(root,m);
}

template <typename Item, typename Key>
template <typename Function>
void BST<Item, Key>::postorder(Function m) {
	postorderTrav(root,m);
}

template <typename Item, typename Key>
void BST<Item,Key>::del(Node*& ptr){
	if(ptr==NULL) return;
	else{
		if(ptr->left==NULL && ptr->right==NULL) delete ptr;
		else{
			if(ptr->left!=NULL) return del(ptr->left);
			if(ptr->right != NULL) return del(ptr->right);
		}
	}
}

template <typename Item, typename Key>
BST<Item,Key>::~BST(void)
{
	del(root);
}



template <typename Item, typename Key>
BST<Item,Key>& BST<Item,Key>::operator = (const BST& rhs){
	if (&rhs==this) return *this;
	del(root);
	root=NULL;
	copy(rhs.root);
	Size=rhs.size();
	return *this;
}


template <typename Item, typename Key>
BST<Item,Key>::BST(BST& Original){
	Size=0;
	root=NULL;
	copy(Original.root);
}

template <typename Item, typename Key>
void BST<Item,Key>::copy(Node* ptr){
	insert(ptr->data);
	if(ptr->left != NULL) copy(ptr->left);
	if(ptr->right != NULL) copy(ptr->right);
}

template <typename Item, typename Key>
template <typename Function>
bool BST<Item,Key>::apply(const Key& key, Function f){
	Node* n=recurse(root,key);
	if (n==NULL) return false;
	else{
		f((n->data));
		return true;
	}
}
}