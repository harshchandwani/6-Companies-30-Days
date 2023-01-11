class Solution {
public:
   vector<string> separate(string &s){
        vector<string> v;
        string t;
        for(auto it : s){
            if(it == ','){
                v.push_back(t);
                t.clear();
            }else{
                t.push_back(it);
            }
        }
        v.push_back(t);
        return v;
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        unordered_map<string, vector<string>>map;
        //Bascially we are stroring the elements in the map
        //key = 'alice,20,800,mtv'
        //value = vector<alice, 20, 800, mtv>


        for(int i = 0; i < n; i++){
            map[transactions[i]] = separate(transactions[i]);
        }
        //Calling separeate function to store in map

        vector<string>invalid;
        for(int i = 0; i < n; i++){
             vector<string> s = map[transactions[i]];
             if(stoi(s[2]) > 1000){
                 invalid.push_back(transactions[i]);
                 continue;
             }
             //Check if the value in larger than 1000
             //store it in invalid vector
             //continue


            for(int j = 0; j < n; j++){
                //compare the current string with every other transaction
                if(i != j){
                    vector<string> t = map[transactions[j]];
                    if( abs(stoi(t[1]) - stoi(s[1])) <= 60){
                        //check if 2 transactions are within 60 min
                        
                        if(s[0] == t[0] && s[3] != t[3]){
                            invalid.push_back(transactions[i]);
                            break;
                        }
                        //Check the if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
                    }
                }
            }
        }
        return invalid;
    }
};