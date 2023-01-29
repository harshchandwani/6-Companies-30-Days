class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int >>v(nums1.size()+1,vector<int >(nums2.size()+1,0));
        int res=0;
        for(int i=0;i<=nums1.size();i++){
            for(int j=0;j<=nums2.size();j++)
            {
                if(i==0 or j==0){
                    v[i][j]=0;
                }
                else if(nums1[i-1]==nums2[j-1]){
                    v[i][j]=(v[i-1][j-1]+1);
                    res=max(res,v[i][j]);
                }
            }
        }
        
        return res;
    }
};
