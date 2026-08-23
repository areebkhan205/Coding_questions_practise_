class Solution {
public:
    int countVowelSubstrings(string word) {
         int cnt=0;
         for(int f=0;f<word.size();f++){
            int a=0,e=0,i=0,o=0,u=0;
             for(int j=f;j<word.size();j++){
                  if(word[j]!='a' && word[j]!='e' && word[j]!='o' && word[j]!='i' && word[j]!='u' ){
                        break;
                  }
                  if(word[j]=='a')a++;
                  else if(word[j]=='e')e++;
                  else if(word[j]=='o')o++;
                  else if(word[j]=='i')i++;
                  else if(word[j]=='u'){
                    u++;
                  }
                      


                      if(a>0 && i>0 && o>0 && u>0  && e>0){
                        cnt++;
                      }
                  
                               }
         }
    return cnt;
    }
};