#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  ListNode* AddToNumbersinLL(ListNode* head1, ListNode* head2){
    ListNode* t1=head1;
    ListNode* t2=head2;
    ListNode* dummyNode=new ListNode(-1);
    ListNode* current=dummyNode;
    int carry=0;
    while (t1!=NULL || t2!=NULL)
    {
        int sum=carry;
        if(t1) sum+=t1->val;
        if(t2) sum+=t2->val;

        ListNode* newNode=new ListNode(sum%10);
        carry=sum/10;
        current->next=newNode;
        current=current->next;
        if(t1) t1=t1->next;
        if(t2) t2=t2->next;
    }
    if(carry){
        ListNode* newNode=new ListNode(carry);
        current->next=newNode;
    }
    return dummyNode;
  }
  