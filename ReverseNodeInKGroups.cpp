#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
   ListNode* findKthNode(ListNode* temp,int k){
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
 }
 ListNode* reverse(ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode* newHead=reverse(head->next);
    ListNode* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
 }
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev;
        while(temp!=NULL){
            ListNode* KthNode=findKthNode(temp,k);
            if(KthNode==NULL){
                if(prev) prev->next=temp;
                break;
            }
            ListNode* nextNode=KthNode->next;
            KthNode->next=NULL;
            reverse(temp);
            if(temp==head){
                head=KthNode;
            }
            else{
                prev->next=KthNode;
            }
            prev=temp;
            temp=nextNode;
        }
        return head;
    }
};
