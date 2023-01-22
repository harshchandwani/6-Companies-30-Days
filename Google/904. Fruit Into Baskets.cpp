class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        unordered_map<int,int>map;
        int left = 0;
        int right = 0;
        for(right = 0; right < n; right++){
            map[nums[right]]++;          
            if(map.size() > 2){
                if (--map[nums[left]] == 0)map.erase(nums[left]);
               left++;
            }
            
        }
        return right - left;
    }
};