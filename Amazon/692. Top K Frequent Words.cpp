class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int, string>> vp;
        unordered_map<string, int> mp;
        
        for(string &word : words) {
            mp[word]++;
        }
        
        for(auto &it : mp) {
            vp.push_back({it.second, it.first});
        }
        
        auto lambda = [](pair<int, string>& p1, pair<int, string>& p2) {
            if(p1.first == p2.first)
                return p1.second < p2.second;
            
            return p1.first > p2.first;
        };
        
        sort(begin(vp), end(vp), lambda);
        
        int i = 0;
        vector<string> result(k);
        while(i < k) {
            result[i] = vp[i].second;
            i++;
        }
        
        return result;
    }
};
