class Solution
{
  public:
    vector<string> cellsInRange(string s)
    {
        vector<string> result;
        string temp = "";
        for (char i = s[0]; i <= s[3]; i++)
        {
            temp = "";
            temp += i;
            for (char j = s[1]; j <= s[4]; j++)
            {
                temp += j;
                result.push_back(temp);
                temp.pop_back();
            }
        }
        return result;
    }
};