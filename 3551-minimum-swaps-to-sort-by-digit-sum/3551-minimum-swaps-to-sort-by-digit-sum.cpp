#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sum_digit(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n = n / 10;
        }
        return sum;
    }

    static bool myComparator(const tuple<int, int, int>& A, const tuple<int, int, int>& B) {
        if (get<0>(A) != get<0>(B))
            return get<0>(A) < get<0>(B);
        return get<1>(A) < get<1>(B);
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<tuple<int, int, int>> vec;

        // Build the tuple: (digit sum, value, original index)
        for (int i = 0; i < n; i++) {
            int sum = sum_digit(nums[i]);
            vec.emplace_back(sum, nums[i], i);
        }

        // Sort the vector using custom comparator
        sort(vec.begin(), vec.end(), myComparator);

        // Build new position mapping from original index to sorted index
        vector<int> newpos(n);
        for (int sorted_idx = 0; sorted_idx < n; sorted_idx++) {
            int orig_idx = get<2>(vec[sorted_idx]);
            newpos[orig_idx] = sorted_idx;
        }

        // Cycle detection
        int ans = 0;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (visited[i] || newpos[i] == i) continue;
            int cycle_length = 0;
            int start = i;

            while (!visited[start]) {
                visited[start] = 1;
                start = newpos[start];
                cycle_length++;
            }

            ans += (cycle_length - 1); // Each cycle of length L needs L - 1 swaps
        }

        return ans;
    }
};
