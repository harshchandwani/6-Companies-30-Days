
class Solution {
public:

//    int gcd(int a, int b)
//     {
//     if (a == 0)
//         return b;
//     return gcd(b % a, a);
//     }
 
//     // Function to find gcd of array of
//     // numbers
//     int findGCD(vector<int>arr, int n)
//     {
//         int result = arr[0];
//         for (int i = 1; i < n; i++)
//         {
//             result = gcd(arr[i], result);
        
//             if(result == 1)
//             {
//             return 1;
//             }
//         }
//         return result;
//         }
   int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int GCD = 0;
        for(auto &i : numsDivide) GCD = __gcd(GCD, i);
        int count=0;
        int n = size(nums), sz = size(nums);
        for(int i = 0; i < n; i++){
            if( (nums[i] == GCD) or (GCD % nums[i]==0)) break;
            else sz--;
        }
        if(sz == 0) return -1;
        return n - sz;
    }
};