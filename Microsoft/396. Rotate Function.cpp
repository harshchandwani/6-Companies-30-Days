class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int curr = 0, res = 0, sum = 0;
        for(int i = 0;i < n; i++){
            curr += i * nums[i];
            sum += nums[i];
        }
        res = curr;

        for(int i = 0;i < n; i++){
            //we are making last digit 0,
            //and adding total sum of the nums to the curr
            //and have the max of the res and curr
            //Basically in every next step we are increasing the occurence of every number by 1
            //except the last digit, which will be zero
        

            curr -= n * nums[n - i - 1];
            curr += sum;
            res = max(curr, res);
        }
        return res;
    }
};