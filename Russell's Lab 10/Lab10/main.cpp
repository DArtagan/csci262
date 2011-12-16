#include "BinarySearchTree.h" // change this line to whatever you named your file
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <utility>
#include <cmath>
#include <sstream>
using namespace std;
using namespace CS262;
using namespace rel_ops;


// ** change 'BSTree' to whatever you named your class
#define TreeType BinarySearchTree

// ** change this to true if you implement a balanced BST for extra credit!
#define BALANCED false

// ** uncomment the following line if you implement iterators for extra credit!
// #define ITERATORS


// returns the ideal height of a tree with n nodes
size_t balanced_height(size_t n) { 
    return (n < 2) ? n : 1 + (size_t) (log10((double) n) / log10(2.0));
}


// a simple compound data type
struct Person {
    string name;
    int age;

    bool operator <(const Person& other) const { return (name < other.name); }
    bool operator ==(const Person& other) const { return (name == other.name); }

    operator string() const { return name; }
};


// operators for comparing a string to a Person (a Key to an Item)
bool operator <(const string& L, const Person& R) { return L < R.name; }
bool operator >(const string& L, const Person& R) { return L > R.name; }
bool operator ==(const string& L, const Person& R) { return L == R.name; }
bool operator !=(const string& L, const Person& R) { return L != R.name; }
bool operator <=(const string& L, const Person& R) { return L <= R.name; }
bool operator >=(const string& L, const Person& R) { return L >= R.name; }


// output operator for Person class
ostream& operator <<(ostream& out, const Person& p) { return out << p.name; }


/**
 * Uses assertions to exercise all the methods of your class. Assumes that your
 * method names are as specified in the assignment page.
**/
template <typename Item, typename Key>
void test_tree(TreeType<Item, Key>, const vector<Item>&);


/**
 * Main routine exercises two versions of your class using simple values...
**/
int main() {
    const size_t NUM_VALUES = 15;

    // create vectors containing the values to use
    vector<int> nums(NUM_VALUES);
    vector<Person> people(NUM_VALUES);

    // populate them with values
    for (size_t i = 0; i < NUM_VALUES; i++) {
        nums[i] = people[i].age = i;
        people[i].name = char('A' + i);
    }

    // create the empty trees
    TreeType<int> t1;
    TreeType<Person, string> t2;

    // testing when the data type is also the key
    cout << "Testing case when Item type is also the Key type... " << endl;
    test_tree(t1, nums);
    cout << "Passed!\n\n";

    // testing when the Item type has a different Key type
    cout << "Testing case with different Item and Key types... " << endl;
    test_tree(t2, people);
    cout << "Passed!\n\n";

    // all tests passed
    cout << "Nicely done!" << endl;
    return EXIT_SUCCESS;
}


// simple stringstreams for testing purposes
stringstream s1, s2;


// outputs a value to the stringstream for testing
template <typename Item>
void output_value(Item& data) {
    s1 << data;
}


// inserts the contents of the vector in way that yields a balanced tree
template <typename Item, typename Key>
void balanced_insert(TreeType<Item, Key>& tree, const vector<Item> values, int beg, int end) {
    if (beg > end) return;

    size_t mid = ceil((beg + end) / 2.0);
    tree.insert(values[mid]);

    if (beg != end) {
        balanced_insert(tree, values, beg, mid - 1);
        balanced_insert(tree, values, mid + 1, end);
    }
}


// fills ss with data in preorder fashion
template <typename Item>
void vector_preorder(stringstream& ss, const vector<Item> values, int beg, int end) {
    if (beg > end) return;

    size_t mid = ceil((beg + end) / 2.0);
    ss << values[mid];

    if (beg != end) {
        vector_preorder(ss, values, beg, mid - 1);
        vector_preorder(ss, values, mid + 1, end);
    }
}


// fills ss with data in inorder fashion
template <typename Item>
void vector_inorder(stringstream& ss, const vector<Item> values, int beg, int end) {
    if (beg > end) return;

    size_t mid = ceil((beg + end) / 2.0);

    if (beg != end) vector_inorder(ss, values, beg, mid - 1);

    ss << values[mid];

    if (beg != end) vector_inorder(ss, values, mid + 1, end);
}


// fills ss with data in postorder fashion
template <typename Item>
void vector_postorder(stringstream& ss, const vector<Item> values, int beg, int end) {
    if (beg > end) return;

    size_t mid = ceil((beg + end) / 2.0);

    if (beg != end) {
        vector_postorder(ss, values, beg, mid - 1);
        vector_postorder(ss, values, mid + 1, end);
    }

    ss << values[mid];
}


