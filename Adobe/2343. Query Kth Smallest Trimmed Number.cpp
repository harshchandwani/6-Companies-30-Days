class Solution {
    public:
        vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {


            //bascially we need to trim the nums until we have queries[i][0] digits left from the right.
            //and return the queries[i][1] smallest digit
            
            //for loop for queries
            // have a unordered map
            //lenOfDigit //the number of letter we need to trim
            //lenOfDigit = totallen - queries[i][0]
            //store in priority queue
            //get tthe accurate number and store in answer vector

            vector<int> ans;
            for (auto q: queries){
                int trim= q[1];
                int k= q[0];
                priority_queue<pair<string,int>> pq;
                for (int i=0; i<nums.size(); i++){
                    string  val= nums[i];
                    if (trim< nums[i].size()) val= nums[i].substr(nums[i].size()-trim,trim);

                    pair<string,int> val1= {val,i};
                    if (pq.size()<k){
                        pq.push(val1);
                    }
                    else{
                        if (val1 < pq.top()){
                            pq.pop();
                            pq.push(val1);
                        }
                    }
                }
                ans.push_back(pq.top().second);
            }
            return ans;
        }
};
