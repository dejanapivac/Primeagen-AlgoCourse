#include <iostream>

using namespace std;

struct BinaryNode {
    int value;
    BinaryNode *left, *right;

    BinaryNode(int v) {
        value = v;
        left = right = nullptr;
    }
};

// log n ili n
bool search(BinaryNode *curr, int needle) {
    if (!curr) {
        return false;
    }

    if (curr->value == needle) {
        return true;
    }

    if (curr->value < needle) {
        return search(curr->right, needle);
    }

    return search(curr->left, needle);
}

bool dfs(BinaryNode *head, int needle) {
    return search(head, needle);
}

int main() {

    BinaryNode* root = new BinaryNode(5);
    root->left = new BinaryNode(3);
    root->right = new BinaryNode(10);
    root->left->left = new BinaryNode(1);
    root->left->right = new BinaryNode(4);
    root->right->right = new BinaryNode(13);
    root->right->left = new BinaryNode(7);

    if(dfs(root, 111)) {
        cout<<"ima";
    } else {
        cout << "nema";
    }

    return 0;
}