class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        n = len(nums)
        maxlen = 0
        if n==1:
            return nums[0]+1
        currsum =0
        mini =float('inf')
        currlength =0
        ptr=0
        indexmapped = [-1]*3000      
        for i in range(n):
            indexmapped[nums[i]] = i
        while ptr<n:
            if ptr > 0 and nums[ptr] != nums[ptr-1] + 1: 
                break
                
            currsum+=nums[ptr]
            currlength +=1
            if currlength>=maxlen:   
                maxlen = currlength
                res = currsum        
                while indexmapped[res]!=-1:
                    res+=1
                mini = res        
            ptr+=1
        return mini