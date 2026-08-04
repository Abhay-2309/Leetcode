class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        
        unsigned long long max_product = 1;
        int num_batches = 0;
        
        int count_of_threes = n / 3;
        int remainder = n % 3;
        
        if (remainder == 0) {
            max_product = pow(3, count_of_threes);
            num_batches = count_of_threes;
        } 
        else if (remainder == 1) {
            max_product = pow(3, count_of_threes - 1) * 4;
            num_batches = count_of_threes;
        } 
        else if (remainder == 2) {
            max_product = pow(3, count_of_threes) * 2;
            num_batches = count_of_threes + 1;
        }
        
        return max_product;
    }
};