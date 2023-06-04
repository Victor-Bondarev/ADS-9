// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>

template <typename T>
class BST {
 private:
    struct NODE {
        T value;
        int count;
        NODE *left, *right;
    };
    NODE* root;
    NODE* addNODE(NODE* root, const T& value) {
        if (!root) {
            root = new NODE{value, 1, nullptr, nullptr};
        } else if (root->value > value) {
            root->left = addNODE(root->left, value);
        } else if (root->value < value) {
            root->right = addNODE(root->right, value);
        } else {
            ++root->count;
        }
        return root;
    }
    int heightTree(NODE* root) {
        return root ? std::max(heightTree(root->left), heightTree(root->right)) + 1 : 0;
    }
    NODE* searchTree(NODE* root, const T& value) {
        return !root || root->value == value ? root : value < root->value ? searchTree(root->left, value) : searchTree(root->right, value);
    }

 public:
    BST() : root(nullptr) {}
    void add(const T& value) { root = addNODE(root, value); }
    int depth() { return heightTree(root) - 1; }
    int search(const T& value) { return searchTree(root, value) ? searchTree(root, value)->count : 0; }
};

#endif  // INCLUDE_BST_H_
