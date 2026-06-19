class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_height = 0;
        int curr_height=0;

        for(int i=0;i<gain.size();i++){
            curr_height += gain[i];
            if(curr_height> max_height) max_height = curr_height;
        }

        return max_height;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna