class Solution {
private:
    map<pair<int,vector<int>>,int>mp;               // for memorization of dp states
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(price,special,needs,0);
    }
    
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int> needs,int st){
        if(st==special.size()){
            int cost=0;
            for(int i=0;i<needs.size();++i){
                cost+=needs[i]*price[i];
            }
            return cost;
        }
        if(mp.find({st,needs})!=mp.end()) return mp[{st,needs}];
        vector<int>need=needs;
        for(int j=0;j<price.size();++j){
            need[j]=needs[j]-special[st][j];
            if(need[j]<0) return mp[{st,needs}]=solve(price,special,needs,st+1);
        }
        return mp[{st,needs}]=min(solve(price,special,needs,st+1),solve(price,special,need,st)+special[st][price.size()]);          // either choose it or don't choose
    }
};
