from typing import List, Tuple
import heapq

class SparseTableMinMax:
    def __init__(self, arr: List[int]):
        self.n = len(arr)
        if self.n == 0:
            return
        self.max_k = self.n.bit_length() 
        
        self.st_min = [[0] * self.max_k for _ in range(self.n)]
        self.st_max = [[0] * self.max_k for _ in range(self.n)]
        
        for i in range(self.n):
            self.st_min[i][0] = arr[i]
            self.st_max[i][0] = arr[i]
            
        for j in range(1, self.max_k):
            for i in range(self.n - (1 << j) + 1):
                self.st_min[i][j] = min(
                    self.st_min[i][j - 1], 
                    self.st_min[i + (1 << (j - 1))][j - 1]
                )
                self.st_max[i][j] = max(
                    self.st_max[i][j - 1], 
                    self.st_max[i + (1 << (j - 1))][j - 1]
                )

    def query(self, left: int, right: int) -> Tuple[int, int]:
        if left > right:
            return (float('inf'), float('-inf'))
            
        length = right - left + 1
        j = length.bit_length() - 1 
        
        range_min = min(
            self.st_min[left][j], 
            self.st_min[right - (1 << j) + 1][j]
        )
        range_max = max(
            self.st_max[left][j], 
            self.st_max[right - (1 << j) + 1][j]
        )
        
        return (range_min, range_max)

class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        if not nums:
            return 0
            
        spTable = SparseTableMinMax(nums)
        pq = []
        n = len(nums)
        
        left = 0
        right = n - 1
        while left <= right:
            mini, maxi = spTable.query(left, right)
            heapq.heappush(pq, (-(maxi - mini), left, right))
            left += 1 
            
        ans = 0
        while k > 0 and pq:
            neg_s, l, r = heapq.heappop(pq)
            ans += (-neg_s)
            k -= 1  
            
            newl = l
            newr = r - 1  
            if newr >= newl:
                mini, maxi = spTable.query(newl, newr)
                heapq.heappush(pq, (-(maxi - mini), newl, newr))
                
        return ans