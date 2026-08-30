class Solution:
    def largestString(self, nums: list[int]) -> list[str]:
        ans = []
        for num in nums:
            res = []
            if (num >> 26) & 1:
                res.append("zz")
            for bit in range(25, -1, -1):
                if (num >> bit) & 1:
                    res.append(chr(ord('a') + bit))
            ans.append("".join(res))
        return ans