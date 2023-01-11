class Solution {
public:
vector<int>ans;//answer array 
int maxpoints=0; //stores the maximum points by bob
    void solve(int ind,int score,int arrow,vector<int> &nums,vector<int> &res){
        if(arrow==0||ind<0){
            //if ind goes negitive or arrows count became 0.
            //Then check if current score is the maximum score .
            //If score is maximum the res array is ans array.
            if(score>maxpoints){
                maxpoints=score;
                ans=res;
            }
            return ;
        }
        //if available arrows is greater than the arrorws requires for the current score index then we can take this score.
        if(arrow>nums[ind]){
           res[ind]=nums[ind]+1;
            solve(ind-1,score+ind,arrow-(nums[ind]+1),nums,res);//taking the current index score.
          res[ind]=0;
           
        }
        //Here we are not taking the current index score.
        solve(ind-1,score,arrow,nums,res);
        
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>res(12,0);//To store the values of arrows used by bob
        solve(11,0,numArrows,aliceArrows,res);
        int cnt=0;
        for(auto it:ans){
            cnt+=it;

        }
        int startind=numArrows-cnt;
        if(startind>0){
            ans[0]+=startind;
        }
         return ans;
    }
};