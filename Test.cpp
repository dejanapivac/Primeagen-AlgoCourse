#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int value;
    Node *left, *right, *parent;

    Node(int v) {
        value = v;
        left = right = nullptr;
    }
};


bool compareTrees(Node *nodeA, Node* nodeB) {
    if(nodeA == NULL && nodeB == NULL) {
        return true;
    }

    if(!nodeA || !nodeB) {
        return false;
    }

    if(nodeA->value != nodeB->value) {
        return false;
    }

    return compareTrees(nodeA->left, nodeB->left) && compareTrees(nodeA->right, nodeB->right);
}

Node *constructTree(int arr[], int start, int end, Node *parent) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);
    root->parent = parent;

    root->left = constructTree(arr, start, mid - 1, root);
    root->right = constructTree(arr, mid + 1, end, root);

    return root;
}

void preorder(Node *curr) {
    if (!curr) {
        return;
    }

    cout << curr->value << " ";
    preorder(curr->left);
    preorder((curr->right));
}


int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = constructTree(arr, 0, n - 1, nullptr);

    int arr2[] = {1, 2, 3, 4, 12, 6, 7, 8, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    Node *root2 = constructTree(arr2, 0, n2 - 1, nullptr);

    preorder(root);
    cout<<endl;
    preorder(root2);
    cout<<endl;

    if(compareTrees(root, root2)) {
        cout<<"isti";
    } else {
        cout<<"nisu isti";
    }


}