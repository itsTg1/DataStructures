class Solution {
public:
    vector<pair<int,int>> idxs={{-1,0},{1,0},{0,1},{0,-1}};
    static bool checkConstraint(int i,int j,int rows,int cols){
            if(i<rows && j<cols && i>=0 && j>=0){
                return true;
            }
            return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int rows=heights.size();
        int cols=heights[0].size();
        
        vector<vector<int>> efforts(rows,vector<int>(cols,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        efforts[0][0]=0;
        while(!pq.empty()){
            auto frontNod=pq.top();
            pq.pop();
            pair<int,int> currPos=frontNod.second;
            int currEffort=frontNod.first;
            for(auto it:idxs){
                int newI=currPos.first+it.first;
                int newY=currPos.second+it.second;
if(checkConstraint(newI,newY,rows,cols) && max(currEffort,abs(heights[newI][newY] -
        heights[currPos.first][currPos.second]))<efforts[newI][newY])
{
                    efforts[newI][newY]=max(
    currEffort,
    abs(heights[newI][newY] -
        heights[currPos.first][currPos.second])
);

                    pq.push({efforts[newI][newY],{newI,newY}});
                }
            }
        }
        return efforts[rows-1][cols-1];
    }
};