class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        min_no=minutes/5
        hr_no=hour%12
        
        
        if(min_no==hr_no):
      
            return (minutes/2)
        else:
            option1=abs(((hour%12)*30)-(minutes*6)+(0.5*minutes))
            answer = min(option1, 360 - option1)
            return answer
        return 0
