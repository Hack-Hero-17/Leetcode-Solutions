class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        isPrime = [True] * (n + 1)
        isPrime[0] = isPrime[1] = False
        for i in range(2, int(n**0.5) + 1):
            if isPrime[i]:
                for j in range(i * i, n + 1, i):
                    isPrime[j] = False
        p = sum(isPrime)
        factorial = [1] * (n + 1)
        for i in range(1, n + 1):
            factorial[i] = factorial[i - 1] * i % (10**9 + 7)
    
        return (factorial[p] * factorial[n - p]) % (10**9 + 7)