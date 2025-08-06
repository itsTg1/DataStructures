// bubble by pass -1

for(int i=0;i<nums.size()-1;i++){
    bool isSwap=false;
    for(int j=0;j<nums.size()-i-1;j++){
        if(nums[j]>nums[j+1]){
            swap(nums[j],nums[j+1]);
            isSwap=true;
        }
    }
    if(!isSwap){
        break;
    }
}