#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int value) : key(value), left(nullptr), right(nullptr) {}
    ~Node() { delete left; delete right; }
};

int check(Node* root, long long low, long long high) {
    if (root == nullptr) return 0;
    if (root->key <= low || root->key >= high) return -1;
    int leftHeight = check(root->left, low, root->key);
    int rightHeight = check(root->right, root->key, high);
    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) return -1;
    return max(leftHeight, rightHeight) + 1;
}

bool isAVL(Node* root) { return check(root, LLONG_MIN, LLONG_MAX) != -1; }

int main() {
    Node root(20);
    root.left = new Node(10);
    root.right = new Node(30);
    root.left->left = new Node(5);
    root.left->right = new Node(15);
    cout << boolalpha << "Is AVL: " << isAVL(&root) << endl;
    root.left->left->left = new Node(2);
    cout << "After adding 2: " << isAVL(&root) << endl;
}
