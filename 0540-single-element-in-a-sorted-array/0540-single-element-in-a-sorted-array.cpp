class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
         int n = arr.size(); //size of the array.
         int ans = 0;
        // XOR all the elements:
        for (int i = 0; i < n; i++) {
            ans = ans ^ arr[i];
        }
        return ans;
        }
};