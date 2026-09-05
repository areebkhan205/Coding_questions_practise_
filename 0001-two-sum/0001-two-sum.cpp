class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int,int> mpp;

        for(int i=0;i<nums.size();i++){
              int diff=target-nums[i];
               auto it =mpp.find(diff);
               if(it!=mpp.end()){
                    return {i,it->second};
               }
               mpp[nums[i]]=i;
        }
    return {-1,-1};
    }
};