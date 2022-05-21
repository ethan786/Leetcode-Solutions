class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool isSub ;
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j)
    {
        if(i<0 || j<0 || i>= grid2.size() || j>= grid2[0].size() || grid2[i][j]==0){
            return;
        }

        grid2[i][j] = 0;
        
        if(grid1[i][j] == false){
            isSub = false;
        }
      
        for(int k=0;k<4;k++){
                dfs(grid1,grid2,i+dx[k],j+dy[k]);
        }

    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int count =0;
        for(int i=0;i<grid2.size();i++)
        {
            for(int j=0;j<grid2[0].size();j++)
            {
                if(grid2[i][j] == 1 and grid1[i][j] == 1)
                {
                    isSub = true;
                    dfs(grid1,grid2,i,j);
                    if(isSub)
                        count++;
                }
            }
        }

        return count;

    }
};