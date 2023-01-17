/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &nums) {
        int low = 0;
        int high = nums.length() - 1;
        

        //first half
        while(low <= high){
            int mid = (low + high)/2;
            if(nums.get(mid) < nums.get(mid + 1) && nums.get(mid) < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        if(nums.get(low) == target){
            return low;
        }
        high = nums.length() - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums.get(mid) < nums.get(mid - 1) && nums.get(mid) < target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(nums.get(high) == target){
            return high;
        }
        return -1;
    }
};
