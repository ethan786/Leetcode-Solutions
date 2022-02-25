class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.length(),n2=version2.length();
        int num1=0,num2=0;
        int i=0,j=0;
        while(i<n1 || j<n2){
            while(i<n1 && version1[i]!='.'){
                num1=10*num1+(version1[i]-'0');
                i++;
            }
            while(j<n2 && version2[j]!='.'){
                num2=10*num2+(version2[j]-'0');
                j++;
            }
            if(num1<num2) return -1;
            else if(num1>num2) return 1;
            else{
                i++;
                j++;
                num1=0;
                num2=0;
            }
        }
        return 0;
    }
};