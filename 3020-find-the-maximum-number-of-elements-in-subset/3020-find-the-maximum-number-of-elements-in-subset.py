from collections import Counter

class Solution:
    def maximumLength(self, nums: list[int]) -> int:
        freq = Counter(nums)
        cnt = freq[1]
        if cnt % 2 == 0 and cnt > 0:
            cnt -= 1
            
        ans = 0
        unq_nums = sorted([key for key in freq.keys() if key != 1])
        
        for num in unq_nums:
            current_val = num
            tempcnt = 0
            flag = False
            
            while True:
                if current_val > 10**9 or current_val not in freq:
                    flag = True
                    break
                if freq[current_val] < 2:
                    tempcnt += 1
                    break
                
                tempcnt += 2
                current_val *= current_val
            if flag and (tempcnt % 2) == 0 and tempcnt > 0:
                tempcnt -= 1
                
            ans = max(ans, tempcnt)
            
        return max(ans, cnt)