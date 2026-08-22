class Solution {
public:
    bool checkDivisibility(int n) {
        int o = n;
        int sump = 1;
        int sums = 0;

        while(n > 0) {
            int digit = n % 10;
            sums += digit;
            sump *= digit;
            n /= 10;
        }

        return (o %(sump+sums)==0);
    }
};