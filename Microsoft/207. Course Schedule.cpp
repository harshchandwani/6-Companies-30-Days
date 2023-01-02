// class Solution {
// public:

//     bool isCyclic(vector<vector<int>>& adj, vector<int>& visited, int curr){
//         if(visited[curr] == 2){
//             return true;
//         }
//         visited[curr] = 2;
//         for(int i = 0; i < adj[curr].size(); i++){
//             if(visited[adj[curr][i]] != -1){
//                 if(isCyclic(adj, visited, adj[curr][i]))
//                     return true;
//             }
//         }

//         visited[curr] = 1;
//         return false;
//     }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);
//         vector<vector<int>> adj(numCourses);
        
//         for(int i = 0; i < prerequisites.size(); i++){
//             adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
//         }

//         vector<int>visited(numCourses, 0);
//         for(int i = 0; i < numCourses; i++){
//             if(visited[i] == 0){
//                 if(isCyclic(adj, visited, i))
//                     return false;
//             }
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool solve(int x,vector<vector<int>>&grid,vector<bool>&visit,vector<bool>&st){
        visit[x]=true;
        st[x]=true;
        bool ans=true;
        cout<<x<<" ";
        for(auto it:grid[x]){
            if(st[it]){
                ans= false;
                break;
            }
            if(!visit[it]&&!solve(it,grid,visit,st)){
                ans=false;
                break;
            }
        }
        st[x]=false;
        return ans;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>grid(n);
        for(auto it:prerequisites){
            grid[it[0]].push_back(it[1]);
        }
        vector<bool>visit(n+1,false);
        vector<bool>st(n+1,false);
        for(int x=0;x<n;x++){
            if(!visit[x])
                if(!solve(x,grid,visit,st))
                    return false;
            cout<<endl;
        }
        return true;
    }
};
