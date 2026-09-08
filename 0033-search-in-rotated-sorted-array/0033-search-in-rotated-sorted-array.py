class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        low = 0
        high = n - 1
        flag = False
        
        while low <= high:
            mid = low + ((high - low) >> 1)
            flag = nums[mid] > nums[high] or nums[mid] < nums[low]
            
            if flag:
                if nums[mid] == target:
                    return mid
                elif nums[low] <= nums[mid]:
                    if target < nums[mid] and nums[low] <= target:
                        high = mid - 1
                    else:
                        low = mid + 1
                else:
                    if target > nums[mid] and target <= nums[high]:
                        low = mid + 1
                    else:
                        high = mid - 1
            else:
                if nums[mid] == target:
                    return mid
                elif nums[mid] > target:
                    high = mid - 1
                else:
                    low = mid + 1
                    
        return -1