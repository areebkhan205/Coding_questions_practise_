class Solution {
    int dp[2001];
    bool ispal(int i,int j,string &s){
          
          while(i<=j){
              if(s[i]!=s[j]){
                return false;
              }

              i++;
              j--;
          }
    return true;

    }

    int solve(int i,string &s){
        if(i==s.size())return  0;
          if(dp[i]!=-1)return dp[i];
        int ans=INT_MAX;
        for(int j=i;j<s.size();j++){
            if(ispal(i,j,s)){
                int cost=1+solve(j+1,s);
                ans=min(cost,ans);
            }
        }
    return   dp[i]= ans;
    }
public:
    int minCut(string s) {
     memset(dp,-1,sizeof(dp));
         return solve(0,s)-1;
    }
};