class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int num=n;num<=100;num++){
            int val=num;
            int prod=1;
            while(val>0){
                prod *= val%10;
                val /=10;
            }
            if(prod%t==0)return num;
        }
        return 0;
    }
};
