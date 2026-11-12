class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans1=1;
        int lis=1;
        for(int i=1;i<n;i++){
               if(nums[i]>nums[i-1]){
                   lis++;
                   ans1=max(lis,ans1);
               }
               else{
                lis=1;
               }
        }
        int lds=1;
        int ans2=1;
        for(int i=1;i<n;i++){
               if(nums[i]<nums[i-1]){
                lds++;
                ans2=max(lds,ans2);
               }
               else{
                   lds=1;
               }
        }
    return max(ans1,ans2);
    }
};