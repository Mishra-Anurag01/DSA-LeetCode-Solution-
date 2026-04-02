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
    k-=1;
    while(temp!=NULL && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
  }
  ListNode* reverse(ListNode* head){
    ListNode* temp=head;
    ListNode* prev=NULL;
    while(temp->next!=NULL){
        ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
  ListNode* ReverseNodeInKgroups(ListNode* head,int k){
    ListNode* temp=head;
    ListNode* prevNode=NULL;
    while(temp!=NULL){
        ListNode* KthNode=findKthNode(temp,k);
        if(KthNode==NULL){
            if(prevNode) prevNode->next=temp;
            break;
        }
        ListNode* nextNode=KthNode->next;
        KthNode->next=NULL;
        reverse(temp);
        if(temp==head){
            head=KthNode;
        }
        else{
            prevNode->next=KthNode;
        }
        prevNode=temp;
        temp=nextNode;
    }
    return head;
  }
  