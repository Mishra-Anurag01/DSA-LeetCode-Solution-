#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  ListNode* reverse(ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode* newhead=reverse(head->next);
    ListNode* front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
  }
  //Brute
  ListNode* Add1toNumber(ListNode* head){
    head=reverse(head);
    ListNode* temp=head;
    int carry=1;
    while(temp!=NULL){
        temp->val=temp->val=carry;
        if(temp->val<10){
            carry=0;
            break;
        }
        else{
            temp->val=0;
            carry=1;
        }
        temp=temp->next;
    }
    if(carry==1){
        ListNode* newNode= new ListNode(1);
        head=reverse(head);
        newNode->next=head;
        return newNode;
    }
    head=reverse(head);
    return head;
  }
  //Optimal..
  int helper(ListNode* temp){
    if(temp==NULL) return 1;
    int carry=helper(temp->next);
    temp->val+=carry;
    if(temp->val<10){
        return 0;
    }
    temp->val=0;
    return 1;
  }
  ListNode* Add1ToNumber(ListNode* head){
    int carry=helper(head);
    if(carry==1){
        ListNode* newNode=new ListNode(1);
        newNode->next=head;
        return newNode;
    }
    return head;
  }
  