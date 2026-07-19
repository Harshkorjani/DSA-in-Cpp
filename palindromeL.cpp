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
            tail -> next = newnode;
            tail = tail -> next;
        }
        cin>>data;
    }
    return head;
}
int  print (Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return count;
}
bool helper(int arr[], int length){
    int s = 0;
    int e = length - 1;
    while(s<e){
        if(arr[s] != arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}
bool palindrome(Node* head, int length){
    if(head == NULL){
        return head;
    }
    Node* temp = head;
    int arr[1000];
    int i = 0;
    while(temp!= NULL){
        arr[i] = temp->data;
        temp = temp->next;
        i++;
    }
    bool ans = helper(arr,length);
    return ans;
}
int main(){
    Node* head = takeinput();
    int length = print(head);
    cout<<endl;
    bool ans = palindrome(head,length);
    cout<<ans;
}
