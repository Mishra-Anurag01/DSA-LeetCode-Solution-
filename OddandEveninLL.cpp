#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  // Brute..
  ListNode* OddEvenInLL(ListNode* head){
    vector<int> arr;
    ListNode* temp=head;
    while(temp!=NULL){
        arr.push_back(temp->val);
        temp=temp->next;
    }
    if(temp) arr.push_back(temp->val);
    temp=head->next;
    while (temp!=NULL && temp->next!=NULL)
    {
        arr.push_back(temp->val);
        temp=temp->next;
    }
    if(temp) arr.push_back(temp->val);
    int i=0;
    temp=head;
    while(temp!=NULL){
        temp->val=arr[i];
        i++;
        temp=temp->next;
    }
    return head;
  }
  //Optimal..
  ListNode* OddAndEvenInLL(ListNode* head){
    if(head==NULL || head->next == NULL) return head;
    ListNode* even=head->next;
    ListNode* odd=head;
    ListNode* evenHead= head->next;
    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even= even->next->next;
    }
    odd->next=evenHead;
    return head;
  }
  