class Solution {
public:
    int maximumSwap(int num) {
        vector<string> ans;
        
        string s=to_string(num);
        int n=s.size();
        int idx;
        for(int i=0;i<n;i++){
              string a=s;
               idx=-1;
            for(int j=i+1;j<n;j++){
                if(a[j]>a[i]){
                if(idx==-1 || a[j]>=a[idx]){
                idx=j;
            }
                }
            }
            if(idx!=-1){
            swap(a[idx],a[i]);
            }
           
            ans.push_back(a);
        }

        int maxi=INT_MIN;
        for(int i=0;i<ans.size();i++){
              int as=stoi(ans[i]);
              maxi=max(maxi,as); 
        }
    return maxi;
    }
};