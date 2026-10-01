#include <vector>
#include <string>
#include <cctype> 
class Solution {
public:
    bool isValid(string s) {
        vector <char> ch;
        for (int i=0;i<s.length();i++){
            if (isalpha(s[i])||isdigit(s[i]))   return false;
            if (s[i]=='('||s[i]=='{'||s[i]=='['){
                ch.push_back(s[i]);
            } 
            else {
                if (ch.empty()) return false;
                char top = ch.back();
                if (top =='(') { 
                    if (s[i]==')') ch.pop_back();
                    else return false;
                }
                else if (top =='[') { 
                    if (s[i]==']') ch.pop_back();
                    else return false;
                }
                else if (top =='{') { 
                    if (s[i]=='}') ch.pop_back();
                    else return false;
                }
            }
        }
        if (ch.empty()) return true;
        else return false;
    }
};