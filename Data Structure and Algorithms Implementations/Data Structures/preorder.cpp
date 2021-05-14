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
void preorder(Node *node){
    if(!node){
        return;
    }
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}
void preorderiter(Node *node){
    if(!node){
        return;
    }
    stack<Node*> s;
    s.push(node);
    Node *cur = node;
    while(!s.empty()){
        cur = s.top();
        s.pop();
        cout << cur->data << " ";
        if(cur->right){
            s.push(cur->right);
        }
        if(cur->left){
            s.push(cur->left);
        }
    }
}
void postorder(Node *node){
    if(!node){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}
void postorderiter(Node *node){
    if(!node){
        return;
    }
    stack<Node*> s;
    stack<Node*> ans;
    s.push(node);
    Node *cur = node;
    while(!s.empty()){
        cur = s.top();
        s.pop();
        // cout << cur->data << " ";
        ans.push(cur);
        if(cur->left){
            s.push(cur->left);
        }
        if(cur->right){
            s.push(cur->right);
        }
    }
    while(!ans.empty()){
        cout << ans.top()->data << " ";
        ans.pop();
    }
}
int main(){
    // Node* root = new Node(10); 
    // root->left = new Node(20); 
    // root->right = new Node(30); 
    // root->left->left = new Node(40); 
    // root->left->left->left = new Node(70); 
    // root->left->right = new Node(50); 
    // root->right->left = new Node(60); 
    // root->left->left->right = new Node(80); 

    Node* root = NULL; 
    root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 

    postorder(root);
    cout << '\n';
    postorderiter(root);
}