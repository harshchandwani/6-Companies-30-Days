class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            maxi=max(dp[i],maxi);
        }
        vector<int> ans(maxi);
        int prev=0;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==maxi && prev%nums[i]==0){
                ans[maxi-1]=nums[i];
                prev=nums[i];
                maxi--;
            }
        }
        return ans;
    }
};