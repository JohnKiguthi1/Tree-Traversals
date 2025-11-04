#include <iostream>
#include <vector>

class Node {
public:
    int val;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int v) {
        val = v;
    }
};

Node* insert(Node* root, int v) {
    if (!root) {
        return new Node(v);
    }

    if (v < root->val) {
        root->left = insert(root->left, v);
    }
    else {
        root->right = insert(root->right, v);
    }

    return root;
}

void inO(Node* node) {
    if (!node) return;
    inO(node->left);
    std::cout << node->val << ' ';
    inO(node->right);
}

void postO(Node* node) {
    if (!node) return;
    postO(node->left);
    postO(node->right);
    std::cout << node->val << ' ';
}


int main() {
    std::vector<int> values = { 4, 2, 6, 1, 3, 5, 7 };
    Node* root = nullptr;
    for (int v : values) root = insert(root, v);

    std::cout << "In-order: ";
    inO(root);
    std::cout << std::endl;

    std::cout << "Post-order: ";
    postO(root);
    std::cout << std::endl;
    return 0;
}