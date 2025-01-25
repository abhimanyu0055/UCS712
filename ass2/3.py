import random as r
l= r.sample(range(100,900),100)
print(l)
counteven=0
for num in l:
    if num%2==0:
        counteven+=1
        print(num)

print(counteven)
countprime=0
for num in l:
    flag=0
    for i in range(2,num):
        if num%i==0:
            flag=1
            break
    if flag==0:
        countprime+=1
        print(num)

