class Solution {
  public:
    void relativeSort(vector<int> &arr1, vector<int> &arr2) {
        // code here
        map<int,int> mp2;
        
        for(int i=0;i<arr1.size();i++){
            mp2[arr1[i]]++;
        }
        int j=0;
        for(int i=0;i<arr2.size();i++){
            if(mp2.find(arr2[i])!=mp2.end()){
                // present in arr1
                while(mp2[arr2[i]]!=0){
                    arr1[j]=arr2[i];
                    mp2[arr2[i]]--;
                    j++;
                }
                if(mp2[arr2[i]]==0){
                    mp2.erase(arr2[i]);
                }
            }
            
        }
        
        for(auto it:mp2){
            while(j<arr1.size() && it.second!=0){
                arr1[j]=it.first;
                j++;
                it.second--;
            }
            
        }
        
    }
};