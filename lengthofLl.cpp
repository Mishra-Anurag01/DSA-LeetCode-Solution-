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
  int lengthofLL(ListNode* head){
    map<ListNode*,int> mpp;
    ListNode* temp=head;
    int timer=1;
    while(temp!=NULL){
        if(mpp.count(temp)){
            int value=mpp[temp];
            return (timer-value);
        }
        mpp[temp]=timer;
        timer++;
        temp=temp->next;
    }
    return 0;
  }
  //Optimal
  int LengthofLL(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            int cnt=1;
            fast=fast->next;
            while(slow!=fast){
                cnt++;
                fast=fast->next;
            }
            return cnt;
        }
    }
    return 0;
  }