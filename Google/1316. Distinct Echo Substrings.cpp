class Solution {
public:  
    bool check(string &s){
        int j=s.size()/2;
        
        for(int i=0;i<(s.size()/2);i++){
            if(s[i]!=s[j])return false;
            j++;
        }
        return true;
    }
    
    int distinctEchoSubstrings(string text) {
               
        unordered_set<string>s;
        
        for(int i=0;i<text.size();i++){
            string ans="";
            for(int j=i;j<text.size();j+=2){
                ans+=text[j];
                if(j+1<text.size())ans+=text[j+1];
                else break;
                
                if(check(ans))s.insert(ans);
            }
        }
        
        return s.size();
    }
};
