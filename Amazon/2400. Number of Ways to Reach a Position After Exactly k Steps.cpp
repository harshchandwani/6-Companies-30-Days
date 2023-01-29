class Solution {
    
    const unsigned int M = 1000000007;
    map<pair<int,int>,int>mp;
public:
    
    int solve(int startPos, int endPos,int moves, int k)
    {
        if(moves==k)
        {
            if(startPos == endPos)
                return 1;
            
            return 0;
        }
        
		// we cannot reach the endPos since we dont have the no of moves needed
        if(abs(endPos-startPos)>k-moves)
            return 0;
        
        if(mp.find({startPos,moves})!=mp.end())
            return mp[{startPos,moves}];
        
        // move left
        int left = solve(startPos-1,endPos,moves+1,k);
        // move right
        int right = solve(startPos+1,endPos,moves+1,k);

        return mp[{startPos,moves}] = (left + right)%M;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
     
        return solve(startPos,endPos,0,k);
    }
};
