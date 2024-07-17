#pragma once
#include <iostream>
using namespace std;

// AVL Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = nullptr;
    }

    // Function to get the height of a node
    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // Function to get the balance factor of a node
    int getBalanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Function to update the height of a node
    void updateHeight(Node* node) {
        if (node == nullptr)
            return;
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    // Function to perform a right rotation
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Function to perform a left rotation
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // Function to insert a new node into the AVL tree
    Node* insert(Node* root, int data) {
        if (root == nullptr) {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->height = 1;
            return newNode;
        }

        if (data < root->data)
            root->left = insert(root->left, data);
        else if (data > root->data)
            root->right = insert(root->right, data);
        else
            return root; // Duplicate keys are not allowed in AVL trees

        updateHeight(root);

        int balanceFactor = getBalanceFactor(root);

        // Left-Left Case
        if (balanceFactor > 1 && data < root->left->data)
            return rotateRight(root);

        // Right-Right Case
        if (balanceFactor < -1 && data > root->right->data)
            return rotateLeft(root);

        // Left-Right Case
        if (balanceFactor > 1 && data > root->left->data) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Right-Left Case
        if (balanceFactor < -1 && data < root->right->data) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    // Function to find the node with the minimum value in the AVL tree
    Node* findMinNode(Node* node) {
        if (node == nullptr || node->left == nullptr)
            return node;
        return findMinNode(node->left);
    }

    // Function to delete a node from the AVL tree
    Node* delete_node(Node* root, int data) {
        if (root == nullptr)
            return root;

        if (data < root->data)
            root->left = delete_node(root->left, data);
        else if (data > root->data)
            root->right = delete_node(root->right, data);
        else {
            // Node to be deleted is found
            if (root->left == nullptr || root->right == nullptr) {
                // Node has no child or one child
                Node* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    // Node has no child
                    temp = root;
                    root = nullptr;
                }
                else {
                    // Node has one child
                    *root = *temp;
                }

                delete temp;
            }
            else {
                // Node has two children
                Node* temp = findMinNode(root->right);
                root->data = temp->data;
                root->right = delete_node(root->right, temp->data);
            }
        }

        if (root == nullptr)
            return root;

        updateHeight(root);

        int balanceFactor = getBalanceFactor(root);

        // Left-Left Case
        if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0)
            return rotateRight(root);

        // Left-Right Case
        if (balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Right-Right Case
        if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0)
            return rotateLeft(root);

        // Right-Left Case
        if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    // Function to search for a node in the AVL tree
    bool search(Node* root, int data) {
        if (root == nullptr || root->data == data)
            return root != nullptr;

        if (data < root->data)
            return search(root->left, data);
        else
            return search(root->right, data);
    }

    // Function to get the size of the AVL tree
    int size(Node* root) {
        if (root == nullptr)
            return 0;
        return 1 + size(root->left) + size(root->right);
    }
};

