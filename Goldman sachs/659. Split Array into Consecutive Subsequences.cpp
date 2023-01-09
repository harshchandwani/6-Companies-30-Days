class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int>m, m1;//One for the availablity and one for the want
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto it: nums){
            if(!m[it]){continue;}
            if(m1[it]){
                m1[it]--; m1[it+1]++;
                m[it]--;
            }
            else{
                if(m[it] && m[it+1] && m[it+2]){
                    m[it]--; m[it+1]--; m[it+2]--;
                    m1[it+3]++;
                }
                else{return false;}
            }
        }
        return true;
    }
};