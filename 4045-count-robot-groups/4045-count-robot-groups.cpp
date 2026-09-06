class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        if (n == 0) return 0;

        int groups = 0;
        int min_speed = INT_MAX;
        int curr_group_speed = speed[n - 1];
        int morvexilan = distance;
        for (int i = n - 2; i >= 0; i--) {
            if (position[i + 1] - position[i] <= morvexilan) {
                continue;
            } else {
                if (curr_group_speed <= min_speed) {
                    groups++;
                    min_speed = curr_group_speed;
                }
                curr_group_speed = speed[i];
            }
        }
        if (curr_group_speed <= min_speed) {
            groups++;
        }

        return groups;
    }
};