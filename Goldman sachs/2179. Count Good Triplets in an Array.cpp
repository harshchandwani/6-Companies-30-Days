class Solution {
public:
    // function to return the last bit set in the input number
    inline int lastOne(int x) {
        return x & (-x);
    }
    
    // function to update a Fenwick tree with delta at index i
    void updateFenwickTree(vector<int>& fenwickTree, int index, int delta) {
        for(;index < fenwickTree.size(); index += lastOne(index)) {
            fenwickTree[index] += delta; 
        }
    }
    
    // function to get the prefix sum of the Fenwick tree up to index i
    int getPrefixSum(vector<int>& fenwickTree, int index) {
        int prefixSum = 0; 
        for(;index;index -= lastOne(index)) {
            prefixSum += fenwickTree[index];
        }
        return prefixSum; 
    }
    
    // function to get the range sum of the Fenwick tree between startIndex and endIndex
    int getRangeSum(vector<int>& fenwickTree, int startIndex, int endIndex) {
        return getPrefixSum(fenwickTree,endIndex) - (startIndex == 1?0:getPrefixSum(fenwickTree,startIndex-1));
    }
    
    // main function to find good triplets
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        // get the size of the input vectors
        const int vectorSize = nums1.size(); 
        // create a vector to hold the index positions of nums1
        vector<int> indexPositions(vectorSize);
        for(int i = 0; i < vectorSize; i++) {
            indexPositions[nums1[i]] = i;
        }
        // variable to count the number of good triplets
        long long goodTripletCount = 0; 
        // create a Fenwick tree with size n + 5
        vector<int> fenwickTree(vectorSize + 5);
        // create a vector to hold the number of elements smaller than nums2[i] in nums1 to the right of nums1[i]
        vector<int> smallerElementsToRight(vectorSize);
        // loop through nums2 backwards
        for(int i = vectorSize - 1; i >= 0; i--) {
            // get the index position of nums2[i] in nums1
            int index = indexPositions[nums2[i]];
            // store the number of elements smaller than nums2[i] in nums1 to the right of nums1[i]
            smallerElementsToRight[nums2[i]] = getRangeSum(fenwickTree,index + 1,vectorSize + 1);
            // update the Fenwick tree at index j + 1
            updateFenwickTree(fenwickTree,index + 1,1);
        }
        // reset the Fenwick tree
        fenwickTree.assign(vectorSize + 5,0);
        // loop through nums2 forwards
        for(int i = 0; i < vectorSize; i++) {
            // get the index position of nums2[i] in nums1
            int index = indexPositions[nums2[i]];
            // count the number of good triplets using the stored values
            long long smallerElementsBefore = getPrefixSum(fenwickTree,index);
            goodTripletCount += smallerElementsBefore * smallerElementsToRight[nums2[i]];
            // update the Fenwick tree at index j + 1
            updateFenwickTree(fenwickTree,index + 1,1);
        }
    return goodTripletCount;
    }
};