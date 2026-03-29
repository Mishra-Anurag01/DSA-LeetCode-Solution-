#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  //Brute..
  ListNode* deleteTheMiddleNode(ListNode* head){
    if(head==NULL || head->next==NULL) return NULL;
    ListNode* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    int res=cnt/2;
    temp=head;
    while(temp!=NULL){
        res--;
        if(res==0){
            ListNode* middle=temp->next;
            temp->next=temp->next->next;
            delete middle;
            break;
        }
        temp=temp->next;
    }
    return head;
  }
  //Optimal..
  ListNode* DeleteTheMiddleNode(ListNode* head){
    if(head==NULL || head->next!=NULL){
        return NULL;
    }
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* delNode=slow->next;
    slow->next=slow->next->next;
    delete delNode;
    return head;
  }
  