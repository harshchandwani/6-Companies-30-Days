class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long sum = mass;
        for(int i = 0; i < n; i++){
            if(nums[i] <= sum){
                sum += nums[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};
