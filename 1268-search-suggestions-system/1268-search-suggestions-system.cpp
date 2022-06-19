class trie{
   public:
   vector<trie*> next;
   vector<int> index;
   trie()
   {
       next.resize(26,0);
   }
   void insert(string x,int j)
   {
      trie* temp=this;
       
       for(int i=0;i<x.length();i++)
       {
           if(temp->next[x[i]-'a']==NULL)
               temp->next[x[i]-'a']=new trie();
           temp=temp->next[x[i]-'a'];
           temp->index.push_back(j);
       }
   }
   vector<vector<int>> find(string x)
   {
       trie* temp=this;
       vector<vector<int>> res;
       int i;
       for(i=0;i<x.length();i++)
       {
           int j=0;
           vector<int> p;
           temp=temp->next[x[i]-'a'];
            if(temp==NULL)
               break;
           else
           {
                for(auto z:temp->index)
                {
                      p.push_back(z);
                      j++;
                      if(j==3)
                      break;
                }
                res.push_back(p);
           }
       }
       while(i<x.length())
       {
           res.push_back({});
           i++;
       }
       return res;
   }
};
class Solution {
public:
   trie* root;
   vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
       root=new trie();
       vector<vector<string>> res;
      sort(p.begin(),p.end());
       for(int i=0;i<p.size();i++)
       {
          root->insert(p[i],i); 
       }
       vector<vector<int>> index_array=root->find(s);
   	
   	//with the help indices extracting the strings from p
   	
       for(auto x:index_array)
       {
           vector<string> temp;
           for(auto y:x)
               temp.push_back(p[y]);
           res.push_back(temp);
       }
       return res;
   }
};