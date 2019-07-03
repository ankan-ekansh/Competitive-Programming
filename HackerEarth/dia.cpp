#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node* right;
};
struct node *newnode(int element){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = element;
    temp->left=NULL;
    temp->right=NULL;
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
struct node *copynode(struct node *n){
    struct node *temp = (struct node*)calloc(1,sizeof(struct node));
    temp->data = n->data;
    temp->left = n->left;
    temp->right = n->right;
    return temp;
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
    int z=t;
    int x;
    cin>>x;
    struct node *root = newnode(x);
    while(t--){
        struct node *temproot = root;
        string s;
        cin>>s;
        for(auto i=s.begin();i!=s.end();i++){
            //cout<<*i<<"\n";
            if(*i == 'L'){
                if(temproot->left == NULL){
                    temproot->left = newnode(0);
                }
                temproot = temproot->left;
            }
            else if(*i == 'R'){
                if(temproot->right == NULL){
                    temproot->right = newnode(0);
                }
                temproot = temproot->right;
            }
        }
        //cout<<"\n";
        int e;
        cin>>e;
        temproot->data=e;
    }
    while(z--){
        printnode(root);
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

