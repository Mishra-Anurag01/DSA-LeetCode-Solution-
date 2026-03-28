#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
};
//Brute..
bool isPalindrome(Node* head){
    stack<int> st;
    Node* temp=head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->data!=st.top()) return false;
        else{
            temp=temp->next;
            st.pop();
        }
    }
    return true;
}
//Optimal..
Node* reverse(Node* head){
    Node* temp=head;
    Node* prev=NULL;
    while(temp->next!=NULL){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
bool IsPalindrome(Node* head){
Node* slow=head;
Node* fast=head;
while(fast->next!=NULL && fast->next->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        Node* newHead=slow->next;
        reverse(newHead);
        Node*first=head;
        Node* second=newHead;
        while(second!=NULL){
            if(first->data!=second->data) {
                reverse(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverse(newHead);
    }
}
return true;
}
