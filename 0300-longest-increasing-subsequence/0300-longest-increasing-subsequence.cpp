class Solution {
    int solve(int idx,int last,vector<int> &nums,vector<vector<int>> &dp){
            if(idx>=nums.size())return 0; 
            if(dp[idx][last+1]!=-1)return dp[idx][last+1];  
         int take=0;
        if(last==-1 ||  nums[idx]>nums[last]){
             take=1+solve(idx+1,idx,nums,dp);
        }      
        int notake=solve(idx+1,last,nums,dp);
  return dp[idx][last+1]=max(take,notake);
  
      }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return solve(0,-1,nums,dp);
    }
};