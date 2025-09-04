// brute force
class Solution {

  public:
    bool findSwapValues(vector<int>& a, vector<int>& b) {
        // Your code goes here
        set<int> st1;
        set<int> st2;
        int sum1=0;
        int sum2=0;
        for(int i=0;i<a.size();i++){
            st1.insert(a[i]);
            sum1+=a[i];
        }
        for(auto it:b){
            st2.insert(it);
            sum2+=it;
        }
        int diff=abs(sum2-sum1);
        
        
        for(int i=0;i<b.size();i++){
          
                int newSum2=sum2-b[i];
                int newSum1=sum1+b[i];
                for(auto it:st1){
                    if(newSum1-it==newSum2+it){
                        return true;
                    }
                }
                
            
        }
        
        
        for(int i=0;i<a.size();i++){
           
                int newSum1=sum1-a[i];
                int newSum2=sum2+a[i];
                for(auto it:st2){
                    if(newSum1+it==newSum2-it){
                        return true;
                    }
                }
               
            
        }
        
        
        return false;
    }
};