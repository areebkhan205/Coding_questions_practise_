class Solution {
    bool ispal(string &ans){
           int l=0;
           int r=ans.size()-1;
           while(l<=r){
               if(ans[l]!=ans[r]){
                return false;
                break;
               }
               l++;
               r--;
           }
    return true;
    }
public:
    bool isPalindromic(string s) {
        
          int n=s.size();
          string ans="";
          for(int i=0;i<n;i++){
            int ch=(int)s[i];
            bitset<8>b(ch);
             ans+=b.to_string();
          }

          return ispal(ans);
    }
};