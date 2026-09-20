class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;

        for (int i = 0; i < s.size(); i++) {
            int value = s[i] - 'a' + 1;
            int reverseValue = 27 - value;

            sum += (i + 1) * reverseValue;
        }

        return sum;
    }
};