template <typename Item, typename Key>
void test_tree(TreeType<Item, Key> tree, const vector<Item>& values) {
    // tree should initially be empty
    assert(tree.size() == 0);
    assert(tree.height() == 0);

    // insert a single value (becomes root of tree)
    tree.insert(values[0]);

    // ensure that the tree has a size and height of 1...
	assert(tree.size() == 1);
    assert(tree.height() == 1);

    // ensure the value appears in the tree...
    assert(tree.search(values[0]));

    // and that your function correctly returns a pointer to the value
    assert(*tree.search(values[0]) == values[0]);

    // testing removing the root node (resulting in an empty tree)
    assert(tree.remove(values[0]));

    // ensure that the tree is once again empty...
    assert(tree.size() == 0);
    assert(tree.height() == 0);

    // ensure that removing a non-existent value doesn't fail (should return false)
    assert(!tree.remove(values[0]));

    // ensure that the value no longer appears in the tree...
	assert(!tree.search(values[0]));

    // insert all the values this time in sorted order...
    for (size_t i = 0; i < values.size(); i++) {
        tree.insert(values[i]);

		// ensure the value appears in the tree...
		assert(tree.search(values[i]));

        // ensure that the size is correct...
        assert(tree.size() == i + 1);

        // height of tree depends on whether you're balancing as you go or not
        assert(tree.height() == (BALANCED ? balanced_height(tree.size()) : tree.size()));
    }

    // ensure min and max work
    assert(tree.min() == *min_element(values.begin(), values.end()));
    assert(tree.max() == *max_element(values.begin(), values.end()));

    // remove all the values, starting with the root
    for (size_t i = 0; i < values.size(); i++) {
        // remove the value
        tree.remove(values[i]);

        // ensure the value no longer appears in the tree...
        assert(!tree.search(values[i]));

        // ensure that the size is correct...
        assert(tree.size() == values.size() - i - 1);

        // height of tree depends on whether you're balancing as you go or not
        assert(tree.height() == (BALANCED ? balanced_height(tree.size()) : tree.size()));
    }

    // insert all the values this time in balanced order...
    balanced_insert(tree, values, 0, values.size() - 1);

    // make sure the size is still right...
    assert(tree.size() == values.size());

    // height of tree should be ceil(log2(n))
    assert(tree.height() == balanced_height(tree.size()));

    // can't insert duplicate values (size & height shouldn't increase)
    // operation should simply fail silently (do nothing)
    tree.insert(values[0]);
    assert(tree.size() == values.size());
    assert(tree.height() == balanced_height(values.size()));

    // ensure min and max (still) work
    assert(tree.min() == *min_element(values.begin(), values.end()));
    assert(tree.max() == *max_element(values.begin(), values.end()));

    // testing copy constructor
    TreeType<Item, Key>* copy = new TreeType<Item, Key>(tree);
    assert(copy->size() == tree.size());
    assert(copy->height() == tree.height());
    
    // original should remain unchanged after copy modification
    copy->remove(values[1]);
    copy->remove(values[values.size() - 2]);
    assert(copy->size() == tree.size() - 2);
    assert(tree.search(values[1]));
    assert(tree.search(values[values.size() - 2]));
    
	// testing destructor
	cout << "got_here";
	delete copy;
    
    // the original should remain unchanged
    for (size_t i = 0; i < values.size(); i++) {
        assert(tree.search(values[i]));
    }
    
    // testing assignment operator
    copy = new TreeType<Item, Key>;
    *copy = tree;
    
    // original should remain unchanged after copy modification
    copy->remove(values[1]);
    copy->remove(values[values.size() - 2]);
    assert(copy->size() == tree.size() - 2);
    assert(tree.search(values[1]));
    assert(tree.search(values[values.size() - 2]));
    
    // testing destructor
	cout << "Got here";
    delete copy;
    
    // the original should remain unchanged
    for (size_t i = 0; i < values.size(); i++) {
        assert(tree.search(values[i]));
    }

    // testing preorder traversal
    s1.str(""); s2.str("");
    vector_preorder(s2, values, 0, values.size() - 1);
    tree.preorder(output_value<Item>);
    assert(s1.str() == s2.str());

    // testing inorder traversal
    s1.str(""); s2.str("");
    vector_inorder(s2, values, 0, values.size() - 1);
    tree.inorder(output_value<Item>);
    assert(s1.str() == s2.str());
    
    // testing postorder traversal
    s1.str(""); s2.str("");
    vector_postorder(s2, values, 0, values.size() - 1);
    tree.postorder(output_value<Item>);
    assert(s1.str() == s2.str());
    
    // testing apply
    s1.str(""); s2.str("");
    s2 << values[0];
    tree.apply(values[0], output_value<Item>);
    assert(s1.str() == s2.str());
    
#ifdef ITERATORS
    // testing iterators (smallest-to-largest order)
    typename TreeType<Item, Key>::iterator t = tree.begin();
    typename vector<Item>::const_iterator v = values.begin();
        
    while (t != tree.end()) {
        assert(*t == *v);
        ++t;
        ++v;
    }
        
    assert(v == values.end());
#endif
}
