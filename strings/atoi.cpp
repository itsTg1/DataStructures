class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(i < s.length() && s[i] == ' '){
            i++;
        }
        s = s.substr(i);  

        bool isneg = false;
        if(s.length() > 0 && s[0] == '-'){
            isneg = true;
            s = s.substr(1);  
        }
        else if(s.length() > 0 && s[0] == '+'){
            s = s.substr(1);  
        }

        int j = 0;
        string temp = "";
        while(j < s.length() && s[j] >= '0' && s[j] <= '9'){
            temp.push_back(s[j]);
            j++;
        }
        if(temp.length() == 0){
            return 0;
        }

        long long ans = 0;
        for(int k = 0; k < temp.length(); k++){
            int val = temp[k] - '0';

            // Corrected overflow checks before multiplying
            // condn:- ans*10 + val <= int_max if this is true then overflow will not happen
            // but ( ans*10 + val > int_max )=> (int_max-val)/10 < ans 
            if(ans > (INT_MAX - val) / 10){
                return isneg ? INT_MIN : INT_MAX;
            }

            ans = ans * 10 + val;
        }

        if(isneg){
            ans = -ans;
        }

        // Final boundary checks
        if(ans > INT_MAX){
            return INT_MAX;
        }
        if(ans < INT_MIN){
            return INT_MIN;
        }

        return ans;
    }
};
