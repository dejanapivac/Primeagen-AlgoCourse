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

Node* findLeftMost(Node* node) {
    if(!node) {
        return nullptr;
    }

    findLeftMost(node->left);

    return node;
}

Node* findFirstParent(Node* node) {
    if(!node || !node->parent) {
        return nullptr;
    }

    if(node->parent->value > node->value) {
        return node->parent;
    }

    return findFirstParent(node->parent);
}

Node* inorder_successor(Node* givenNode){
    // 1. case: imamo right subtree
    // leftmost child
    // 2. case: nemamo right moramo naci parent node da taj dani node nije njegovo
    // desno dijete

    if(!givenNode) {
        return nullptr;
    }

    if(givenNode->right) {
        return findLeftMost(givenNode->right);
    } else {
        return findFirstParent(givenNode);
    }

}


// LEETCODE 108

Node* constructTree(int arr[], int start, int end, Node* parent) {
    if(start > end) {
        return NULL;
    }

    int midpoint = (start+end) / 2;
    Node* root = new Node(arr[midpoint]);
    root->parent = parent;

    root->left = constructTree(arr, start, midpoint-1, root);

    root->right = constructTree(arr, midpoint + 1, end, root);

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

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = constructTree(arr, 0, n - 1, nullptr);

    preOrder(root);

    Node* nodeToFindSuccessor = root->left->left;

    Node* successor = inorder_successor(nodeToFindSuccessor);
    if (successor)
        cout << "\nInorder successor of " << nodeToFindSuccessor->value << " is " << successor->value << endl;
    else
        cout << "\nNo inorder successor found for " << nodeToFindSuccessor->value << endl;

    return 0;
}