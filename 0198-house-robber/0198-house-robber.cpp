class Solution {
    int dp[101];
    int solve(int i,vector<int> &nums){
          int n=nums.size();
        if(i>=n)return 0;
        if(i==n-1)return nums[i];
        if(dp[i]!=-1)return dp[i];
        int take=nums[i]+solve(i+2,nums);
        int notake=solve(i+1,nums);
        return dp[i]=max(take,notake);
    }
public:
    int rob(vector<int>& nums) {
         int n=nums.size();
         memset(dp,-1,sizeof(dp));
         return solve(0,nums);
    }
};