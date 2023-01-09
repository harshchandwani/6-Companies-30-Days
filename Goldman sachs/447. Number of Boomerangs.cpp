class Solution {
public:
    double dist(vector<int>& p1, vector<int>& p2) {
        return ((p2[0] - p1[0]) * (p2[0] - p1[0])) + ((p2[1] - p1[1]) * (p2[1] - p1[1]));
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        //map<int,int>map;
        for(int i = 0; i < n; i++){
            map<int,int>mp;
            for(int j = 0; j < n; j++){
                if(i != j){
                    int dis = dist(points[i], points[j]);
                    mp[dis]++;
                }
            }

            for(auto it: mp){
                ans += (it.second) * (it.second - 1);
            }
        }

        return ans;
    }
};