class Solution {
public:
        int calPoints(vector<string>& ops) {
        vector<int> rounds;
        int lastIndex=0;
        
        for(string str : ops){
            if(isdigit(str[0]) || str[0] == '-'){
                rounds.push_back(std::stoi(str));
            }
            else if(str[0] == '+'){
                rounds.push_back(rounds[lastIndex]+rounds[lastIndex-1]);
            }
            else if(str[0] == 'D'){
                rounds.push_back(2*rounds[lastIndex]);
            }
            else if(str[0] == 'C'){
                rounds.pop_back();
            }
            
            lastIndex = rounds.size()-1;
        }
        
        return accumulate(rounds.begin(), rounds.end(),0); // calculates sum of vector
    }
};