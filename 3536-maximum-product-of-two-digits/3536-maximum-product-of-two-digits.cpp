class Solution {
public:
    int maxProduct(int n) {
        string a=to_string(n);
          int ans=0;
        for(int i=0;i<a.size();i++){
               for(int j=i+1;j<a.size();j++){
                 ans=max(ans,(a[i]-'0')*(a[j]-'0'));
               }
    }
    return ans;
    }
};