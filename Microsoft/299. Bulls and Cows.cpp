class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int,int>mps, mpg;
        int n = secret.size();
        int x = 0, y = 0;
        for(int i = 0 ;i < n; i++){
            if(secret[i] == guess[i]){
                x++;
            }
            else{
                mps[secret[i]]++;
                mpg[guess[i]]++;
            }
        }

        for(auto it: mpg){
            if(mps.find(it.first)!=mps.end()){
                y+=min(mps[it.first],it.second);
            }
        }
        return to_string(x) + 'A' + to_string(y) + 'B';
    }
}; 