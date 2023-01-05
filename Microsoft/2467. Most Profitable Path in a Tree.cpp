class Solution {
    vector<int> timeMap;
    vector<bool> vis;
    unordered_map<int, vector<int>> g;
    int ans = INT_MIN;

    bool callForBob(int bob, int sec){
        if(bob == 0){
            timeMap[bob] = sec;
            return true;
        }

        vis[bob] = 1;
        bool canReach = 0;
        for(auto it:g[bob]){
            if(vis[it]) continue;
            if(callForBob(it, sec+1) == true){
                canReach = 1;
                break;
            }
        }
        vis[bob] = 0;

        if(canReach == 1){
            timeMap[bob] = sec;
            return true;
        }
        return false;
    }

    void callForAlice(int node, int sec, int cost, vector<int> &amount){
        vis[node] = 1;

        if(timeMap[node] > sec)
            cost += amount[node];
        else if(timeMap[node] == sec)
            cost += (amount[node])/2;
        
        for(auto it:g[node]){
            if(vis[it]) continue;
            callForAlice(it, sec+1, cost, amount);
        }
        vis[node] = 0;
        if(node != 0 && g[node].size() == 1){
            ans = max(ans, cost);
        }
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        // forming the tree as a undirected graph
        for(auto it:edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        // visited array of size n
        vis.resize(n);
        timeMap.resize(n, INT_MAX);

        int sec = 0;
        callForBob(bob, sec);

        callForAlice(0, sec, 0, amount);

        return ans;
    }
};