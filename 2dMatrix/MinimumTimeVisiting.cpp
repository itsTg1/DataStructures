// leetcode 1266
class Solution {
public:
    
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int cnt=0;
        for(int i=0;i<points.size()-1;i++){
           int x1=points[i][0];
           int y1=points[i][1];
           int x2=points[i+1][0];
           int y2=points[i+1][1];
           int diff1=abs(x2-x1);
           int diff2=abs(y2-y1);
           int mindiff=min(diff1,diff2);
           diff1=diff1-mindiff;
           diff2=diff2-mindiff;
           cnt+=mindiff+diff1+diff2;
        }
        return cnt;
    }
};