#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node *left, *right, *parent;
    explicit Node(int v) {
        value = v;
//        left = right = parent = nullptr;
    }
};

// LEETCODE 510 - inorder successor

vector<int> inorder()

// LEETCODE 108

Node* constructTree(int arr[], int start, int end) {
    if(start > end) {
        return NULL;
    }

    int midpoint = (start+end) / 2;
    Node* root = new Node(arr[midpoint]);

    root->left = constructTree(arr, start, midpoint-1);

    root->right = constructTree(arr, midpoint + 1, end);

    return root;
}

void preOrder(Node* node) {
    if(node == NULL) {
        return;
    }
    cout<<node->value << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main() {

    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = constructTree(arr, 0, n - 1);

    preOrder(root);

    return 0;
}