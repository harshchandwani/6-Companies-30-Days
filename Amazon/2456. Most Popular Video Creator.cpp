class Solution {
public:
     vector<vector<string>> mostPopularCreator(
        const vector<string>& creators, const vector<string>& ids, const vector<int>& views) {
        const int n = size(creators);
        unordered_map<string, tuple<long, long, string>> vpcs;
        long mvpc = 0;
        for (int i = 0; i < n; ++i) {
            auto it = vpcs.find(creators[i]);
            if (it == end(vpcs)) {
                mvpc = max<long>(mvpc, views[i]);
                vpcs[creators[i]] = {views[i], views[i], ids[i]};
            } else {
                mvpc = max(mvpc, get<0>(it->second) += views[i]);
                if (views[i] > get<1>(it->second)) {
                    get<1>(it->second) = views[i];
                    get<2>(it->second) = ids[i];
                } else if (views[i] == get<1>(it->second)) {
                    get<2>(it->second) = min(get<2>(it->second), ids[i]);
                }
            }
        }
        vector<vector<string>> ans;
        for (const auto& [creator, v] : vpcs)
            if (get<0>(v) == mvpc) ans.push_back({creator, get<2>(v)});

        return ans;
    }
};
