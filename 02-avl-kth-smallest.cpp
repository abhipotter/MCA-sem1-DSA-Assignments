#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
    int key, height, size;
    Node *left, *right;
    Node(int value) : key(value), height(1), size(1), left(nullptr), right(nullptr) {}
    ~Node() { delete left; delete right; }
};

int height(Node* node) { return node ? node->height : 0; }
int sizeOf(Node* node) { return node ? node->size : 0; }
void update(Node* node) {
    node->height = 1 + max(height(node->left), height(node->right));
    node->size = 1 + sizeOf(node->left) + sizeOf(node->right);
}
Node* rotateRight(Node* node) {
    Node* child = node->left; node->left = child->right; child->right = node;
    update(node); update(child); return child;
}
Node* rotateLeft(Node* node) {
    Node* child = node->right; node->right = child->left; child->left = node;
    update(node); update(child); return child;
}
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;
    update(node);
    int balance = height(node->left) - height(node->right);
    if (balance > 1) { if (key > node->left->key) node->left = rotateLeft(node->left); return rotateRight(node); }
    if (balance < -1) { if (key < node->right->key) node->right = rotateRight(node->right); return rotateLeft(node); }
    return node;
}
Node* kthSmallest(Node* root, int k) {
    if (!root || k < 1 || k > root->size) return nullptr;
    while (root) {
        int leftSize = sizeOf(root->left);
        if (k == leftSize + 1) return root;
        if (k <= leftSize) root = root->left;
        else { k -= leftSize + 1; root = root->right; }
    }
    return nullptr;
}
int main() {
    Node* root = nullptr;
    for (int key : {30, 20, 10, 25, 40, 50, 5}) root = insert(root, key);
    int k = 4; Node* result = kthSmallest(root, k);
    if (result) cout << "k = " << k << ", kth smallest = " << result->key << endl;
    else cout << "Invalid k\n";
    delete root;
}
