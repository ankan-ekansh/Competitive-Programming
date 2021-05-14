#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        (*this).data = data;
        next = NULL;
    }
};
void printlist(Node* node){
    while(node != NULL){
        // cout << node->data << " ";
        // node = node->next;
        cout << (*node).data << " ";
        node = (*node).next;
    }
}
int main(){
    Node *node = new Node(1);
    Node *node2 = new Node(2);
    (*node).next = node2;
    printlist(node);
}