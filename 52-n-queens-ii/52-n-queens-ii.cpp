class Solution {  
private:
	int res;
public:
	void dfs(int n,int dep,int r,int d1, int d2){
		if(dep==n){
			res++;
			return;
		}
		for(int i=0;i<n;i++){
			int cur=1<<i;
			if((cur&r) || (cur&d1) || (cur&d2)) continue;
			dfs(n,dep+1, (cur|r),(cur|d1)<<1,(cur|d2)>>1);
		}

	}
	int totalNQueens(int n) {
		res=0;
		dfs(n,0,0,0,0);
		return res;
	}
};