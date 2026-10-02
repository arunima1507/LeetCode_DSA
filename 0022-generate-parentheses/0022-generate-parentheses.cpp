class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        function<void(int, int)> backtrack = [&](int open, int close) {
            if (cur.size() == 2 * n) {
                ans.push_back(cur);
                return;
            }
            if (open < n) {
                cur += '(';
                backtrack(open + 1, close);
                cur.pop_back();
            }
            if (close < open) {
                cur += ')';
                backtrack(open, close + 1);
                cur.pop_back();
            }
        };
        backtrack(0, 0);
        return ans;
    }
};