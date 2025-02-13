class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        std::priority_queue<long, std::vector<long>, std::greater<>> minHeap(nums.begin(), nums.end());
        int operations = 0;

        while (minHeap.size() > 1 && minHeap.top() < k) {
            long x = minHeap.top();
            minHeap.pop();
            long y = minHeap.top();
            minHeap.pop();
            long newElement = std::min(x, y) * 2 + std::max(x, y);
            minHeap.push(newElement);
            ++operations;
        }

        return operations;
    }
};