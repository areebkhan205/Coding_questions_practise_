class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int a = f.size();
        if (n == 0)
            return true;
        for (int i = 0; i < a; i++) {
            if (f[i] == 0) {
                bool leftkhali = (i==0 || f[i - 1] == 0 );
                bool rightkhali = (i==a-1 || f[i + 1] == 0);

                if (leftkhali && rightkhali) {
                    f[i]=1;
                    n--;


                    if (n == 0)
                    return true;
                }

                
            }
        }

        return false;
    }
};