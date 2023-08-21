#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Node {
public: 
    char name;
    Node* left;
    Node* right;
    Node() { left = NULL; right = NULL;}
};

class Tree {
public:
    Node* root;
    Tree() { root = NULL; }
    Node* Search(Node* root, char c) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* cur = q.front();
            if(cur->name == c) return cur;
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return NULL;
    } 
    void preorder(Node* root) {
        if(root != NULL) cout << root->name;
        if(root->left) preorder(root->left);
        if(root->right) preorder(root->right);
    }
    void inorder(Node* root) {
        if(root->left) inorder(root->left);
        if(root) cout << root->name;
        if(root->right) inorder(root->right);
    }
    void postorder(Node* root) {
        if(root->left) postorder(root->left);
        if(root->right) postorder(root->right);
        if(root) cout << root->name;
    }
};

int main(void) {
    Tree* t = new Tree();
    int n;
    cin >> n;
    while(n--) {
        char n, l, r;
        cin >> n >> l >> r;
        Node* node;
        if(t->root == NULL) {
            node = new Node();
            node->name = n;
            t->root = node;
        }
        else 
            node = t->Search(t->root, n);
        if(l != '.') {
            Node* newnode = new Node();
            newnode->name = l;
            node->left = newnode;
        }
        if(r != '.') {
            Node* newnode = new Node();
            newnode->name = r;
            node->right = newnode;
        }
    }
    t->preorder(t->root);
    cout << "\n";
    t->inorder(t->root);
    cout << "\n";
    t->postorder(t->root);

    return 0;
}
