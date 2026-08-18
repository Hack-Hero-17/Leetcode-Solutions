class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for( int num : nums ){
            if( res.empty() || res.back() < num ){
                res.push_back(num);
            }
            else{
                int idx = binary_search(num,res);
                res[idx] = num;
            }
        }
        return res.size();
    }
private:
    int binary_search( int n, vector<int> arr ){
        int low = 0;
        int high = arr.size()-1;
        while( low <= high ){
            int mid = low + (high-low)/2;
            if( arr[mid] == n)
                return mid;
            else if( arr[mid] > n )
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna