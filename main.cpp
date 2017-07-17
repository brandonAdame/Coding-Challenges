#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d, Node* l, Node* r) {
        this->data = d;
        this->left = l;
        this->right = r;
    }
};

Node* insert(Node* root, int value);
bool isLeaf(Node* root);
void showTree(Node* root);

int main() {

    Node* t = new Node(6, NULL, NULL);
    cout << "Is it a leaf: " << isLeaf(t) << endl;
    insert(t, 5);
    insert(t, 90);
    insert(t, 21);
    showTree(t);


    return 0;
}

bool isLeaf(Node* root) {
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    return false;
}

/**
 * Inserts a node in a tree
 *
 * @param root
 *  Root Node
 * @param value
 *  Integer Value
 * @return
 *  The root node
 */
Node* insert(Node* root, int value) {
    if (root == NULL) {
        root = new Node(value, NULL, NULL);
    } else if (isLeaf(root)) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void showTree(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        showTree(root->left);
        showTree(root->right);
    }

}
