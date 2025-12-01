#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
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

// Find minimum node (for delete)
Node* minNode(Node* root){
    while(root->left) root = root->left;
    return root;
}

// Delete a node
Node* deleteNode(Node* root, int key){
    if(root == NULL) return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Max depth
int maxDepth(Node* root){
    if(root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Min depth
int minDepth(Node* root){
    if(root == NULL) return 0;
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);

    cout << "Inorder before deletion: ";
    inorder(root);

    root = deleteNode(root, 5);

    cout << "\nInorder after deletion: ";
    inorder(root);

    cout << "\nMax Depth = " << maxDepth(root);
    cout << "\nMin Depth = " << minDepth(root);
}
