class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
         vector<int> ans;
        int n=s.size();
        int m=words.size();
        int k=words[0].size();
        unordered_map<string,int> freq,temp;
        for(string q:words) temp[q]++;
        
        for(int i=0;i<k;i++){
            int l=i;
            freq.clear();
            for(int j=i;j+k<=n;j=j+k){
                
                string curr=s.substr(j,k);
                if(temp.find(curr)==temp.end()){
                    freq.clear();
                    l=j+k;
                    continue;
                 }
               freq[curr]++;
               while(freq[curr]>temp[curr]){
                   string p=s.substr(l,k);
                    freq[p]--; if(freq[p]==0) freq.erase(p);
                    l=l+k;
                }
               if(j==l+k*(m-1)){
                    ans.push_back(l);
                    string p=s.substr(l,k);
                    freq[p]--; if(freq[p]==0) freq.erase(p);
                   l=l+k;
               }
            }
        }
        return ans;
    }
};