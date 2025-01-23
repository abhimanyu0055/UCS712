def addPrime(n):
    sum=0
    for i in range(2,n+1):
     f=0
     for x in range(2,(i//2)+1):
        if i%x==0:
           f=1
           break
     if f==0:
      sum=sum+i
    return sum
print(addPrime(6))

     
     