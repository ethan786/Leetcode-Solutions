class NumMatrix {
public:
    vector<vector<int>> a;
    NumMatrix(vector<vector<int>>& m) {
        int n = m.size();
        int x = m[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<x;j++){
               m[i][j] += m[i][j-1];
            }
        }
        a = m;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        int  j = col2;
        for(int i = row1;i<=row2;i++){
            int k = (col1 - 1 >= 0 ? col1 - 1 : -1);
            if(k != -1){
                sum += (a[i][j] - a[i][k]);
                //cout<<a[i][j]<<" "<<a[i][k]<<endl;
            }else{
                sum += a[i][j];
            }
        }
        return sum;
    }
    
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */