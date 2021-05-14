#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
    Node(int x){
        this->data = x;
        this->next = NULL;
    }
};
int length(struct Node *head){          // length
    int l = 0;
    while(head){
        head = head->next;
        l++;
    }
    return l;
}
void print(struct Node *head){          // print
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}
void search(struct Node *head, int x){      // search
    bool found = false;
    int pos = 0;
    while(head && !found){
        if(head->data == x){
            found = true;
            break;
        }
        head = head->next;
        pos++;
    }
    if(found){
        cout << "Found " << x << " at position " << pos << "\n";
    }
    else{
        cout << x << " not found\n";
    }
}
void insert(struct Node **head){  // insert x at end
    int x;
    cout << "Enter data to insert at end\n";
    cin >> x;
    struct Node *ele = new Node(x);
    struct Node *tmp = *head;
    if(*head == NULL){
        *head = ele;
        return;
    }
    while(tmp->next){
        tmp = tmp->next;
    }
    tmp->next = ele;
}
void insert(struct Node **head, int pos){       // insert at pos
    int x;
    cout << "Enter data to insert at " << pos << "\n";
    cin >> x;
    if(*head == NULL){
        if(pos != 0){
            cout << "Not enough elements\n";
            return;
        }
        *head = new Node(x);
        return;
    }
    int cnt = 1;
    struct Node *tmp = *head;
    while(cnt < pos && head){
        cnt++;
        tmp = tmp->next;
    }
    if(cnt < pos){
        cout << "Not enough elements\n";
        return;
    }
    struct Node *tmp1 = new Node(x);
    struct Node *tmp2 = tmp->next;
    tmp->next = tmp1;
    tmp1->next = tmp2;
}
void deletell(struct Node* head){     // delete from end
    if(head == NULL){
        cout << "Linked list empty, insert elements first\n";
        return;
    }
    while(head->next){
        head = head->next;
    }
    delete(head->next);
    head->next = NULL;
}
void deletell(struct Node* head, int pos){      // delete at pos
    if(head == NULL){
        cout << "Linked list empty, insert elements first\n";
        return;
    }
    int cnt = 1;
    while(head && cnt < pos){
        head = head->next;
        cnt++;
    }
    if(cnt < pos){
        cout << "Not enough elements\n";
        return;
    }
    struct Node *tmp = head->next;
    head->next = head->next->next;
    delete(tmp);
}
void deletellf(struct Node **head){     // delete from front
    if(*head == NULL){
        cout << "Linked list empty, insert elements first\n";
        return;
    }
    struct Node *tmp = *head;
    *head = (*head) -> next;
    delete(tmp);
}
int main(){
    struct Node *head;
    head = NULL;
    int ch;
    while(1){
        cout << "Enter 1 for insert at end, 2 for insert at pos, 3 for printing 4 for searching, 5 for finding length, 6 for deleting from end, 7 for deleting at pos, 8 for deleting at front, 9 to exit program\n";
        cin >> ch;
        int p;
        switch(ch){
            case 1:
                insert(&head);
                break;
            case 2:
                cout << "Enter position to insert\n";
                cin >> p;
                insert(&head, p);
                break;
            case 3:
                print(head);
                break;
            case 4:
                cout << "Enter element to search\n";
                cin >> p;
                search(head, p);
                break;
            case 5:
                cout << "Length of linked list is " << length(head) << "\n";
                break;
            case 6:
                deletell(head);
                break;
            case 7:
                cout << "Enter position to delete\n";
                cin >> p;
                deletell(head, p);
                break;
            case 8:
                deletellf(&head);
                break;
            case 9:
                return 0;
        }
    }
    return 0;
}