class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto i:mpp){
            pq.push({i.second,i.first});
        }
      while(k--){
        ans.push_back(pq.top().second);
        pq.pop();
      }
        return ans;
    }
};