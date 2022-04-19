class Solution {
public:
    vector<int> splitToNums(string s) {
        if(s.size()==0) return {};
        vector<int>res;
        
        int start = 0, end = s.find("."); 
        while (end != -1) {
            string temp = s.substr(start, end - start); //spliting the string by '.'
            res.push_back(stoi(temp));  // converting to num and pushing in array
            start = end + 1;   // updating start and end index for next split
            end = s.find(".", start); 
        }
        string last = s.substr(start, end - start); // last version
        res.push_back(stoi(last));
        return res;
    }
    int compareVersion(string v1, string v2) {
        vector<int>A = splitToNums(v1);
        vector<int>B = splitToNums(v2);
        int m = A.size(), n = B.size(), i=0;
        
        for(int i=0; i<m || i<n; i++) {
            if(i<m && i<n) {
                if(A[i]==B[i]) continue;
                return A[i]<B[i] ? -1 : 1; 
            } 
            else if(i < m && A[i] != 0) {
                return  1; // v1 greater
            } 
            else if(i<n && B[i] != 0 ){
                return -1; // v2 is greater
            }
        }
        return 0;
    }
};