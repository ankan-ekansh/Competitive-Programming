#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};
void leftViewUtil(Node *root, int level, int *maxlevel){
    if(!root){
        return;
    }
    if(level > *maxlevel){
        cout << root->data << " ";
        *maxlevel = level;
    }
    leftViewUtil(root->left, level+1, maxlevel);
    leftViewUtil(root->right, level+1, maxlevel);

    // recur to right subtree first for right view
}
void leftView(Node *root)
{
    int maxlevel = 0;
   leftViewUtil(root, 1, &maxlevel);
}
void leftViewLevelOrder(Node *root){
    if(!root){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        for(int i=0;i<q.size();i++){
            Node *tmp = q.front();
            q.pop();
            if(i == 0){
                cout << tmp->data << " ";       // first element in each level in level order traversal
            }
            // last element of queue to be printed for right view
            if(tmp->left){
                q.push(tmp->left);
            }
            if(tmp->right){
                q.push(tmp->right);
            }
        }
    }
}