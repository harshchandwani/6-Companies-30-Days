class Solution {
public:
    int maxCoins(vector<int>& piles) {
        //ide ais to always give the maximum element to alice and take second max as urs and minimum for bob
        sort(piles.begin(),piles.end());
        int res=0,cnt=0;
        int i=piles.size()-2,n=piles.size()/3;
        while(cnt<n && i>=0){
            cnt++;
            res+=piles[i];
            i-=2;

        }
        return res;
        
    }
};