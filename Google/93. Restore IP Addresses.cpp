class Solution {
public:
    vector<string>ans;
    vector<string> restoreIpAddresses(string s) {
        vector<string>a;
        backtrack(s,a);
        return ans;
    }
    void backtrack(string s, vector<string>a)
    {
        if(s.size()==0) return;
        if(a.size()==3)
        {
            if(s.size()>4) return;
            int b=stoi(s);
            if(b==0 && s.size()>1 || b>255) return;
            if(s.size()>1 && s[0]=='0') return;
            ans.push_back(a[0]+'.'+a[1]+'.'+a[2]+'.'+s);
            return;
        }
        string st;
        int i=0;
        for(i=0;i<3;i++)
        {
            st+=s[0];
            if((stoi(st)==0 && st.size()>1) || stoi(st)>255 || (st[0]=='0' && st.size()>1))
                return;
            a.push_back(st);
            s.erase(s.begin());
            backtrack(s,a);
            a.erase(a.begin()+a.size()-1);
            if(s.size()==0)
                return;
        }
        return;
    }
};
