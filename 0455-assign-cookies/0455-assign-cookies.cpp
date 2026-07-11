class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
         int j=0;
         int i=0;
       while(j<s.size() && i<g.size()){
          if(s[j]>=g[i]){
            i++;
            j++;
          }
          else{
            j++;
          }
          
       }
    return i;
    }
};