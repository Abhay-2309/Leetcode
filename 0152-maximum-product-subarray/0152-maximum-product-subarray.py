class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        if n==1:
            return nums[0]
        fristnegative = -1
        lastnegative = n
        zero = 0
        negative = 0
        prod = 1
        for i in range(0,n):
            if nums[i]==0:
                zero+=1
            if(nums[i]<0):
                negative+=1
            prod *=nums[i]
            
        if zero==0:
            if negative%2==0:
                return prod
            else:
                l =0
                while nums[l]>0:
                    l+=1
                r = n-1
                while nums[r]>0:
                    r-=1
                x = 1
                y =1
                for i in range(0,r):
                    x= x*nums[i]
                for i in range(l+1,n):
                    y = y*nums[i]
                return max(x,y)
        
        maxi = nums[0]
        mini = nums[0]  
        prevproductmaxi = nums[0]
        prevproductmini = nums[0]
        idx = 1
        
        while idx < n:
            if nums[idx] != 0:
                if nums[idx] < 0:
                    prevproductmaxi, prevproductmini = prevproductmini, prevproductmaxi
                prevproductmaxi = max(nums[idx], prevproductmaxi * nums[idx])
                prevproductmini = min(nums[idx], prevproductmini * nums[idx])
                
                maxi = max(maxi, prevproductmaxi)
                mini = min(mini, prevproductmini)
                idx += 1
            else:
                maxi = max(maxi, 0) 
                if idx < n - 1:
                    prevproductmaxi = nums[idx+1]
                    prevproductmini = nums[idx+1]
                    
                    maxi = max(maxi, prevproductmaxi)
                    mini = min(mini, prevproductmini)
                    idx += 2
                else:
                    idx += 1 
                    
        return max(maxi, mini)