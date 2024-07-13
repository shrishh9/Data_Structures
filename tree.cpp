#include <iostream>

// Define a TreeNode structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Define a Tree class
class Tree {
private:
    TreeNode* root;

    // Helper function for inserting a node
    TreeNode* insertRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return new TreeNode(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    // Helper function for in-order traversal
    void inOrderRecursive(TreeNode* node) {
        if (node != nullptr) {
            inOrderRecursive(node->left);
            std::cout << node->data << " ";
            inOrderRecursive(node->right);
        }
    }

    // Helper function for pre-order traversal
    void preOrderRecursive(TreeNode* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preOrderRecursive(node->left);
            preOrderRecursive(node->right);
        }
    }

    // Helper function for post-order traversal
    void postOrderRecursive(TreeNode* node) {
        if (node != nullptr) {
            postOrderRecursive(node->left);
            postOrderRecursive(node->right);
            std::cout << node->data << " ";
        }
    }

public:
    // Constructor
    Tree() : root(nullptr) {}

    // Insert method
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // In-order traversal method
    void inOrderTraversal() {
        inOrderRecursive(root);
        std::cout << std::endl;
    }

    // Pre-order traversal method
    void preOrderTraversal() {
        preOrderRecursive(root);
        std::cout << std::endl;
    }

    // Post-order traversal method
    void postOrderTraversal() {
        postOrderRecursive(root);
        std::cout << std::endl;
    }
};

// Main function for testing
int main() {
    Tree tree;

    // Prompt user to enter integers
    std::cout << "Enter integers to insert into the tree (-1 to stop):\n";

    int value;
    while (true) {
        std::cin >> value;
        if (value == -1) {
            break;
        }
        tree.insert(value);
    }

    // Printing traversals
    std::cout << "In-order traversal:" << std::endl;
    tree.inOrderTraversal();

    std::cout << "Pre-order traversal:" << std::endl;
    tree.preOrderTraversal();

    std::cout << "Post-order traversal:" << std::endl;
    tree.postOrderTraversal();

    return 0;
}
