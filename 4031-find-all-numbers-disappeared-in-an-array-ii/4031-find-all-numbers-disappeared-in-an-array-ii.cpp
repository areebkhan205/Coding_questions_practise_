class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
          set<int> st;
          for(int i=0;i<nums.size();i++){
              st.insert(nums[i]);
          }
          vector<vector<int>> ans;
            

            int i=lower;
            while(i<=upper){

                 if(st.count(i)){
                    i++;
                 }
                 

                           else {
                int start = i;

                while (i <= upper && !st.count(i)) {
                    i++;
                }

                int end = i - 1;

                ans.push_back({start, end});
            }
        }

            
            return ans;
    }
};