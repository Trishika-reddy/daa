w=list(map(int,input("enter w:").split()))
p=list(map(int,input("enter w:").split()))
c=int(input("c:"))
n=len(w)
k=[[0 for i in range(c+1)] for i in range(n+1)]
l=[]
for i in range(n+1):
    for j in range(c+1):
        if(i==0 or j==0):
            k[i][j]=0
        elif(w[i-1]<=j):
            k[i][j]=max(p[i-1]+k[i-1][j-w[i-1]],k[i-1][j])
        else:
            k[i][j]=k[i-1][j]
print(k[n][c])
j=c
for i in range(n,0,-1):
    if(k[i][j]!=k[i-1][j]):
        l.append(1)
        j=j-w[i]
    else:
        l.append(0)
print(l.reverse())
