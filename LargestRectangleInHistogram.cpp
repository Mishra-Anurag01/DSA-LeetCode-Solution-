#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 vector<int> findNSE(vector<int>& arr){
      vector<int> ans(arr.size());
      stack<int> st;
      for(int i=arr.size()-1;i>=0;i--){
          int currEle=arr[i];
          while(!st.empty() && arr[st.top()]>=currEle){
              st.pop();
          }
          ans[i]=!st.empty() ?st.top():arr.size();
          st.push(i);
         }
         return ans;
  }
    vector<int> findPSE(vector<int>& arr){
      vector<int> ans(arr.size());
      stack<int> st;
      for(int i=0;i<arr.size();i++){
          int currEle=arr[i];
          while(!st.empty() && arr[st.top()]>currEle){
              st.pop();
          }
          ans[i]=!st.empty()?st.top():-1;
          st.push(i);
         }
         return ans;
  }
    int largestRectangleArea(vector<int>& arr) {
       vector<int> nse=findNSE(arr);
       vector<int> pse=findPSE(arr);
       int maxi=0;
       for(int i=0;i<arr.size();i++){
           int area=arr[i]*(nse[i]-pse[i]-1);
           maxi=max(maxi,area);
       }
       return maxi;
    }
};
