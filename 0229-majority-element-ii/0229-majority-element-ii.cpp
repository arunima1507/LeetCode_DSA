class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map <int,int> counts;
        int val = nums.size()/3;
        for (int n:nums) counts[n]++;
        for (auto c:counts){
            if (c.second>val) ans.push_back(c.first);
        }
        return ans;
    }
};