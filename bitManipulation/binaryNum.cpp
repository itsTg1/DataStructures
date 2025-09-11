void generateBinary(int num,string &temp){
        if(num==0){
            temp.push_back('0');
            return ;
        }
        if(num==1){
            temp.push_back('1');
            return ;
        }
        char ans='0'+(num%2);
        generateBinary(num/2,temp);
        temp.push_back(ans);
    }