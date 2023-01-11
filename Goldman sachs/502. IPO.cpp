class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int>q;
        int i=0;
        vector<pair<int, int>>v;
        for(int i=0; i<profits.size(); i++){
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end());
        while(i<v.size() && k){
            if(w>=v[i].first){
                q.push(v[i].second);
                i++;
            }
            else{
                if(q.empty()){
                    return w;
                }
                else{
                    w+=q.top();
                    q.pop();
                    k--;
                }
            }
        }
        while(k-- && !q.empty()){
            w+=q.top();
            q.pop();
        }
        return w;
    }
};