class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>mp;
        if( k > s.size()){
            return false;
        }
        for(int i =0;i<=s.size()- k; i++){
            mp.insert(s.substr(i,k));
        }
        if(mp.size() == pow(2, k)){
            return true;
        }
        else{
            return false;
        }
        return false;
    }
};
