class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n,vector<int>(n,0));
    int rs = 0, cs = 0 ,re = n-1, ce = n-1;
    int k = 1;
    while(cs <= ce){
        for (int i = cs; i <= ce; ++i)
        {
            ans[rs][i] = k;
            k++;
        }
        rs++;
        for (int i = rs; i <= re; ++i)
        {
            ans[i][ce] = k;
            k++;
        }
        ce--;
        for (int i = ce; i >= cs; --i)
        {
            ans[re][i] = k;
            k++;
        }
        re--;
        for (int i = re; i >= rs; --i)
        {
            ans[i][cs] = k;
            k++;
        }
        cs++;
    }   
    return ans;     
}
};