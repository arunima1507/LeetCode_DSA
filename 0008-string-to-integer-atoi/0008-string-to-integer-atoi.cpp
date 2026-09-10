#include <climits>
#include <string>
#include <cctype>

class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        int flag = 1;
        int started=0, signtaken =0;
        
        for (int i=0;i<s.size();i++){

            if (s[i]==' ' && started==0 && signtaken==0) continue;
            if ((s[i]=='-'||s[i] =='+') && started==0 && signtaken==0){
                signtaken=1;
                if(s[i]=='-') flag =-1;
                continue;
            }
            if (isdigit(s[i])){
                started =1;
                if(num>INT_MAX/10 || (num == INT_MAX/10 && (s[i]-'0')>7)) return flag ==1? INT_MAX:INT_MIN;
                num= num*10 + (s[i]-'0');
            }
            else break;
        }
        return flag*num;
    }
};