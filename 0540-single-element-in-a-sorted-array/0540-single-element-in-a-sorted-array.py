class Solution:
    def singleNonDuplicate(self, nums: list[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        if nums[0] != nums[1]:
            return nums[0]
        if nums[n-1] != nums[n-2]:
            return nums[n-1]
        low = 1
        high = n - 2
        while low <= high:
            mid = low + ((high - low) >> 1)
            if nums[mid] != nums[mid + 1] and nums[mid] != nums[mid - 1]:
                return nums[mid]
            firstoccur = -1
            if nums[mid] == nums[mid + 1]:
                firstoccur = mid
            elif nums[mid] == nums[mid - 1]:
                firstoccur = mid - 1
            if firstoccur & 1:
                high = mid - 1
            else:
                low = mid + 1
        return -1