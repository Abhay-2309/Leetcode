class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n =nums.size();
        set<int>st;
        for(int i=0;i<nums.size();i++) st.insert(nums[i]);
        vector<int>res;
        int temp = *st.begin();
        while(temp<*st.rbegin()){
            if(st.find(temp)==st.end()){
                res.push_back(temp);
                temp++;
            }
            else temp++;
        }
        return res;
    }
};