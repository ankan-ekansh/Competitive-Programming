#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *left, *right;
    Node(int d){
        this->data = d;
        this->left = this->right = NULL;
    }
};
struct Node* insert(struct Node* root, int val){
    if(!root){
        struct Node *node = new Node(val);
        return node;
    }
    if(val > root->data){
        root->right = insert(root->right, val);
    }
    else{
        root->left = insert(root->left, val);
    }
    return root;
}
void inorder(struct Node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout << root->data << "\n";
    inorder(root->right);
}
void preorder(struct Node* root){
    if(!root){
        return;
    }
    cout << root->data << "\n";
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node* root){
    if(!root){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "\n";
}
void search(struct Node* root, int val){
    struct Node* cur = root;
    if(!cur){
        cout << "BST is empty\n";
        return;
    }
    while(cur){
        if(cur->data == val){
            cout << val << " is present in the BST\n";
            return;
        }
        if(val < cur->data){
            cur = cur->left;
        }
        else{
            cur = cur->right;
        }
    }
    cout << val << " not found in the BST\n";
}
struct Node* inorderSuccessor(struct Node* node){
    struct Node* cur = node;
    while(cur && cur->left){
        cur = cur->left;
    }
    return cur;
}
struct Node* deleteNode(struct Node* root, int val){
    if(!root){
        cout << "BST is empty\n";
        return root;
    }
    if(val < root->data){
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->data){
        root->right = deleteNode(root->right, val);
    }
    else{
        if(!root->left){
            struct Node* tmp = root->right;
            delete(root);
            return tmp;
        }
        else if(!root->right){
            struct Node* tmp = root->left;
            delete(root);
            return tmp;
        }
        struct Node* tmp = inorderSuccessor(root->right);
        root->data = tmp->data;
        root->right = deleteNode(root->right, tmp->data);
    }
    return root;
}
int main(){

    struct Node* root = NULL;
    int val;
    int ch;
    while(1){
        cout << "Enter 1 to insert node, 2 to search a key, 3 to delete a key, 4 to do inorder traversal, 5 to do preorder traversal, 6 to do postorder traversal, 7 to exit\n";
        cin >> ch;
        switch(ch){
            case 1:
                cout << "Enter value to insert in BST\n";
                cin >> val;
                root = insert(root, val);
                break;
            case 2:
                cout << "Enter value of key to search in BST\n";
                cin >> val;
                search(root, val);
                break;
            case 3:
                cout << "Enter key to delete from BST\n";
                cin >> val;
                root = deleteNode(root, val);
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                preorder(root);
                break;
            case 6:
                postorder(root);
                break;
            case 7:
                exit(0);
            default:
                cout << "Incorrect choice, please enter correct choice again\n";
        }
    }
    return 0;
}