class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(),nums.end());
        int i=1;
        int temp = k;
        while(true){
            if(st.find(temp)==st.end()) return temp;
            temp = k*i;
            i++;
        }
        return 0;
    }
};