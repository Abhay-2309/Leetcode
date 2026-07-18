class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        if (n == 1 || m == 1) {
            if (k != 1) {
                return {};
            }
            if (m == 1) {
                return { string(n, '.') };
            }
            if (n == 1) {
                return vector<string>(m, ".");
            }
        }
        
        if (k == 1) {
            vector<string> ans;
            ans.push_back(string(n, '.'));
            for (int i = 0; i < m - 1; ++i) {
                ans.push_back(string(n - 1, '#') + ".");
            }
            return ans;
        }
            
        else if (k == 2) {
            if (n >= 2 && m >= 2) {
                vector<string> ans;
                ans.push_back(string(n, '.'));
                ans.push_back(string(n - 2, '#') + "..");
                for (int i = 0; i < m - 2; ++i) {
                    ans.push_back(string(n - 1, '#') + ".");
                }
                return ans;
            }
            return {};
        }
            
        else if (k == 3) {
            if (n >= 3 && m >= 2) {
                vector<string> ans;
                ans.push_back(string(n, '.'));
                ans.push_back(string(n - 3, '#') + "...");
                for (int i = 0; i < m - 2; ++i) {
                    ans.push_back(string(n - 1, '#') + ".");
                }
                return ans;
            } else if (m >= 3 && n >= 2) {
                vector<string> ans;
                ans.push_back(string(n, '.'));
                ans.push_back(string(n - 2, '#') + "..");
                ans.push_back(string(n - 2, '#') + "..");
                for (int i = 0; i < m - 3; ++i) {
                    ans.push_back(string(n - 1, '#') + ".");
                }
                return ans;
            }
            return {};
        }
            
        else if (k == 4) {
            if (n >= 3 && m >= 3) {
                vector<string> ans;
                ans.push_back(string(n - 1, '.') + "#");
                ans.push_back(string(n - 3, '#') + "...");
                ans.push_back(string(n - 3, '#') + "#..");
                
                for (int i = 0; i < m - 3; ++i) {
                    ans.push_back(string(n - 1, '#') + ".");
                }
                return ans;
            }
            else if (m == 2 && n >= 4) {
                return {
                    string(4, '.') + string(n - 4, '#'),
                    string(n, '.')
                };
            }
            else if (n == 2 && m >= 4) {
                vector<string> ans;
                for (int i = 0; i < m; ++i) {
                    if (i < 4) {
                        ans.push_back("..");
                    } else {
                        ans.push_back("#.");
                    }
                }
                return ans;
            }
            return {};
        }
            
        return {};
    }
};