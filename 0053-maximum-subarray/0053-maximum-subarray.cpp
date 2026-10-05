class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max_=INT_MIN;
        for (int i=0; i<= nums.size()-1; i++ ){
            sum += nums[i];
            if (max_<sum) max_ = sum;
            if (sum<0) sum = 0;
        }
        return max_;
    }
};