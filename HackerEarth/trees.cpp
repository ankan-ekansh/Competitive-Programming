#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int element){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=element;
    temp->left=temp->right=NULL;
    return temp;
}
void printnode(struct node *n){
    cout<<n->data<<"\n";
    if(n->left == NULL && n->right == NULL){
        return;
    }
    else if(n->left != NULL && n->right == NULL){
        printnode(n->left);
    }
    else if(n->left == NULL && n->right != NULL){
        printnode(n->right);
    }
    else{
        printnode(n->left);
        printnode(n->right);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        struct node *root = newnode(1);
        root->left = newnode(2);
        root->right = newnode(3);
        root->left->left = newnode(4);
        root->left->right = newnode(5);
        root->right->left = newnode(6);
        root->right->right = newnode(7);
        printnode(root);
        /*
                            1
                2                       3
            4       5                6      7
        */
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}