class Solution {
public:
    
    int count(vector<int>& a){
        int c = 0;
        int ans = 0;
        for(int i=0;i<a.size();i++){
            if(a[i] == 1){
                c++;
            }else{
                c=0;
            }
            ans = max(ans,c);
        }
        return ans;
    }
    
    int longestOnes(vector<int>& a, int k) {
        if(k==0){
            return count(a);
        }
        int i=0,j=0;
        int ans = 0;
        while(j < a.size()){
            if(a[j] == 0 and k > 0){
                //cout<<"x";
                k--;
                j++;
            }else if(a[j] == 1){
                //cout<<"y";
                j++;
            }else if(a[j] == 0 and k <= 0){
                //cout<<"z";
                while(i<j and k <= 0){
                    //cout<<"m";
                    if(a[i] == 0){
                        //cout<<"n";
                        k++;
                    }
                    i++;
                }
            }
            ans = max(ans,j-i);
        }
        return ans;
    }
};