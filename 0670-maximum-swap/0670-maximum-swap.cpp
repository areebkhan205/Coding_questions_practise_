class Solution {
public:
    int maximumSwap(int num) {
        
        vector<string> temp;
        string a=to_string(num);
        int n=a.size();
        for(int i=0;i<n;i++){
               string s=a;
               int idx=-1;
            for(int j=i+1;j<n;j++){
                 if(s[j]>s[i]){
                        if(idx==-1 || s[j]>=s[idx]){
                               idx=j;
                        }

                 }
            }
            if(idx!=-1){
                swap(s[idx],s[i]);
            }
            temp.push_back(s);

        }

        int maxi=INT_MIN;
        for(int i=0;i<temp.size();i++){

               maxi=max(maxi,stoi(temp[i]));
        }
    return maxi;
    }
};