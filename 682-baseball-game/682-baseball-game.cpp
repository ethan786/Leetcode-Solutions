class Solution {
public:
    int calPoints(vector<string>& ops) {
	
        stack<int> points;
		
        int length=ops.size(),temp1,temp2,ans=0;
		
        for(int i=0;i<length;i++){
		
            if(ops[i]=="C")
                points.pop();
				
            else if(ops[i]=="D")
                points.push(points.top()*2);
				
            else if(ops[i]=="+"){
                temp1=points.top();
                points.pop();
                temp2=points.top();
                points.push(temp1);
                points.push(temp1+temp2);
            }
			
            else{
                temp1=stoi(ops[i]);
                points.push(temp1); 
            }
			
        }
        while(points.size()>0){
		
            ans=points.top()+ans;
            points.pop();
			
        }
		
        return ans;        
    }
};