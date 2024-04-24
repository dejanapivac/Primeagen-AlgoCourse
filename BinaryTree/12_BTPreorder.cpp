#include <iostream>
#include <vector>

using namespace std;

struct BinaryNode {
    int value;
    BinaryNode *left, *right;

    explicit BinaryNode(int v) {
        value = v;
        left = right = nullptr;
    }
};

vector<int> walk(BinaryNode *curr, vector<int> &path) {
    if (!curr) {
        return path;
    }

    path.push_back(curr->value);

    walk(curr->left, path);
    walk(curr->right, path);

    return path;
}

vector<int> preorder_BT(BinaryNode *head) {
    vector<int> arr = {};
    return walk(head, arr);
}

int main() {
    auto *root = new BinaryNode(6);
//    root->left = new BinaryNode(4);
//    root->right = new BinaryNode(2);
//    root->left->left = new BinaryNode(5);
//    root->left->right = new BinaryNode(3);
//    root->right->left = new BinaryNode(9);
//    root->right->right = new BinaryNode(34);
//    root->left->left->left = new BinaryNode(76);

    root->left = new BinaryNode(2);
    root->right = new BinaryNode(3);
    root->left->left = new BinaryNode(4);
    root->left->right = new BinaryNode(5);

    vector<int> result = preorder_BT(root);

    for (int i: result) {
        cout << i << " ";
    }


    return 0;
}