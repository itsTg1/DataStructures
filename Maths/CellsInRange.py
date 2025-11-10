# 2194


class Solution:
    def getCol(self,colNum)->int:
        ans=""
        while colNum>0:
            colNum-=1
            rem=colNum%26
            let=rem+ord('A')
            ch=chr(let)
            ans+=ch
            colNum=colNum//26
        ans=ans[::-1]
        return ans
    def findCol(self,col:str)->int:
        x=1
        ans=0
        
        for i in col:
            n=ord(i)
            firs=ord('A')
            ans+=(n-firs+1)*x
            x=x*26
        return ans

    def cellsInRange(self, s: str) -> List[str]:
        lis=[]
        cols=s.split(":")
        col1=""
        row1=0
        col2=""
        row2=0
        ele1=list(cols[0])
        ele2=list(cols[1])
        print(ele2)
        for i in ele1 :
            if(i>='A' and i<='Z'):
                col1+=i
            else:
                row1+=(row1*10)+int(i)
        for i in ele2:
            if(i>='A' and i<='Z'):
                col2+=i
            else:
                row2+=(row2*10)+int(i)
        
        colNum1=self.findCol(col1)
        colNum2=self.findCol(col2)
        for i in range(colNum1,colNum2+1):
            for j in range(row1,row2+1):
                colName=self.getCol(i)
                colName+=str(j)
                lis.append(colName)
        return lis
        