class Solution {
  public:
    int removeDuplicates(vector<int> &arr) {
        // code here
        vector<int> temp;
        int size=1;
        int ele=arr[0];
        temp.push_back(ele);
        for(int i=1;i<arr.size();i++){
            if(arr[i]!=ele){
                size++;
                ele=arr[i];
                temp.push_back(ele);
            }
        }
        arr=temp;
        return size;
    }
};