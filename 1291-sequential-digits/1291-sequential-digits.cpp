// class Solution {
// public:
    
//     int count(int x){
//         return floor(log10(x) + 1);
//     }
    
//     bool is(int f){
//         while(f){
//             int last = f%10;
//             f/=10;
//             int slast = -63515;
//             if(f){
//              slast = f%10;
//             }
//             if(slast == -63515) return true;
//             if(slast>last) return false;
//         }
//         return true;
//     }
    
//     vector<int> sequentialDigits(int low, int high) {
//         //find we have to find the first number that will fit our condition
//         //then we have to add only 11...11..1.111 to it to make every digit one
//         //more than the previous
//         // int find_first_digit;
//         int n = low;//first digit of low
//         while(n > 9){
//             n/=10;
//         }
//         int lower_count_digit = count(low);
//         int upper_count_digit = count(high);
//         int f =1,add =1;
//         for(int i =2;i<=lower_count_digit;i++){
//             f = f*10+i;
//             add = add*10+1;
//         }
//         vector<int> ans;
//         int c=10;
//         bool flag = false;
//         while(c--){
//             if(f>= low and f<= high){
//                 flag = true;
//                 break;
//             }else{
//                 f += add;
//             }
//         }
//         while(flag){
            
//             if(f>= low and f<= high and is(f)){
//                 ans.emplace_back(f);
//             }else if((add*10+1) >= low and (add*10+1) <= high){
//                 add = add*10+1;
//             }else{
//                 break;
//             }
//             cout<<add<<" ";
//             if(is(f)){
//             f+=add;
//             }
//             cout<<f<<" ";
            
//         }
//         //cout<<lower_count_digit<<upper_count_digit;
//         return ans;
        
//     }
// };
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        int num = 0;
        for(int i = 1; i<10 ; i++)
        {
            num = i;
            for(int j = i+1;j<10;j++)
            {
                num = num*10 + j;
                if(num >= low && num <= high)
                {
                    result.push_back(num);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};