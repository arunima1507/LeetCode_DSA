class Solution {
public:
    string s;
    int pos;

    set<string> parseExpr() {
        set<string> res = parseConcat();

        while (pos < s.size() && s[pos] == ',') {
            pos++;
            set<string> cur = parseConcat();
            res.insert(cur.begin(), cur.end());
        }

        return res;
    }

    set<string> parseConcat() {
        set<string> res = {""};

        while (pos < s.size() && s[pos] != '}' && s[pos] != ',') {
            set<string> cur;

            if (s[pos] == '{') {
                pos++;
                cur = parseExpr();
                pos++; // skip '}'
            } 
            else {
                cur.insert(string(1, s[pos]));
                pos++;
            }

            set<string> temp;

            for (const string& a : res) {
                for (const string& b : cur) {
                    temp.insert(a + b);
                }
            }

            res = temp;
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> result = parseExpr();

        return vector<string>(result.begin(), result.end());
    }
};