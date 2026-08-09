class Solution {
public:
    
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int>rightHandSideMatchLen(n,0);
        int i=n-1,j=m-1;
        int cnt=0;
        while(i>=0){
            if(j>=0 && word1[i]==word2[j]){
                cnt++;
                rightHandSideMatchLen[i]=cnt;
                j--;
            }
            rightHandSideMatchLen[i]=cnt;
            i--; 
        }
        vector<int>index;
        bool changePower = true;
        
        i = 0;
        j = 0;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                index.push_back(i);
                j++;
            }
            else if(i+1<n && changePower==true && rightHandSideMatchLen[i+1]>=m-j-1){
                index.push_back(i);
                j++;
                changePower = false;
            }
            i++;
        }
        if(j==m)return index;
        return {};
    }
};