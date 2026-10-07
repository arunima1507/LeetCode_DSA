class Solution {
public:
    vector<string> ans;

    void dfs(string &s, int start, int lRemove, int rRemove) {
        if (lRemove == 0 && rRemove == 0) {
            int balance = 0;

            for (char c : s) {
                if (c == '(') {
                    balance++;
                } else if (c == ')') {
                    balance--;
                    if (balance < 0) return;
                }
            }
            if (balance == 0) ans.push_back(s);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (i > start && s[i] == s[i - 1])
                continue;
            if (lRemove > 0 && s[i] == '(') {
                s.erase(i, 1);
                dfs(s, i, lRemove - 1, rRemove);
                s.insert(i, 1, '(');
            }
            if (rRemove > 0 && s[i] == ')') {
                s.erase(i, 1);
                dfs(s, i, lRemove, rRemove - 1);
                s.insert(i, 1, ')');
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int lRemove = 0, rRemove = 0;
        for (char c : s) {
            if (c == '(') lRemove++;
            else if (c == ')') {
                if (lRemove>0) lRemove--;
                else rRemove++;
            }
        }
        dfs(s, 0, lRemove, rRemove);
        return ans;
    }
};