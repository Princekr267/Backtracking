#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
            next=NULL;
        }
    }
};
class List{
public:
    Node* head;
    Node* tail;
    List(){
        head=NULL;
        tail=NULL;
    }
    ~List(){
        if(head!=NULL){
            delete head;
            head=NULL;
        }
    }
    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        } else{
            newNode->next=head;
            head=newNode;
        }
    }
    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        } else{
            tail->next=newNode;
            tail=newNode;
        }
      //  newNode->next=NULL;
    }
    void pop_front(){
        if(head==NULL){
            cout<<"List is empty\n";
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;

    }
    void printList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
};
void printLL(Node* head){
    Node* temp=head;
    while (temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
Node* splitAtMid(Node* head){
    Node* slow=head;
    Node* fast=head;
    Node* prev=NULL;
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev!=NULL){
        prev->next=NULL;  //split at Middle
    }
    return slow;  //slow=rightHead
}
/* Node* merge(Node* leftHead, Node* rightHead){
    List ans;
    Node* i=leftHead;
    Node* j=rightHead;
    while(i!=NULL && j!=NULL){
        if(i->data<=j->data){
            ans.push_back(i->data);
            i=i->next;
        } else{
            ans.push_back(j->data);
            j=j->next;
        }
    }
    while(i!=NULL){
        ans.push_back(i->data);
        i=i->next;
    }
    while(j!=NULL){
        ans.push_back(j->data);
        j=j->next;
    }
    return ans.head;
} */
Node* merge(Node* leftHead, Node* rightHead){
    List ans;
    Node* i=leftHead;
    Node* j=rightHead;
    while(i!=NULL && j!=NULL){
        if(i->data<=j->data){
            ans.push_back(i->data);
            i=i->next;
        } else{
            ans.push_back(j->data);
            j=j->next;
        }
    }
    while(i!=NULL){
        ans.push_back(i->data);
        i=i->next;
    }
    while(j!=NULL){
        ans.push_back(j->data);
        j=j->next;
    }
    return ans.head;
}

Node* mergeSort(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* rightHead=splitAtMid(head);
    Node* left=mergeSort(head);
    Node* right=mergeSort(rightHead);
    return merge(left, right);
}
int main(){
    List ll;
    // ll.push_front(2);
    // ll.push_front(1);
    // ll.push_front(3);
    // ll.push_front(4);
    // //ll.pop_front();
    // ll.push_back(6);
    // ll.push_back(7);
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    printLL(ll.head);
    ll.head=mergeSort(ll.head);
    printLL(ll.head);
    return 0;
}