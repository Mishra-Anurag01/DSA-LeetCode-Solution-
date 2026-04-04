#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* mergetwosortedlists(vector<ListNode*> &list){
   ListNode* head=list[0];
   priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
   for(int i=0;i<list.size();i++){
    if(list[i]){
        pq.push({list[i]->val,list[i]});
    }
   }
   ListNode* dummyNode=new ListNode(-1);
   ListNode* temp=dummyNode;
   while(!pq.empty()){
    auto it=pq.top();
    pq.pop();
    if(it.second->next)
    pq.push({it.second->next->val,it.second->next});
    temp->next=it.second;
    temp=temp->next;
   }
   return dummyNode->next;
}
