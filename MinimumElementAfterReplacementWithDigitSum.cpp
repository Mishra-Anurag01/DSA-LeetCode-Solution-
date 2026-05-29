#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int digitSum(int x) {
        int sum = 0;

        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int minElement(vector<int>& nums) {
        int mini = INT_MAX;

        for (int num : nums) {
            mini = min(mini, digitSum(num));
        }

        return mini;
    }
};