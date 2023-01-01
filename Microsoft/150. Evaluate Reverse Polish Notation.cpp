class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long>st;
        for(auto s: tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                long a = st.top();
                st.pop();
                long b = st.top();
                st.pop();
                if(s == "+"){
                    a = a + b;
                    
                }
                if(s == "-"){
                    a = b - a;
                    
                }
                
                if(s == "*"){
                    a = (a * b);
                    
                }
                if(s == "/"){
                    a = (b / a);
                    
                }
                st.push(a);
            }
            
            else{
                st.push(stoi(s));
            }
        }
        
        return st.top();
    }
};




