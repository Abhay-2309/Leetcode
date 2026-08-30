class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int x = source[0], y = source[1];
        int tx = target[0], ty = target[1];
        if ((x + y) % 2 != (tx + ty) % 2)
            return -1;
        if (x == tx && y == ty)
            return 0;
        if (abs(x - tx) == abs(y - ty))
            return 1;
        return 2;
    }
};