class Solution {
public:
     #define ll long long
    #define MOD 1000000007
    int peopleAwareOfSecret(int n, int delay, int forget) {
        ll day = 2;
        vector<array<ll,3>> persons = {{delay + 1, forget + 1, 1}};
        while(day <= n){
            
            //Remove if the day cross the delay
            while(!persons.empty() && persons[0][1] == day){
                persons.erase(persons.begin());
            }
            //Persons till now
            ll count = 0;
            for(auto& x : persons){
                if(x[0] <= day){
                    count += x[2];
                }
                count %= MOD;
            }
            persons.push_back({day + delay, day + forget, count});
            day++;

        }
        ll res = 0;
        for(auto& x: persons){
            res += x[2];
            res %= MOD;
        }
        return res;
    }
};
