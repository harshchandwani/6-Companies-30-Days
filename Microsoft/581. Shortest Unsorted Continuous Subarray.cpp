class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1;
        int end = n;

        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            if(maxi < nums[i]){
                maxi = nums[i];
            }
            if(maxi > nums[i]){
                end = i;
            }
        }

        int mini = INT_MAX;
        for(int i = n - 1;i >= 0; i--){
            if(mini > nums[i]){
                mini = nums[i];
            }
            if(mini < nums[i]){
                start = i;
            }
        }
         if(start == -1){
            return 0;
        }
        return (end - start + 1);
    }
};