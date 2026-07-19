#include<vector>
#include<queue>
#include<climits>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
template<typename T>
class Binarytree{
    public:
    T data;
    Binarytree<T>*left;
    Binarytree<T>*right;

    Binarytree(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~Binarytree(){
        delete left;
        delete right;
    }
};
template <typename T>
class Node{
    public:
    T data;
    Node<T>*next;
    Node(T data){
        this->data = data;
        this->next == NULL;
    }
};
void printTree(Binarytree<int>*root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left != NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}
void printTreelevelwise(Binarytree<int>*root){
    if(root == NULL){
        return;
    }
    queue<Binarytree<int>*> pending;
    pending.push(root);
    while(pending.size() != 0){
        Binarytree<int>*front = pending.front();
        cout<<front->data<<":";
        pending.pop();
        if(front->left != NULL){
            cout<<"L:"<<front->left->data<<",";
            pending.push(front->left);
        }
        if(front->right != NULL){
            cout<<"R:"<<front->right->data;
            pending.push(front->right);
        }
        cout<<endl;
    }
}
Binarytree<int>*takeinput(){
    int rootdata;
    cout<<"Enter data"<<endl;
    cin>>rootdata;
    if(rootdata == -1){
        return NULL;
    }
    Binarytree<int>*root = new Binarytree<int>(rootdata);
    Binarytree<int>*leftchild = takeinput();
    Binarytree<int>*rightchild = takeinput();
    root->left = leftchild;
    root->right = rightchild;
    return root;
}
Binarytree<int>*takeinputlevelwise(){
    int rootdata;
    cout<<"Enter root data"<<endl;
    cin>>rootdata;
    if(rootdata == -1){
        return NULL;
    }
    Binarytree<int>* root = new Binarytree<int>(rootdata);
    queue<Binarytree<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size() != 0){
        Binarytree<int>*front = pendingnodes.front();
        pendingnodes.pop();
        int leftchilddata;
        cout<<"Enter left child of "<<front->data<<endl;
        cin>>leftchilddata;
        if(leftchilddata != -1){
            Binarytree<int>*child = new Binarytree<int>(leftchilddata);
            front->left = child;
            pendingnodes.push(child);
        }
        int rightchilddata;
        cout<<"Enter right child of "<<front->data<<endl;
        cin>>rightchilddata;
        if(rightchilddata != -1){
            Binarytree<int>*child = new Binarytree<int>(rightchilddata);
            front->right = child;
            pendingnodes.push(child);
        }
    }
    return root;
}
//1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int numNodes(Binarytree<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right); 
}
bool isNodePresent(Binarytree<int>*root,int x){
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    bool ans1 = isNodePresent(root->left,x);
    bool ans2 = isNodePresent(root->right,x);
    if(ans1){
        return true;
    }
    else if(ans2){
        return true;
    }
    else{
        return false;
    }
}
Binarytree<int>* helper(Binarytree<int>* root){
    if(root == NULL){
        return NULL;
    }
    Binarytree<int>* ans1 = helper(root->left);
    Binarytree<int>* ans2 = helper(root->right);
    root->left = ans2;
    root->right = ans1;
    return root;
}
void MirrorBinaryTree(Binarytree<int>* root){
    helper(root);
}
pair<int,int>getMinAndMax(Binarytree<int>* root){
    if(root == NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int,int> leftans = getMinAndMax(root->left);
    pair<int,int> rightans = getMinAndMax(root->right);
    int leftmin = leftans.first;
    int leftmax = leftans.second;
    int rightmin = rightans.first;
    int rightmax = rightans.second;

    int minimum;
    int maximum = max(root->data,max(leftmax,rightmax)); 
    if(root->left == NULL && root->right == NULL){
        minimum = root->data;
    }
    else if(root->left == NULL){
        minimum = min(root->data,rightmin);
    }
    else if(root->right == NULL){
        minimum = min(root->data,leftmin);
    }
    else{
        minimum = min(root->data,min(leftmin,rightmin));
    }
    pair<int,int> p;
    p.first = minimum;
    p.second = maximum;
    return p;
}
int getSum(Binarytree<int>* root){
    if(root == NULL){
        return 0;
    }
    int sum = 0;
    int ans1 = getSum(root->left);
    int ans2 = getSum(root->right);
    sum = root->data + ans1 + ans2;
    return sum;
}
Binarytree<int>* removeleafnode(Binarytree<int>*root){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }
    root->left = removeleafnode(root->left);
    root->right = removeleafnode(root->right);
    return root;
}
int height(Binarytree<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
bool isBalanced(Binarytree<int>* root){
    if(root == NULL){
        return true;
    }
    int hl = height(root->left);
    int hr = height(root->right);
    if(abs(hl - hr)>1){
        return false;
    }
    bool a = isBalanced(root->left);
    bool b = isBalanced(root->right);
    if(a == true && b == true){
        return true;
    }
    return false;
}
void printlevelwise(Binarytree<int>*root){
    if(root == NULL){
        return;
    }
    queue<Binarytree<int>*>pending;
    pending.push(root);
    pending.push(NULL);
    while(pending.size() != 0){
        Binarytree<int>* front = pending.front();
        pending.pop();
        if(front == NULL){
            if(pending.size() == 0){
                return;
            }
            cout<<endl;
            pending.push(NULL);
            continue;
        }
        cout<<front->data<<" ";
        if(front->left != NULL){
            pending.push(front->left);
        }
        if(front->right != NULL){
            pending.push(front->right);
        }
    }
}
vector<Node<int>*> printLevelwiseLL(Binarytree<int>* root){
    if(root == NULL){
        vector<Node<int>*>v;
        v.push_back(NULL);
        return v;
    }
    queue<Binarytree<int>*>pending;
    vector<Node<int>*>v;
    pending.push(root);
    pending.push(NULL);
    while(!pending.front() == NULL){
        Node<int>*head = NULL;
        Node<int>* tail = NULL;
        while(!pending.front() == NULL){
            Binarytree<int>* front = pending.front();
            pending.pop();
            Node<int>* newnode = new Node<int>(front->data);
            if(head == NULL && tail == NULL){
                head = newnode;
                tail = newnode;
            }
            else{
                tail->next = newnode;
                tail = newnode;
            }
            if(front->left != NULL){
                pending.push(front->left);
            }
            if(front->right != NULL){
                pending.push(front->right);
            }
        }
        v.push_back(head);
        pending.pop();
        pending.push(NULL);
    }
    return v;
}
int maxValue(Binarytree<int>* root){
    if(root == NULL){
        return INT_MIN;
    }
    int leftmax = maxValue(root->left);
    int rightmax = maxValue(root->right);
    return max(root->data,max(leftmax,rightmax));
}
int minValue(Binarytree<int>* root){
    if(root == NULL){
        return INT_MAX;
    }
    int leftmin = minValue(root->left);
    int rightmin = minValue(root->right);
    return min(root->data,min(leftmin,rightmin));
}
bool isBST(Binarytree<int>*root){
    if(root == NULL){
        return true;
    }
    if((root->data >maxValue(root->left)) && (root->data <= minValue(root->right))){
        bool ans1 = isBST(root->left);
        bool ans2 = isBST(root->right);
        if(ans1 && ans2){
            return true;
        }
    }
    return false;
}
Node<int>* constructLL(Binarytree<int>* root){
    if(root == NULL){
        return NULL;
    }
    Node<int>* node = new Node<int>(root->data);
    Node<int>* lefthead = constructLL(root->left);
    Node<int>* righthead = constructLL(root->right);
    if(lefthead == NULL && righthead + NULL){
        return node;
    }
    else if(lefthead == NULL){
        node->next = righthead;
        return node;
    }
    else if(righthead == NULL){
        Node<int>* temp = lefthead;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = node;
    }
    else{
        node->next = righthead;
        Node<int>* temp = lefthead;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next =node;
    }
    return lefthead;
}
vector<int>* RootToNodePath(Binarytree<int>* root,int data){
    if(root == NULL){
        return NULL;
    }
    if(root->data == data){
        vector<int>*output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    else if(root->data > data){
        vector<int>* leftoutput = RootToNodePath(root->left,data);
        if(leftoutput != NULL){
            leftoutput->push_back(root->data);
            return leftoutput;
        }
    }
    else if(root->data < data){
        vector<int>* rightoutput = RootToNodePath(root->right,data);
        if(rightoutput != NULL){
            rightoutput->push_back(root->data);
            return rightoutput;
        }
    }
}
void convertToArray(Binarytree<int>* root, vector<int>& output){
    if(root == NULL){
        return;
    }
    output.push_back(root->data);
    convertToArray(root->left,output);
    convertToArray(root->right,output);
}
void pairSum(Binarytree<int>* root,int sum){
    vector<int> output;
    convertToArray(root,output);
    sort(output.begin(),output.end());
    int i = 0;
    int j = output.size() - 1;
    while(i < j){
        if(output[i] + output[j] == sum){
            cout<<output[i]<<" "<<output[j]<<endl;
            i++;
            j--;
        }
        else if(output[i] + output[j] < sum){
            i++;
        }
        else{
            j--;
        }
    }
}
void insertDuplicateNode(Binarytree<int>* root){
    if(root == NULL){
        return;
    }
    Binarytree<int>* newnode = new Binarytree<int>(root->data);
    Binarytree<int>* temp = root->left;
    root->left = newnode;
    newnode->left = temp;
    insertDuplicateNode(temp);
    insertDuplicateNode(root->right);
}
int main(){
    Binarytree<int>*root = takeinputlevelwise();
    printTreelevelwise(root); 
    /*cout<<endl;
    int ans = numNodes(root);
    cout<<ans<<endl;
    int x;
    cin>>x;
    bool ans = isNodePresent(root,x);
    cout<<ans<<endl;
    MirrorBinaryTree(root);
    printTreelevelwise(root);*/
    return 0;
}