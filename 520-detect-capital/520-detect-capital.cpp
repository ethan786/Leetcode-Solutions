class Solution {
public:
    bool detectCapitalUse(string word) {
        string l = word;
         transform(l.begin(), l.end(), l.begin(), ::tolower);
        string u = word;
         transform(u.begin(), u.end(), u.begin(), ::toupper);
        if(word == u){
            return true;
        }else if(word  == l){
            return true;
        }else if((word[0] == toupper(word[0]))){
            int c = 0,i=0;
            while(i<word.size()){
                if(word[i] == toupper(word[i])) c++;
                i++;
            }
            return c==1 ? true : false;
        }else{
            return false;
        }
    }
};