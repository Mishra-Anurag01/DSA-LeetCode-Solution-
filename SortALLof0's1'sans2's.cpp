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
  ListNode* Sortzeroonesandtwos(ListNode* head){
    ListNode* temp=head;
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    while(temp!=NULL){
        if(temp->val==0) cnt0++;
        else if(temp->val==1) cnt1++;
        else cnt2++;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(cnt0){
            temp->val=0;
            cnt0--;
        }
       else if(cnt1){
            temp->val=1;
            cnt1--;
        }
        else{
            temp->val=2;
            cnt2--;
        }
        temp=temp->next;
    }
    return head;
  }
  //Optimal..
  ListNode* SortZeroOnesandTwos(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* zeroHead=new ListNode(-1);
     ListNode* oneHead=new ListNode(-1);
      ListNode* twoHead=new ListNode(-1);

      ListNode* zero=zeroHead;
      ListNode* one=oneHead;
      ListNode* two=twoHead;
      ListNode* temp=head;

      while(temp!=NULL){
        if(temp->val==0){
            zero->next=temp;
            zero=temp;
        }
       else if(temp->val==1){
            one->next=temp;
            one=temp;
        }
        else{
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
      }
      zero->next=(oneHead->next)?(oneHead->next):(twoHead->next);
      one->next=twoHead->next;
      two->next=NULL;
      ListNode* newHead=zeroHead->next;
      delete zeroHead;
      delete oneHead;
      delete twoHead;
      return newHead;

  }