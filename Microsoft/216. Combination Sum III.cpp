class Solution {
public:
    void helper(int i,int k, int n, vector<vector<int>>&ans, vector<int>&subset){
        if(n == 0 && k == 0){
            ans.push_back(subset);
            return;
        }
        if(k < 0 || n < 0 || i == 10){
            return;
        }
        //we are including the current element
        subset.push_back(i);
        helper(i+1,k-1,n - i,ans, subset);
        subset.pop_back();
        
        //we are NOT including the current element
        helper(i+1,k, n, ans, subset);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>subset;
        helper(1,k, n, ans, subset);
        return ans;
    }
};