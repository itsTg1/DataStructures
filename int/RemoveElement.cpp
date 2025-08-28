class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        
        j=len(nums)-1
        i=0
        cnt=0
        while (i<=j):
            if(nums[j]==val):
                j-=1
                cnt+=1
            elif(nums[i]==val):
                temp=nums[j]
                nums[j]=nums[i]
                nums[i]=temp
                j-=1
                i+=1
                cnt+=1
            else:
                i+=1
        ans=len(nums)-cnt
        
        if(len(nums)>0 and nums[0]==val):
            
            nums.clear()

        return ans
        
        