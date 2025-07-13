class Solution {
public:
    int jump(vector<int>& arr) {
        if(arr.size()==1){
            return 0;
        }
        int cnt=0;
        for(int i=0;i<arr.size();){
          
            if(arr[i]+i >= (arr.size()-1)){
                cnt++;
                return cnt;
            }
            int maxjump=0;
            int idx=i;
            for(int j=0;j<=arr[i];j++){
                if((i+j)<arr.size()){
                    if(j + arr[i+j]>=maxjump){
                        maxjump=j+arr[i+j];
                        idx=i+j;
                    }

                }
            }
            i=idx;
            cnt++;
            if(i>=(arr.size()-1)){
                return cnt;
            }
        }
        return cnt;
    }
};