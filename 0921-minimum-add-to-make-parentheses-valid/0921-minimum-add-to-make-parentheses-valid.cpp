class Solution {
public:
    int minAddToMakeValid(string s) {
        int c=0, b=0;
        for (char ch: s){
            if (ch=='(') c++;
            else {
                if (c>0) c--;
                else b++;
            }
        }
        return c+b;
    }
};