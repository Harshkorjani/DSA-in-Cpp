#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};
void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
node* takeinput_better(){
    int data; 
    cin>>data;
    node* head = NULL;
    node* tail = NULL;
    while(data != -1){
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;  
        }
        cin>>data;
    }
    return head;
}
int length(node* head){
    if(head == NULL){
        return 0;
    }
    int ans = length(head->next);
    ans = ans + 1;
    return ans;
}
node* takeinput(){
    int data; 
    cin>>data;
    node* head = NULL;
    while(data != -1){
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode;
        }
        else{
            node* temp = head;
            while(temp -> next != NULL){
                temp = temp->next;
            }  
            temp -> next = newNode;
        }
        cin>>data;
    }
    return head;
}
node* insertNode(node* head, int i, int data){
    node* NewNode = new node(data);
    int count = 0;
    node* temp = head;
    if(i == 0){
        NewNode -> next = head;
        head = NewNode;
        return head;
    }
    while(temp != NULL && count<i-1){
        count++;
        temp = temp->next;
    }
    if(temp != NULL){
        NewNode -> next = temp ->next;
        temp -> next = NewNode;
    }
    return head;
}
node* daleteNode(node* head, int pos){
    if(head == NULL){
        return NULL;
    }
    if(pos == 0){
        head = head ->next;
        return head;
    }
    node* temp = head;
    int count =  0;
    while(temp ->next != NULL && count<pos-1){
        count++;
        temp = temp ->next;
    }
    if(temp->next != NULL){
        node *a = temp ->next;
        node*b = a ->next;
        temp ->next = b;
        delete a;
    }
    return head;
}
node *swapNodes(node *head, int i, int j){
	if(head == NULL){
		return head;
	}
	node* temp1 = head;
	node* temp2 = head;
	for(int k = 0; k<i-1; k++){
		temp1 = temp1->next;
	}
	for(int k =0; k<j; k++){
		temp2 = temp2->next;
	}
	node* var = temp1->next;
	temp1->next = temp2;
	var->next = temp2->next;
	temp2->next = var;
	return head;
}
int main(){
    node* head = takeinput();
    int i, j;
    cin>>i;
    cin>>j;
    node*ans = swapNodes(head,i,j);
    /*int i;
    int data;
    cin>>i;
    cin>>data;
    head = insertNode(head,i,data);
    int ans = length(head);
    cout<<ans<<" "<<endl;*/
    print(head);
}