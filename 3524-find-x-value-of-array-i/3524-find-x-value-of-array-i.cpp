class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);
        for (int x:nums) {
            x%=k;
            vector<long long> ndp(k, 0);
            ndp[x]++;
            for (int r=0; r<k; r++) {
                if (dp[r]) ndp[(r*x) % k] += dp[r];
            }
            dp = ndp;
            for (int r = 0; r<k; r++) ans[r] += dp[r];
        }
        return ans;
    }
};