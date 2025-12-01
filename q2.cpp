#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d){ data=d; left=right=NULL; }
};

Node* insert(Node* root, int key){
    if(root == NULL) return new Node(key);
    if(key < root->data) root->left = insert(root->left, key);
    else if(key > root->data) root->right = insert(root->right, key);
    return root;
}

// Recursive search
Node* searchRec(Node* root, int key){
    if(root == NULL || root->data == key) return root;
    if(key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

// Iterative search
Node* searchIter(Node* root, int key){
    while(root){
        if(key == root->data) return root;
        if(key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}
