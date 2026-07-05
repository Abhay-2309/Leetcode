class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr;
        arr.emplace_back(-1);
        arr.emplace_back(-2);
        int ptr =0;
        while(ptr<n){
            arr.emplace_back(nums[ptr]);
            arr.emplace_back(-2);
            ptr++;
        }
        arr.emplace_back(-3);
        vector<long long>prefixsum(arr.size());
        ptr =1;
        long long a=0,b=0;
        while((ptr+1)<arr.size()){
            if(b>ptr) prefixsum[ptr] = min(b-ptr,prefixsum[(a<<1)-ptr]);
            while( arr[ptr+1+prefixsum[ptr]]==arr[ptr-1-prefixsum[ptr]]) prefixsum[ptr]++;
            if(prefixsum[ptr]>(b- ptr)){
                a = ptr;
                b= ptr+prefixsum[ptr];
            }
            ptr++;
        }
        vector<long long>prefixsum2(n+1);
        ptr=0;
        while(ptr<n){
            prefixsum2[ptr+1] = prefixsum2[ptr]+nums[ptr];
            ptr++;
        }
        long long res =0;
        ptr=1;
        while((ptr+1)<arr.size()){
            if(prefixsum[ptr]<=0){
                ptr++;
                continue;
            }
            else{
                long long  temp =( ptr -1 - prefixsum[ptr])>>1;
                res = max(res,prefixsum2[temp+prefixsum[ptr]] - prefixsum2[temp]);
            }
            ptr++;
        }
        return res;
    }
};