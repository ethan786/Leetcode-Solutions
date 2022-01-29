class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int n=heights.size();
        int res=0,curr=0;
        for(int i=0;i<heights.size();i++)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                int top=s.top();s.pop();
                curr=heights[top]*(s.empty()?i:(i-s.top()-1));
                res=max(res,curr);
            }
            s.push(i);
        }
        while(!s.empty())
        {
            int top=s.top();s.pop();
            curr=heights[top]*(s.empty()?n:(n-s.top()-1));
            res=max(res,curr);
        }
        return res;
    }
};