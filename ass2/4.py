a=set([34,56,78,90])
b=set([78,45,90,23])
print(a.union(b))
print(a.intersection(b))
print(a.symmetric_difference(b))
# x= int(input("enter the no. to be searched"))
# if x in a:
#     print(" th no. is present ")
# else:
#     print("not present")
print(a.issubset(b))
print(b.issuperset(a))