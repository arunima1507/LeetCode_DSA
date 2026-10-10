class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = 1LL * k1 + k2;
        int n = nums1.size();

        vector<int> diff(n);
        int maxDiff = 0;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            total += diff[i];
        }

        if (total <= k)
            return 0;

        int low = 0, high = maxDiff;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long operations = 0;

            for (int d : diff) {
                if (d > mid)
                    operations += d - mid;
            }

            if (operations <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int level = low;
        long long operations = 0;
        long long ans = 0;
        long long count = 0;

        for (int d : diff) {
            if (d > level) {
                operations += d - level;
                d = level;
            }

            ans += 1LL * d * d;

            if (d == level)
                count++;
        }

        long long remaining = k - operations;
        ans -= remaining * (2LL * level - 1);

        return ans;
    }
};