class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        set<int> seen;
        set<int> bad;

        for (int i = 0; i < nums.size(); i++) {

            // If this number appeared before,
            // but this is a new block
            if (i > 0 && nums[i] != nums[i - 1] &&
                seen.count(nums[i])) {

                bad.insert(nums[i]);
            }

            seen.insert(nums[i]);
        }

        return seen.size() - bad.size();
    }
};