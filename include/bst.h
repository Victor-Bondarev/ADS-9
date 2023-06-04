// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>

template<typename T>
class BST {
 private:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
    };
    Node* root;
    Node* addNode(Node*, const T&);
    Node* searchTree(Node*, const T&);
    int heightTree(Node*);

 public:
    BST() : root(nullptr) {}
    void add(const T&);
    int search(const T&);
    int depth();
};

template <typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, const T& value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 0;
        root->left = root->right = nullptr;
    }
    if (value < root->value) {
        root->left = addNode(root->left, value);
    }  else if (value > root->value) {
        root->right = addNode(root->right, value);
    }  else {
        root->count++;
    }
    return root;
}

template <typename T>
typename BST<T>::Node* BST<T>::searchTree(Node* root, const T& value) {
    if (root == nullptr || root->value == value) {
        return root;
    }
    if (value < root->value) {
        return searchTree(root->left, value);
    }  else {
        return searchTree(root->right, value);
    }
}

template <typename T>
int BST<T>::heightTree(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int rightHeight = heightTree(root->right);
    int leftHeight = heightTree(root->left);
    return std::max(leftHeight, rightHeight) + 1;
}

template <typename T>
int BST<T>::search(const T& value) {
    Node* node = searchTree(root, value);
    return (node != nullptr) ? node->count : 0;
}

template <typename T>
void BST<T>::add(const T& value) {
    root = addNode(root, value);
}

template <typename T>
int BST<T>::depth() {
    return heightTree(root) - 1;
}
#endif  // INCLUDE_BST_H_
