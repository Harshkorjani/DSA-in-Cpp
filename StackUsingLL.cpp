#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
class Stack{
    Node* head;
    int size;
    public:
    Stack(){
        head = NULL;
        size = 0;
    }
    int getsize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void push(int element){
        Node* newnode = new Node(element);
        Node* temp = head;
        head = newnode;
        head->next = temp;
        size++;
    }
    int pop(){
        if(head == NULL){
            return -1;
        }
        Node*temp = head;
        head = head->next;
        int ans = temp->data;
        delete temp;
        size--;
        return ans;
    }
    int top(){
        if(head == NULL){
            return -1;
        }
        int ans = head->data;
        return ans;
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.pop()<<" "<<endl;
    cout<<s.pop()<<" "<<endl;
    cout<<s.pop()<<" "<<endl;
    cout<<s.getsize()<<" "<<endl;
    cout<<s.top()<<" "<<endl;
}
