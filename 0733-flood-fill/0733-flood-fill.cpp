class Solution {
       int dr[4]={0,1,0,-1};
       int dc[4]={-1,0,1,0};
      void  solve(int sr, int sc,int init_color, vector<vector<int>> &image,int color){
          int m=image.size();
         int n=image[0].size();
            image[sr][sc]=color;
          for(int i=0;i<4;i++){
                int nr=dr[i]+sr;
                int nc=dc[i]+sc;

                if(nr<m && nc<n &&  nr>=0 && nc>=0 && image[nr][nc]==init_color){
                      image[nr][nc]=color;
                      solve(nr,nc,init_color,image,color);
                }
          }
      }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int init_color=image[sr][sc];
          if (init_color == color)
            return image;

        solve(sr,sc,init_color,image,color);
        return  image;
    }
};