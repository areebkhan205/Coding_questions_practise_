class Solution {

       int solve(int i,vector<int> &nums,int target){
            if(i<0){
                if(target==0)return 1;
                else return  0;
            };
            int plus=solve(i-1,nums,target+nums[i]);
            int minus=solve(i-1,nums,target-nums[i]);
        return plus+minus;
       }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
            return solve(nums.size()-1,nums,target);
    }
};