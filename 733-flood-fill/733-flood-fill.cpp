class Solution {
public:
    
    void dfs(int i,int j,int nc,vector<vector<int>>& image,int start){
        if(i > image.size()-1 || j > image[0].size()){
            return;
        }
        if(i < 0 || j < 0){
            return;
        }
        if(image[i][j] == nc || image[i][j] != start){
            return;
        }
        image[i][j] = nc;
        dfs(i+1,j,nc,image,start);
        dfs(i,j-1,nc,image,start);
        dfs(i-1,j,nc,image,start);
        dfs(i,j+1,nc,image,start);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int nc)     {
       dfs(sr,sc,nc,image,image[sr][sc]);
        return image;
    }
};