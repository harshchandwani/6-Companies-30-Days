class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& nums) {
        int n = nums.size();
        int maxDiff = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; i++){
            int temp = nums[i] - nums[i - 1];
            maxDiff = max(maxDiff, temp);
        }

        int op1 = top - nums[n-1];
        int op2 = bottom - nums[0];
        op1 = abs(op1);
        op2 = abs(op2);
        maxDiff -= 1;

        int ans = max(maxDiff, max(op1, op2));
        if(ans == 1){
            return 0;
        }
        return ans;
    }
};