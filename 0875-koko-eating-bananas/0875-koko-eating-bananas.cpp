class Solution {
    bool isp(int k,vector<int>& p, int h){
        long long hours=0;
        for(int x:p){
            hours+=ceil((double)x/k);
        }
        return hours<=h;
    }
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int l=1;
        int ho=p.size()-1;
        int maxi=0;
        for(int i=0;i<=ho;i++){
            maxi=max(maxi,p[i]);
        }
        int hi=maxi;
        while(l<=hi){
           int m = l + (hi - l) / 2;
           if(isp(m,p,h)){
                hi=m-1;
            }
            else{
                l=m+1;
            }
    }
    return l;
   }
    
    };;