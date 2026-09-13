class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<long long, 3>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = {intervals[i][0], intervals[i][1], i};

        sort(a.begin(), a.end());

        // dp[i][k] = best score using intervals from i onward, choosing <= k.
        // Store the lexicographically smallest index set for ties.
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1, vector<pair<long long, vector<int>>>(5)
        );

        vector<int> starts(n);
        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        auto better = [](const pair<long long, vector<int>>& x,
                         const pair<long long, vector<int>>& y) {
            if (x.first != y.first)
                return x.first > y.first;
            return x.second < y.second;
        };

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                // Skip current interval.
                dp[i][k] = dp[i + 1][k];

                // Take current interval.
                // Need next interval with start > current right.
                int j = upper_bound(starts.begin(), starts.end(), a[i][1])
                        - starts.begin();

                auto take = dp[j][k - 1];
                take.first += intervals[a[i][2]][2];
                take.second.push_back(a[i][2]);

                sort(take.second.begin(), take.second.end());

                if (better(take, dp[i][k]))
                    dp[i][k] = take;
            }
        }

        return dp[0][4].second;
    }
};