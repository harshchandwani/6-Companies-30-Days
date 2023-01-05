class Solution {
public:

    long long merge(int l, int mid, int r, vector<int>&arr, int &diff)  // merges two array after evaluation
    {
        long long cnt=0;
        int i=l, j= mid+1;
        while(i<=mid && j<=r)
        {
            if(arr[i]<=arr[j]+diff)    // base condition
            {
                cnt+= (r-j+1);   // number of elements from right side that hold condition 
                i++;
            }
            else
            {
                j++;
            }
        }
        sort(arr.begin()+l,arr.begin()+r+1);    
        return cnt;
    }
    
    long long mergesort(int l, int r, vector<int>&arr, int &diff)
    {
        if(l==r)
            return 0;
        int mid= (l+r)/2;
        long long cnt=0;
        cnt+= mergesort(l,mid,arr,diff);
        cnt+= mergesort(mid+1,r,arr,diff);
        cnt+= merge(l,mid,r,arr,diff);
        return cnt;
    }
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        
        vector<int>arr(nums1.size());
        for(int i=0;i<nums1.size();i++)
            arr[i]=nums1[i]-nums2[i];    // take difference of both arrays to perform merge sort easily 
        
        return mergesort(0,nums1.size()-1,arr,diff);
    }
};
//TLE SOLUTION
// class Solution {
// public:
//     long long numberOfPairs(vector<int>& num1, vector<int>& num2, int diff) {
//         int n = num1.size();
//         long long count = 0;
//         for(int i = 0;i < n-1; i++){
//             for(int j = i + 1; j < n; j++){
//                 if(num1[i] - num1[j] - num2[i] + num2[j] <= diff){
//                     count++;
//                 }
//             }
//         }


//         return count;
//     }
// };