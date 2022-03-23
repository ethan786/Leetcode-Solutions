class Solution {
public:
    string getSmallestString(int n, int k) {
        string character = "xabcdefghijklmnopqrstuvwxyz";
        string s = "";
        if(n == 1){
            return to_string(character[k-1]);
        }
        for(int i=1;i<=n;i++){
            int l = n-i;
            if( (l*26) > k-1 ){
                s += 'a';
                k--;
            }else{
                int nuksan = abs((l*26) - k);
                //cout<<nuksan<<endl;
                if(nuksan  == 0){
                    int x = l+1;
                    while(x--){
                        s += 'z';
                    }
                    return s;
                }else{
                    int c = abs(nuksan);
                    s += character[c];
                    k -= c;
                }
            }
        }
        return s;
    }
};