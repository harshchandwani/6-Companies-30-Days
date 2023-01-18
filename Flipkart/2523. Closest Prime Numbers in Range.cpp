class Solution {
public:
    bool isPrime(int n)
    {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return n!=1;
    }
 
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans(2,-1);
        vector<int>v;
        for(int i = left; i <= right; i++){
            if(isPrime(i)){
                v.push_back(i);
            }
        }

        if(v.size() < 2) return ans;

        int min = INT_MAX;
        for(int i = 0; i<v.size()-1; i++){
            if(min > v[i+1] - v[i]){
                min = v[i+1] - v[i];
                ans[0] = v[i];
                ans[1] = v[i+1];
            }            
        }

        return ans;
    }
};
