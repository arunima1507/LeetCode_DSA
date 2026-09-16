class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;
        long long ans = 1;
        int r = 2 * k;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n + k - i) % MOD;
            ans = ans * modPow(i, MOD - 2, MOD) % MOD;
        }
        return ans;
    }

private:
    long long modPow(long long a, long long b, long long mod) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
};