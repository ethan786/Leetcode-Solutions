class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        int n = a.size();
        if(n == 0){
            return {};
        }
        if(n == 1){
            return {to_string(a[0])};
        }
        vector<string> ans;
        string x = "";
        int s;
        int e;
        bool fs = false;
        for(int i=0;i<n-1;i++){
            if(a[i] == a[i+1] - 1){
                //(s == 'a') ? s = a[i] :
                if(!fs){
                    s = i;
                    fs = true;
                }
            }else{
                e = i;
                if(!fs){
                    x += (to_string(a[e]));
                }else{
                    x += (to_string(a[s]));
                    x += ("->");
                    x += (to_string(a[e]));            
                }
                ans.push_back(x);
                x = "";
                fs = false;
            }
        }
        if(fs == true){
            e = n-1;
            x = "";
            x += (to_string(a[s]));
            x += ("->");
            x += (to_string(a[e]));
            ans.push_back(x);
        }
        int xsize = ans.size();
        string last = ans[xsize-1];
        int lastint = last[last.size()-1] - '0';
        //cout<<lastint;
        if(lastint != a[n-1] and fs == false){
            ans.push_back(to_string(a[n-1]));
        }
        return ans;
    }
};