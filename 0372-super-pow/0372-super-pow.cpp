class Solution {
public:
    const int MOD = 1337;
    const int PHI = 1140;

    int power(int a, int b) {
        int result = 1;
        a %= MOD;

        while (b > 0) {
            if (b % 2 == 1) {
                result = (result * a) % MOD;
            }

            a = (a * a) % MOD;
            b /= 2;
        }

        return result;
    }

    int superPow(int a, vector<int>& b) {
        if (a == 1)
            return 1;
        int exponent = 0;

        for (int digit : b) {
            exponent = (exponent * 10 + digit) % PHI;
        }
        if (exponent == 0) {
            exponent = PHI;
        }
        return power(a, exponent);
    }
};