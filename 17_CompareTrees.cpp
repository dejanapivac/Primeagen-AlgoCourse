#include <iostream>
using namespace std;

// moraju biti isti strukturom i vrijednostima u nodes

struct BinaryNode {
    int value;
    BinaryNode *left, *right;
    BinaryNode(int v) {
        value = v;
        left = right = nullptr;
    }
};

bool compareTrees(BinaryNode* a, BinaryNode* b) {
    // 1. base
    // structural check
    if(a == NULL && b == NULL) {
        return true;
    }

    // 2. case
    // structural check
    if(a == NULL || b == NULL) {
        return false;
    }

    // 3. case
    // value check
    if(a->value != b->value) {  // ZASTO NIJE ==
        return false;
    }

    return compareTrees(a->left, b->left) && compareTrees(a->right, b->right);
}

int main() {

    return 0;
}