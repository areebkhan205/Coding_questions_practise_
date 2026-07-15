class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int cnt=0;
        // for(int x:nums){
        //     if(x==0)cnt++;
        // }
        // vector<int>temp;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]!=0){
        //       temp.push_back(nums[i]);
        //     }
        // }
        // while(cnt--){
        //     temp.push_back(0);
        // }
        // nums=temp;

        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};