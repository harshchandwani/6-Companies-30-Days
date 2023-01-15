
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n  = matrix.size();
        int m = matrix[0].size();

        //basically in this ques, we dont need to change each number
        //just calculate the sum]
        //if the number is +ve, add such
        //if the number is -ve, add by multiplying -1 to it,
        long long sum = 0; //this will store the sum 
        long long mini = INT_MAX; //it will store the minimum element, if the no. of -ve numbers are odd
        long long count = 0;  //will store the number of -ve numbers 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                long long curr = abs(matrix[i][j]);
                mini = min(mini, curr);
                if(matrix[i][j] < 0){
                    count++;
                }
                sum += curr;
            }
        }

        if(count % 2 == 0){
            return sum;
        }
        else{
            return (sum - 2*(mini));
        }
    }
};
