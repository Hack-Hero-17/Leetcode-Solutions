class Solution:
    def maximumTripletValue(self, a: List[int]) -> int:
        leftMax = accumulate(a, max)
        rightMax = [*accumulate(a[:1:-1], max)][::-1]
        triplet = ((v-u)*w for v,u,w in zip(leftMax, a[1:], rightMax))

        return max(max(triplet), 0)