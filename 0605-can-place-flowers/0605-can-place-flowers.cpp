class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int a = f.size();

        for (int i = 0; i < a; i++) {
            if (f[i] == 0 &&
                (i == 0 || f[i - 1] == 0) &&
                (i == a - 1 || f[i + 1] == 0)) {

                f[i] = 1;
                n--;
            }
        }

        return n <= 0;
    }
};