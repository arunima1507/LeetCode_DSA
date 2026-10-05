class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0], count = 1;
        for (int i = 1; i <= nums.size()-1; i++){
            if (nums[i]==ele) count+=1;
            else count-=1;
            if (count==0){
                ele = nums[i+1];
                if (i==nums.size()-2) return ele;
            }
        }
        return ele;
    }
};