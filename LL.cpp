#include<bits/stdc++.h>
using namespace std;
class LLnode{
    public:
    LLnode *next;
    int val;

    LLnode(int val){
        this->val = val;
        this->next = NULL;
    }
};
void print(LLnode* head){
    while(head->next != NULL){
        cout<<head->val<<" "<<head->val;
        cout<<" ";
        head = head->next;
    }
}
int main(){
    LLnode *n1 = new LLnode(1);
    LLnode *n2 = new LLnode(2);
    LLnode *n3 = new LLnode(3);
    LLnode *n4 = new LLnode(4);
    LLnode *n5 = new LLnode(5);
    LLnode *n6 = new LLnode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    print(n1);
    return 0;
}
