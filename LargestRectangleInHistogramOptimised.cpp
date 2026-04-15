#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
       stack<int> st;
int maxArea=0;
for(int i=0;i<arr.size();i++){
    while(!st.empty() && arr[st.top()]>arr[i]){
        int element=st.top();
        st.pop();
        int nse=i;
        int pse=st.empty()?-1:st.top();
        maxArea=max(maxArea,arr[element]*(nse-pse-1));
    }
    st.push(i);
}
while(!st.empty()){
    int nse=arr.size();
    int element=st.top();
    st.pop();
    int pse=st.empty()?-1:st.top();
    maxArea=max(maxArea,arr[element]*(nse-pse-1));
}
return maxArea;
    }
};
