class Solution {
    int dp[101];
    int solve(int i,vector<int> &arr){
        int n=arr.size();
        if(i>=n)return 0;
        if(i==n-1)return arr[i];
        if(dp[i]!=-1)return dp[i];
        int take=arr[i]+solve(i+2,arr);
        int notake=solve(i+1,arr);
    return dp[i]=max(take,notake);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int ans=0;
        memset(dp,-1,sizeof(dp));
        vector<int> first(nums.begin()+1,nums.end());
          ans=max(ans,solve(0,first));
             memset(dp,-1,sizeof(dp));
          vector<int> second(nums.begin(),nums.end()-1);
          ans=max(ans,solve(0,second));
    return ans;
    }
};