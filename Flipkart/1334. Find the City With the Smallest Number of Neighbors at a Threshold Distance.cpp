class Solution {
public:
    
    // custom comparator for minimum priority queue <node,distance> based on distance 
    struct comparator { 
        bool operator()(pair<int,int> const& a, pair<int,int> const& b) 
        { 
            return a.second > b.second;
        } 
    }; 
  
    int findTheCity(int n, vector<vector<int>>& edges, int K) {
        
        // graph adjacency list of  nodes and weights
        vector<vector<pair<int,int>>>graph(n);
        
        // populate graph adjacency list <node, distance>
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
            graph[edges[i][1]].push_back(make_pair(edges[i][0],edges[i][2]));
        }
        
        // distance vector of nodes
        vector<int>distance(n);
        
        // minimum priority queue <node,distance> based on distance
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator>Q;
        
        // minimum visited node count of nodes
        int minNodeCount = INT_MAX;

		// city with smallest number of neighbors at athreshold distance
        int expectedCity;
        
        // run BFS / Dijkstra from every node and count the number of visited nodes with in threshold distance
        for(int i=0;i<n;i++)
        {
            int source = i;
            
            // set distance of all nodes to threshold + 1
            fill(distance.begin(),distance.end(),K+1);
            
            // push the source node with distance 0 as it is the source node
            Q.push(make_pair(source,0));
            distance[source] = 0;
            
            while(!Q.empty())
            {                
                int node = Q.top().first;
                int node_dis = Q.top().second;
                Q.pop();
                
                // ignore nodes which has lowest distance than the node distance in queue means already visited
                if(distance[node]<node_dis) continue;
                
                // add neighbour nodes in to queue which has higher distance than current node distance + edge distance   
                for(int j=0;j<graph[node].size();j++)
                {
                    int neighbour = graph[node][j].first;
                    int edge_dis = graph[node][j].second;
                    
                    if(edge_dis+distance[node]<distance[neighbour])
                    {
                        distance[neighbour] = distance[node] + edge_dis;
                        Q.push(make_pair(neighbour,distance[neighbour]));
                    }
                }
            }
            
            // count the number of visited nodes in threashold distance
            int visitCount = 0;
            for(int j=0;j<n;j++)
                if(source!=j && distance[j]<=K)visitCount++;                

            // update minNodeCount if count is less or equal cause 
            // we need larger node/city number incase of equal count 
            if(minNodeCount>=visitCount)
            {
                expectedCity = source;
                minNodeCount = visitCount;
            }
        }
        
        return expectedCity;
    }
};
