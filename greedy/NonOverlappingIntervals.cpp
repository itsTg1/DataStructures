// 435

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt=0;
        sort(intervals.begin(),intervals.end());
        for(auto it:intervals){
            cout<<it[0]<<"-"<<it[1]<<endl;
        }
        int end=intervals[0][1];
        int start=intervals[0][0];
        for(int i=1;i<intervals.size();i++){
            if(end>intervals[i][0]){
                cnt++;
                end=min(end,intervals[i][1]);
            }
            else{
                end=max(end,intervals[i][1]);
            }
        }
        return cnt;
    }
};