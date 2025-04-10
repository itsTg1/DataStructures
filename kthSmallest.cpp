int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
     pq.push(nums[i]);
    }
    for(int i=k;i<nums.size();i++){
     if(nums[i]>pq.top()){
         pq.pop();
         pq.push(nums[i]);
     }
    }
    return pq.top();
 }



//  kth largest element in a stream 

class KthLargest {
    public:
        int k;
        priority_queue<int,vector<int>,greater<int>> pq;
        KthLargest(int k, vector<int>& nums) {
            this->k=k;
            for(int i=0;i<nums.size();i++){
                pq.push(nums[i]);
                if(pq.size()>k){
                    pq.pop();
                }
            }
            
        }
        
        int add(int val) {
            pq.push(val);
            if(pq.size()>k){
                pq.pop();
            }
            
            return pq.top();
        }
    };
    