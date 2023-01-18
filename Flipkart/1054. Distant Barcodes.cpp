class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> ans(barcodes.size(), 0);
		// step 1
        unordered_map<int, int> m;
        for (int i: barcodes) {
            m[i]++;
        }
		// step 2
        priority_queue<pair<int, int>> pq;
        for (auto it=m.begin(); it != m.end(); ++it) {
            pq.push({it->second, it->first});
        }
		// step 3
        int index = 0;
        int key, value;
        while (!pq.empty()) {
            key = pq.top().second;
            value = pq.top().first;
            pq.pop();
            while (value != 0) {
                if (index >= ans.size()) index = 1;  // All the even positions have been used.
                ans[index] = key;
                --value;
                index += 2;
            }
        }
        return ans;
    }
};
