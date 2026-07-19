#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        this ->next = NULL;
    } 
};
void print(node *head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    //Statically;
    node n1(1);
    node *head = &n1;
    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);
    node n6(17);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    print(head);
    //Dynamically
    node * N1 = new node(11);
    node * head1 = N1;
    node * N2 = new node(12);
    node * N3 = new node(13);
    node * N4 = new node(14);

    N1 -> next = N2;
    N2 -> next = N3;
    N3 ->next = N4;
    
    print (head1);

}