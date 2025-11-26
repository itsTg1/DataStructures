class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt=0;
        for(int i=num1;i<=num2;){
            string num=to_string(i);
            if(num.length()<3){
                i=101;
            }
            else if(num.length()>=3){
                for(int j=1;j<num.length()-1;j++){
                    int a=num[j]-'0';
                    int b=num[j-1]-'0';
                    int c=num[j+1]-'0';
                    if((a>b && a>c) || (a<b && a<c)){
                        cnt++;
                    }
                }
                i++;
            }
        }
        return cnt;
    }
};