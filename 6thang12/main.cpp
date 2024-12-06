#include<bits/stdc++.h>
using namespace std;


struct Node {
    string value;
    Node* left;
    Node* right;
};

// Tạo node mới
Node* createNode(const string& val) {
    return new Node{val, nullptr, nullptr}; // Gán trực tiếp giá trị và con trỏ NULL
}

// Hàm để tạo toán tử với 2 toán hạng
Node* createOperatorNode(const string& op, Node* left, Node* right) {
    Node* node = createNode(op);
    node->left = left; // Gán toán hạng trái
    node->right = right; // Gán toán hạng phải
    return node;
}

// Duyệt pre order
void traversePreOrder(Node* root) {
    if (!root) return;
    cout << root->value << " ";
    traversePreOrder(root->left);
    traversePreOrder(root->right);
}

// Duyệt inorder
void traverseInOrder(Node* root) {
    if (!root) return;
    traverseInOrder(root->left);
    cout << root->value << " ";
    traverseInOrder(root->right);
}

// Duyệt post order
void traversePostOrder(Node* root) {
    if (!root) return;
    traversePostOrder(root->left);
    traversePostOrder(root->right);
    cout << root->value << " ";
}

// Xay dung cay bieu thuc
Node* constructExpressionTree() {
    // Các cây con được xây từ dưới lên
    Node* subExpr1 = createOperatorNode("^", createNode("e"), createNode("1/2")); // "e^(1/2)"
    Node* subExpr2 = createOperatorNode("*", createNode("d"), subExpr1); // "d * e^(1/2)"
    Node* subExpr3 = createOperatorNode("*", createNode("5"), createNode("b")); // "5 * b"
    Node* subExpr4 = createOperatorNode("/", subExpr3, createNode("c")); // "5 * b / c"
    Node* subExpr5 = createOperatorNode("^", createNode("c"), createNode("8")); // "c^8"
    Node* subExpr6 = createOperatorNode("+", createNode("a"), subExpr4); // "a + 5 * b / c"
    Node* subExpr7 = createOperatorNode("-", subExpr6, subExpr5); // "a + 5 * b / c - c^8"

    // Gốc
    return createOperatorNode("+", subExpr7, subExpr2); // "a + 5 * b / c - c^8 + d * e^(1/2)"
}

int main() {
    Node* root = constructExpressionTree();
    cout << "duyet pre-order: ";
    traversePreOrder(root);
    cout << "\n";

    cout << "duyet in-order: ";
    traverseInOrder(root);
    cout << "\n";

    cout << "duyet post-order: ";
    traversePostOrder(root);
    cout << "\n";

    return 0;
}
