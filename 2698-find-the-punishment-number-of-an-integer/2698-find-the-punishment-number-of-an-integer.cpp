class Solution {
public:
    bool canSplit(string &num, int target, int index = 0, int sum = 0) {
    if (index == num.size()) {
        return sum == target;
    }

    int currentSum = 0;
    for (int i = index; i < num.size(); ++i) {
        currentSum = currentSum * 10 + (num[i] - '0');
        if (currentSum + sum <= target && canSplit(num, target, i + 1, sum + currentSum)) {
            return true;
        }
    }
    return false;
}

// Function to find the punishment number
int punishmentNumber(int n) {
    int totalSum = 0;
    for (int x = 1; x <= n; ++x) {
        string squareStr = to_string(x * x);
        if (canSplit(squareStr, x)) {
            totalSum += x * x;
        }
    }
    return totalSum;
}
};