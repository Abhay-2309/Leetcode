class Solution {
public:
    const static int MOD = 1e9 + 7;
    int K, SIZE;
    vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B) {
        vector<vector<long long>> C(SIZE, vector<long long>(SIZE, 0));
        for (int i = 0; i < SIZE; i++) {
            for (int k = 0; k < SIZE; k++) {
                if (A[i][k] == 0) continue; 
                for (int j = 0; j < SIZE; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }
    vector<vector<long long>> power(vector<vector<long long>> A, long long p) {
        vector<vector<long long>> res(SIZE, vector<long long>(SIZE, 0));
        for (int i = 0; i < SIZE; i++) res[i][i] = 1;
        while (p > 0) {
            if (p % 2 == 1) res = multiply(res, A);
            A = multiply(A, A);
            p /= 2;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        K = r - l + 1;
        SIZE = 2 * K;
        vector<vector<long long>> M(SIZE, vector<long long>(SIZE, 0));
        for (int v = 1; v <= K; v++) {
            for (int u = 1; u < v; u++) {
                M[(v - 1) * 2 + 0][(u - 1) * 2 + 1] = 1;
            }
            for (int u = v + 1; u <= K; u++) {
                M[(v - 1) * 2 + 1][(u - 1) * 2 + 0] = 1;
            }
        }
        vector<vector<long long>> M_power = power(M, n - 1);
        vector<long long> V(SIZE, 1);
        vector<long long> final_state(SIZE, 0);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                final_state[i] = (final_state[i] + M_power[i][j] * V[j]) % MOD;
            }
        }
        long long total_valid_arrays = 0;
        for (int i = 0; i < SIZE; i++) {
            total_valid_arrays = (total_valid_arrays + final_state[i]) % MOD;
        }
        return total_valid_arrays;
    }
};