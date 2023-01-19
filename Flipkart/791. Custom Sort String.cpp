class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(auto i: s)
            mp[i]++;
        string ans;
        for(auto i: order)
        {
             if(mp.find(i)!=mp.end())
            {
                for(int j=0; j<mp[i]; j++)
                    ans.push_back(i);
                mp[i]=0;
            }
        }
         for(auto i: s)
        {
             if(mp.find(i)!=mp.end())
            {
                for(int j=0; j<mp[i]; j++)
                    ans.push_back(i);
                mp[i]=0;
            }
        }
        return ans;
    }
};
