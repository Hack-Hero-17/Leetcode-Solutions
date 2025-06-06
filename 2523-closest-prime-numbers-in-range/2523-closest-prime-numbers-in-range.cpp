class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int limit = right + 1;
        vector<bool> isPrime(limit, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < limit; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step 2: Store prime numbers within the given range
        vector<int> primes;
        for (int i = left; i <= right; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        // Step 3: Find the closest prime pair
        if (primes.size() < 2) return {-1, -1}; // Not enough primes

        int minDiff = INT_MAX;
        vector<int> result(2, -1);

        for (size_t i = 1; i < primes.size(); ++i) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
    }
};