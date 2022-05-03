class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        vector<int> b = a;
        sort(b.begin(),b.end());
        int x=-1,y=-1;
        bool flag = true;
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]){
                x = (flag) ? i : x;
                y = i;
                flag = false;
            }
        }
        if(x == -1) return 0;
        if(x == y) return 2;
        return y-x+1;
    }
};
