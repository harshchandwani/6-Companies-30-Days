class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n/5 != 0){
            ans += n/5;
            n = n/5;
        }
        return ans;
    }
};

//Baically, we are doing calculating the number of 5 in the number
