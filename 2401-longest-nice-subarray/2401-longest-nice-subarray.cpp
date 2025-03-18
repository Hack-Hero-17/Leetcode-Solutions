#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, bitmask = 0, maxLen = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while ((bitmask & nums[right]) != 0) { 
                bitmask ^= nums[left]; 
                left++;
            }
            bitmask |= nums[right];  
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};