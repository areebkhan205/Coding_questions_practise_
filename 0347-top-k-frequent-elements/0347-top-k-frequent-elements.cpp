class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int x:nums){
            mpp[x]++;
        }

        priority_queue<pair<int,int>> pq;
          for(auto it:mpp){
                pq.push({it.second,it.first});
          }

          while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
          }
        return ans;
    }
};