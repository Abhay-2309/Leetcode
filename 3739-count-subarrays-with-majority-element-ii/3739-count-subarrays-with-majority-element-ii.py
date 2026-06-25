from typing import List

class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        max_val = 2 * n + 1
        class SegmentTree:
            def __init__(self, size):
                self.size = size
                self.tree = [0] * (2 * size)
                
            def add(self, index, delta):
                index += self.size
                while index > 0:
                    self.tree[index] += delta
                    index //= 2
                    
            def query(self, left, right):
                res = 0
                left += self.size
                right += self.size
                
                while left <= right:
                    if left % 2 == 1:
                        res += self.tree[left]
                        left += 1
                    if right % 2 == 0:
                        res += self.tree[right]
                        right -= 1
                        
                    left //= 2
                    right //= 2
                    
                return res
        seg_tree = SegmentTree(max_val)
        
        offset = n
        current_prefix_sum = 0
        total_subarrays = 0
        seg_tree.add(current_prefix_sum + offset, 1)
        
        for num in nums:
            if num == target:
                current_prefix_sum += 1
            else:
                current_prefix_sum -= 1
            left_bound = 0
            right_bound = current_prefix_sum - 1 + offset
            if right_bound >= 0:
                total_subarrays += seg_tree.query(left_bound, right_bound)
            seg_tree.add(current_prefix_sum + offset, 1)
            
        return total_subarrays