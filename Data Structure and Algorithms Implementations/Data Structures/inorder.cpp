#include<iostream>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};
void inorder(Node *node){
    if(!node){
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
void inorderiter(Node *node){
    if(!node){
        return;
    }
    stack<Node*> s;
    // s.push(node);
    Node *cur = node;
    while(1){
        while(cur){
            s.push(cur);
            cur = cur->left;
        }
        if(s.empty()){
            break;
        }
        cur = s.top();
        s.pop();
        cout << cur->data << " ";
        cur = cur->right;
    }
}
int main(){
    Node* root = new Node(10); 
    root->left = new Node(20); 
    root->right = new Node(30); 
    root->left->left = new Node(40); 
    root->left->left->left = new Node(70); 
    root->left->right = new Node(50); 
    root->right->left = new Node(60); 
    root->left->left->right = new Node(80); 

    inorder(root);
    cout << '\n';
    inorderiter(root);
}