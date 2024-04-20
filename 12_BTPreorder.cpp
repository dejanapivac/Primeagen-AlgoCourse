#include <iostream>
#include <vector>
using namespace std;

struct BinaryNode {
    int value;
    struct BinaryNode *left, *right;
    BinaryNode(int v) {
        value = v;
        left = right = NULL;
    }
};

vector<int> walk(BinaryNode* curr, vector<int> &path) {
    if(!curr) {
        return path;
    }

    //rec
    //pre
    path.push_back(curr->value);

    //rec
    walk(curr->left, path);
    walk(curr->right, path);

    //post
    return path;
}

vector<int> preorderSearch(BinaryNode* head) {
    vector<int> arr = {};
    return walk(head, arr);
}

int main() {

    BinaryNode* root = new BinaryNode(1);
    root->left = new BinaryNode(2);
    root->right = new BinaryNode(4);
    root->left->left = new BinaryNode(7);
    root->left->right = new BinaryNode(5);
    root->right->right = new BinaryNode(8);
    vector<int> result = preorderSearch(root);

    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}