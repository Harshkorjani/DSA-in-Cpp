#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
Node* takeinput(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
        Node* newnode = new Node(data);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
        cin>>data;
    }
    return head;
}
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
void reverseLL(Node* head){
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        cout<<head->data<<" ";
        return;
    }
    Node* temp = head->next;
    head->next = NULL;
    Node* var;
    while(temp != NULL){
        var = temp->next;
        temp->next = head;
        head = temp;
        temp = var;
    }
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main(){
    Node* head = takeinput();
    print(head);
    cout<<endl;
    reverseLL(head);
    return 0;
}
