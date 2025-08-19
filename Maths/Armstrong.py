#User function Template for python3

class Solution:
    def armstrongNumber (self, n):
        # code here 
        number=str(n)
        num=list(number)
      
        sum=0
        for i in num:
            sum+=((int)(i))**3
        
        return sum==n
            