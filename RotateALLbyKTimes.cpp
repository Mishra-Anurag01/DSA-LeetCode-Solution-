#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
ListNode* findNthNode(ListNode* temp,int k){
    int cnt=1;
    while(temp!=NULL){
        if(cnt==k) return temp;
        cnt++;
        temp=temp->next;
    }
    return temp;
}
ListNode* rotateALLbykTimes(ListNode* head,int k){
    int len=1;
    ListNode* tail=head;
    while(tail!=NULL || tail->next!=NULL){
        len++;
        tail=tail->next;
    }
    if(k%len==0) return head;
    k=k%len;
    tail->next=head;
    ListNode* newNode=findNthNode(head,k);
    head=newNode->next;
    newNode->next=NULL;
    return head;
}
