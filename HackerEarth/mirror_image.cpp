#include<bits/stdc++.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node *newnode(int d){
    struct node *temp = new struct node;
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// void preordertraverse(struct node *n){
//     if(n == NULL){
//         return;
//     }
//     std::cout<<n->data<<"\n";
//     preordertraverse(n->left);
//     preordertraverse(n->right);
// }

int recurse(int target, struct node *l, struct node *r){
    if(l == NULL || r == NULL){
        return -1;
    }
    if(l->data == target){
        return r->data;
    }
    if(r->data == target){
        return l->data;
    }
    int val = recurse(target, l->left, r->right);
    if(val > 0){
        return val;
    }
    return recurse(target, l->right, r->left);
}

int findmirror(struct node *n, int target){
    if(n == NULL){
        return -1;
    }
    if(n->data == target){
        return target;
    }
    else{
        return recurse(target, n->left, n->right);
    }
}

using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,q;
    cin>>n>>q;
    map<int, struct node *> m;
    int t = n-1;
    struct node *root = newnode(1);
    m[1]=root;
    while(t--){
        int p, c;
        char pos;
        cin>>p>>c>>pos;
        m[c]=newnode(c);
        if(pos == 'L'){
            m[p]->left = m[c];
        }
        else{
            m[p]->right = m[c];
        }
    }
    //preordertraverse(root);
    t=q;
    while(t--){
        int target;
        cin>>target;
        cout<<findmirror(root, target)<<"\n";
    }
    // for(auto i = m.begin();i!=m.end();i++){
    //     cout<<((*i).second)->data<<"\n";
    // }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}