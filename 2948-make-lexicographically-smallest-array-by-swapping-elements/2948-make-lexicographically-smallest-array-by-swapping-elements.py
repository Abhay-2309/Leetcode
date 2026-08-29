from collections import defaultdict, deque
from typing import List

class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n = len(nums)
        sorted_nums = sorted(nums)
        grpmap = defaultdict(deque)
        grpindex = defaultdict(int)
        grp = 0
        grpindex[sorted_nums[0]] = grp
        grpmap[grp].append(sorted_nums[0])
        for i in range(1, n):
            if (sorted_nums[i] - sorted_nums[i-1]) <= limit:
                grpindex[sorted_nums[i]] = grp
                grpmap[grp].append(sorted_nums[i])
            else:
                grp += 1
                grpindex[sorted_nums[i]] = grp
                grpmap[grp].append(sorted_nums[i])
        res = []
        for i in range(n):
            num = nums[i]
            group = grpindex[num]
            res.append(grpmap[group].popleft())
            
        return res