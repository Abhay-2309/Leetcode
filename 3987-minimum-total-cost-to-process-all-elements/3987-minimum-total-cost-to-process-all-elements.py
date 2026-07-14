class Solution:
    def minimumCost(self, A: list[int], k: int) -> int:
        x = ceil(sum(A) / k)
        return (x - 1) *  x // 2 % (10 ** 9 + 7)
        