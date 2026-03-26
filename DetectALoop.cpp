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
//Brute force..
bool detectAloop(Node* head){
    Node* temp=head;
    map<Node*,int> mpp;
    while(temp!=NULL){
        if(mpp.count(temp)) return true;
        mpp[temp]=1;
        temp=temp->next;
    }
    return false;
}
//Optimal Approach 
bool detectALoo(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}