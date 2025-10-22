class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        int pos=0;
        for(int i=0;i<arr.size();i++){
            if(pq.size()>k){
                int ele=pq.top();
                arr[pos]=ele;
                pos++;
                pq.pop();
            }
            pq.push(arr[i]);
        }
        while(!pq.empty()){
            int ele=pq.top();
            pq.pop();
            arr[pos]=ele;
            pos++;
        }
        
    }
};