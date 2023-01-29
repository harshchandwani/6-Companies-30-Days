class Solution {
    public:
    vector<int>ans, aq;
        Solution(vector<int>& nums) {
                ans = nums;
                        aq = nums;
                                // return nums;

                                    }
                                        
                                            vector<int> reset() {
                                                    return aq;
                                                        }
                                                            
                                                                vector<int> shuffle() {
                                                                        random_shuffle(ans.begin(), ans.end());
                                                                                return ans;
                                                                                    }
                                                                                    };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 
 = obj->shuffle();
 */
