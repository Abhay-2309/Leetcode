class Solution {
public:
    int dp[106][106][106][3];
    int temp[106][106];
    inline static const int MOD = 1e9+7;
    inline static int moddadd(int a,int b){
        return (a+b)%MOD;
    }
    inline static int modmul(int a,int b){
        return (1LL*a*b)%MOD;
    }
    inline static int modsub(int a,int b){
        return (a-b+MOD)%MOD;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        int n = word1.size();
        int m = word2.size();
        int t = target.size();
        memset(dp,-1,sizeof(dp));
        auto f = [&](auto&& self,int ind1,int ind2,int newk,int dir)->int{
            if(ind1==t){
                return dir==0;
            }
            if(dp[ind1][ind2][newk][dir]!=-1) return dp[ind1][ind2][newk][dir];
            if(dir==1){
                if(ind2==n)return 0;
                int res = self(self,ind1,ind2+1,newk,1);
                if(word1[ind2]==target[ind1]) res = moddadd(res,self(self,ind1+1,ind2+1,newk,0));
                return dp[ind1][ind2][newk][dir] = res;
            }
            if(dir==2){
                if(newk==m) return 0;
                int res = self(self,ind1,ind2,newk+1,2);
                if( word2[newk]==target[ind1]) res = moddadd(res,self(self,ind1+1,ind2,newk+1,0));
                return dp[ind1][ind2][newk][dir] = res;
            } 
            return dp[ind1][ind2][newk][dir] = moddadd(self(self,ind1,ind2,newk,1),self(self,ind1,ind2,newk,2));
        };
        auto f2 = [&](auto&& self,int ind1,int ind2,string str)->int{
            if(ind1==t)return 1;
            if(ind2==str.length())return 0;
            if(temp[ind1][ind2]!=-1) return temp[ind1][ind2];
            int ans = self(self,ind1,ind2+1,str);
            if(str[ind2]==target[ind1]) ans = moddadd(ans,self(self,ind1+1,ind2+1,str));
            return temp[ind1][ind2] = ans;
        };
        int case1 = f(f,0,0,0,0);
        memset(temp,-1,sizeof(temp));
        int case2 = f2(f2,0,0,word1);
        memset(temp,-1,sizeof(temp));
        int case3 = f2(f2,0,0,word2);
        return modsub(case1,moddadd(case2,case3));
    }
};