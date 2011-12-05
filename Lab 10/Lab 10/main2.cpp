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

// a simple compound data type
struct Person {
    string name;
    int age;

    bool operator <(const Person& other) const { return (name < other.name); }
    bool operator ==(const Person& other) const { return (name == other.name); }

    operator string() const { return name; }
};

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

    return EXIT_SUCCESS;
}

