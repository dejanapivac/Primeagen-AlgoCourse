#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct BinaryNode {
    int value;
    BinaryNode *left, *right;
    BinaryNode(int v) {
        value = v;
        left = right = nullptr;
    }
};

bool bfs(BinaryNode *head, int needle) {
    queue<BinaryNode *> q;
    q.push(head);

    while (!q.empty()) {
        BinaryNode *curr = q.front();
        q.pop();

        // search
        if (curr->value == needle) {
            return true;
        }

        if (curr->left) {
            q.push(curr->left);
        }
        if (curr->right) {
            q.push(curr->right);
        }
    }

    return false;
}

int main() {
    auto* root = new BinaryNode(6);
    root->left = new BinaryNode(2);
    root->right = new BinaryNode(3);
    root->left->left = new BinaryNode(4);
    root->left->right = new BinaryNode(5);

    if (bfs(root, 3)) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}