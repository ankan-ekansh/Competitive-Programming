#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};
int dfs(Node *node, int *ans){
    if(!node){
        return 0;
    }
    int leftsum = dfs(node->left, ans);
    int rightsum = dfs(node->right, ans);
    if(leftsum == rightsum && leftsum){
        (*ans)++;
    }
    return node->data + leftsum + rightsum;
}
int main(){

    Node *root = new Node(1);
    root->left = new Node(1);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(1);
    int ans = 0;
    dfs(root, &ans);
    cout << ans << "\n";
    return 0;
}