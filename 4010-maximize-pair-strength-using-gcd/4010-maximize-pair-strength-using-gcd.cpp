class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
          int n=nums.size();
          long long ans=INT_MIN;
          for(int i=0;i<nums.size();i++){
                   int ans1=INT_MIN;
            for(int j=i+1;j<n;j++){
                   long long g=gcd(nums[i],nums[j]);
                    long long product=(long long)nums[i]*(long long)nums[j];
                   long long anss=product/(g*g);
                   ans=max(ans,anss);
            }
          }
    return ans;
    }
};