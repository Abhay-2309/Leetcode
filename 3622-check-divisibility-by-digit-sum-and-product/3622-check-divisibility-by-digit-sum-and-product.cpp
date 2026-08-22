class Solution {
public:
    pair<int,long long> f(int n){
        int temp = 0;
        long long temp2 = 1;
        while(n>0){
            temp += n%10;
            temp2*=(n%10);
            n = n / 10;
        }
        return {temp,temp2};
    }
    
    bool checkDivisibility(int n) {
        int sum = f(n).first;
        long long prod = f(n).second;
        cout<<sum<<" "<<prod;
        // cout<<n<<endl;
        if((sum+prod)==1) return true;
        // if(prod == 0) return false;
        if(n%(sum+prod)==0) return true;
        return false;
    }
};