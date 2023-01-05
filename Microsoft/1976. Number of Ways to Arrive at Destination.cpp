#define mod 1000000007
#define pi pair<long, long>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Construct adjacency list representation of graph
        vector<pi> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // Initialize priority queue for Dijkstra's algorithm
        priority_queue<pi, vector<pi>, greater<pi>> q;
        // Initialize distances and number of ways to reach each node
        vector<long long> dist(n, LONG_MAX), ways(n, 0);
        // Add source node to queue and set its distance to 0 and number of ways to 1
        q.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        
        // Repeatedly extract minimum distance node and relax its neighbors
        while(!q.empty()){
            long long node = q.top().second, dis = q.top().first;
            q.pop();
            // Skip nodes that have already been processed
            if(dis > dist[node])
                continue;
            // Iterate over the current node's neighbors
            for(auto it : adj[node]){
                long long adjN = it.first, edW = it.second;
                // Relax the neighbor if the distance via the current node is shorter
                if(dist[adjN] > dis + edW){
                    dist[adjN] = dis + edW;
                    q.push({dist[adjN], adjN});
                    // Set the number of ways to reach this neighbor to the number of ways to reach the current node
                    ways[adjN] = ways[node];
                }
                // If the distance is the same, increment the number of ways to reach this neighbor
                else if(dist[adjN] == dis + edW)
                    ways[adjN] = (ways[adjN] + ways[node])%mod;
            }
        }
        // Return the number of ways to reach the destination node
        return ways[n-1]%mod;
    }
};