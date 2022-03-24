class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<int,int> even;
        int even_max_freq=0,even_max_element=0,even_sec_max_freq=0,even_sec_max_element=0;
        //Largest and SecondLargest Frequency element at even index
        for(int i=0;i<n;i=i+2){
            even[nums[i]]++;
            if(even[nums[i]]>even_max_freq){
                even_max_element=nums[i];
                even_max_freq=even[nums[i]];
            }
            else if(even[nums[i]]<=even_max_freq && nums[i]!=even_max_element && even_sec_max_freq<even[nums[i]]){
                even_sec_max_element=nums[i];
                even_sec_max_freq=even[nums[i]];
            }
        }
        unordered_map<int,int> odd;
        int odd_max_freq=0,odd_max_element=0,odd_sec_max_freq=0,odd_sec_max_element=0;
        //Largest and SecondLargest Frequency element at odd index
        for(int i=1;i<n;i=i+2){
         odd[nums[i]]++;
            if(odd[nums[i]]>odd_max_freq){
             odd_max_element=nums[i];
             odd_max_freq=odd[nums[i]];
            }
            else if(odd[nums[i]]<=odd_max_freq && nums[i]!=odd_max_element && odd_sec_max_freq<odd[nums[i]]){
                odd_sec_max_element=nums[i];
                odd_sec_max_freq=odd[nums[i]];
            }
        } 
        if(even_max_element!=odd_max_element){
            return n-even_max_freq-odd_max_freq;
        }
        else{
          return  min(n-odd_max_freq-even_sec_max_freq,n-even_max_freq-odd_sec_max_freq);
        }
        return 0;
    }
};