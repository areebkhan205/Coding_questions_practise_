class Solution {
    int dp[501];
    int solve(int i, vector<int>&arr,int k){
        if(i==arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
            int len=0;
            int maxi=INT_MIN;
            int maxisum=INT_MIN;
   for(int j=i;j<min((int)arr.size(),k+i);j++){
    len++;
         maxi=max(maxi,arr[j]);
        int  sum=len*maxi+solve(j+1,arr,k);
         maxisum=max(sum,maxisum);

   }
   return  dp[i]= maxisum;

    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
         return solve(0,arr,k);
    }
};