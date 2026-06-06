
// leetcode - 57

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;
       
        vector<int> start;
        int j=0;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<newInterval[0]){
                ans.push_back(intervals[i]);
            }
            else{
                
          
                break;
            }
        }
        if(ans.size()>0){
            start=ans.back();
            ans.pop_back();
        }
        vector<int> next;
        
        while(j<intervals.size() && intervals[j][0]<=newInterval[1]){
            next=intervals[j];
            j++;
        }
        
        vector<int> IntervalNew(2);
        
        if(start.size()==0 || start[1]<newInterval[0]){
            IntervalNew[0]=newInterval[0];
            if(start.size()>0){
                ans.push_back(start);
            }
            
        }
        else{
            IntervalNew[0]=min(start[0],newInterval[0]);
        }
        if(next.size()==0 || next[0]>newInterval[1]){
            IntervalNew[1]=newInterval[1];
            ans.push_back(IntervalNew); 
            if(next.size()>0){
                ans.push_back(next);
            }      
            
        }
        else{
            IntervalNew[1]=max(next[1],newInterval[1]);
            ans.push_back(IntervalNew);
        }
        
        
        while(j<intervals.size()){
            ans.push_back(intervals[j]);
            j++;
        }
        return ans;


    }
};