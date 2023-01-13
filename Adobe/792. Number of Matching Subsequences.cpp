class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length();
        unordered_map<string, int>map;
        for(int i=0;i<words.size();i++){
            map[words[i]]++;
        }
        
        int count =0;
        for(auto x:map){
            string p = x.first;
            int start1=0;
            int start2=0;
           while(start1 < n && start2 < p.length()){
            
            if(p[start2] == s[start1]){
                start1++;
                start2++;
            }
                else{
                    start1++;
                }
                
                
            
            }
            if(start2 == p.length()){
                    count += x.second;
                }
        }
        
        return count;
    }
};