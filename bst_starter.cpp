// EE 538 - Lab 5, Part 3: Binary Search Tree
// Save your completed version as bst.cpp for CodeGrade.
// This starter compiles, but the three TODO functions are incomplete.

#include <iostream>
#include <string>

struct Node {
    int key;
    Node* left;
    Node* right;

    explicit Node(int value)
        : key(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    // TODO 1: Insert key and return the root of this subtree.
    // - Empty subtree: create one Node with new and return its pointer.
    // - Smaller/larger key: insert into the appropriate child subtree
    //   and reconnect the child to the pointer returned by insert.
    // - Equal key: leave the tree unchanged (ignore duplicates).
    // The caller uses the returned pointer, including for the first node.
    (void)key;  // Remove this placeholder when implementing the function.
    return root;
}

bool contains(const Node* root, int key) {
    // TODO 2: Return whether key occurs in this subtree.
    // Handle an empty subtree, compare with the current key, then
    // follow only the appropriate child. Recursion or iteration is OK.
    (void)root;
    (void)key;
    return false;  // Placeholder, not a completed search.
}

// Provided: print one key with exactly one space between keys.
void printKey(int key, bool& first) {
    if (!first) {
        std::cout << ' ';
    }
    std::cout << key;
    first = false;
}

void printInorder(const Node* root, bool& first) {
    // TODO 3: Recursively visit left subtree, current node, right subtree.
    // Stop at an empty subtree. Use printKey(root->key, first) when
    // visiting the current node, and pass the SAME first variable
    // to recursive calls. Do not print the final newline here.
    (void)root;
    (void)first;
}

// Provided: release every allocated node after all commands finish.
void destroyTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

// Provided: command processing and exact CodeGrade output format.
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int commandCount;
    if (!(std::cin >> commandCount)) {
        return 0;
    }

    Node* root = nullptr;
    for (int i = 0; i < commandCount; ++i) {
        std::string command;
        std::cin >> command;

        if (command == "insert") {
            int key;
            std::cin >> key;
            root = insert(root, key);
        } else if (command == "search") {
            int key;
            std::cin >> key;
            std::cout << (contains(root, key) ? 1 : 0) << '\n';
        } else if (command == "inorder") {
            if (root == nullptr) {
                std::cout << "EMPTY";
            } else {
                bool first = true;
                printInorder(root, first);
            }
            std::cout << '\n';
        }
    }

    destroyTree(root);
    return 0;
}
