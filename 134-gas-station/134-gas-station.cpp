// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         for(int i=0;i<n;i++){
//             if(gas[i] >= cost[i]){
//                 int c = 0;
//                 int cur_tank_cap = gas[i];
//                 int j = i;
//                 // while(c!=n){
//                 //     cur_tank_cap -= cost[j%n];
//                 //     //cout<<"1->"<<cur_tank_cap<<" ";
//                 //     if(cur_tank_cap<0) break;
//                 //     j++;
//                 //     c++;
//                 //     cur_tank_cap += gas[j%n];
//                 //     //cout<<"2->"<<cur_tank_cap<<" "<<endl;
//                 // }
                
//                 int next_station = 
                
//                 if(c==n){
//                     return i;
//                 }
//             }
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current = 0;
        int total = 0;
        int diff = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); i++){
            diff = gas[i] - cost[i];

            total += diff;
            current += diff;
            if(current < 0){
                start = i + 1;
                current = 0;
            }
        }

        if(total >= 0){
            return start;
        }

        return -1;
    }
};