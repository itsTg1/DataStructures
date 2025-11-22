class Solution {
public:
    long long countDistinct(long long n) {
        
        long long sum=0;
        string num=to_string(n);
        long long len=num.length();
        if(len==1){
            return n;
        }
        for(int i=1;i<len;i++){
            sum+=(pow(9,i-1)*9);
        }
       
        long long cnt=1;
        bool isbreak=false;
        for(long long i=0;i<len-1;i++){
            long long ele=num[i]-'0';
            if(ele==0){
                isbreak=true;
                break;
            }
            sum+=(pow(9,len-cnt)*(ele-1));
            cnt++;
        }
        if(num[len-1]-'0'!=0 && !isbreak){
            sum+=(num[len-1]-'0');
        }
        return sum;
    }
};