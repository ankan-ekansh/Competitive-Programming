#include<iostream>
#include<map>
#include<queue>
// #include<algorithm>
// #include<climits>
using namespace std;
struct Node{
    int data;
    int hd;
    Node *left, *right;
    Node(int data){
        this->data = data;
        this->hd = INT32_MAX;
        this->left = this->right = NULL;
    }
};
void bottomviewmap(Node *root, int currDepth, int horiDist, map<int, pair<int, int>> &m){
    if(!root){
        return;
    }
    if(m.find(horiDist) == m.end()){
        m[horiDist] = {root->data, currDepth};
    }
    else{
        if(m[horiDist].second <= currDepth){
            m[horiDist] = {root->data, currDepth};
        }
    }
    bottomviewmap(root->left, currDepth+1, horiDist-1, m);
    bottomviewmap(root->right, currDepth+1, horiDist+1, m);
}
void bottomview(Node *root){
    if(!root){
        return;
    }
    int hd = 0;
    map<int, int> m;
    queue<Node*> q;
    root->hd = hd;
    q.push(root);
    while(!q.empty()){
        Node *tmp = q.front();
        q.pop();
        hd = tmp->hd;
        m[hd] = tmp->data;
        if(tmp->left){
            tmp->left->hd = hd-1;
            q.push(tmp->left);
        }
        if(tmp->right){
            tmp->right->hd = hd+1;
            q.push(tmp->right);
        }
    }
}