class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0 , j = 0  , ans = 0;

        int count_a = 0 , count_b = 0 , count_c = 0;

        while(j < n){

            if(s[j] == 'a') count_a++;
            if(s[j] == 'b') count_b++;
            if(s[j] == 'c') count_c++;

            //if the window is not valid
            if(!(count_a > 0 and count_b > 0 and count_c > 0))  j++;

            else{       
                //when the Window is valid
                while(i < n and count_a > 0 and count_b > 0 and count_c > 0){
                    if(s[i] == 'a') count_a--;
                    if(s[i] == 'b') count_b--;
                    if(s[i] == 'c') count_c--;
                    i++;
                    ans+= n-j;      
                }
                
                j++;
            }
        }

        return ans;
    }
};