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
ListNode* startingNode(ListNode* head){
    map<ListNode*,int> mpp;
    ListNode* temp=head;
    while(temp!=NULL){
        if(mpp.count(temp)){
            return temp;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
    return NULL;
}
//Optimal
ListNode* StartingNode(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }

    return NULL;
}