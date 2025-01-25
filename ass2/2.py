t=(45, 89.5, 76, 45.4, 89, 92, 58, 45)
print(max(t))
print(t.index(max(t)))
print(min(t))
print(t.count(min(t)))
t= t[::-1]
t= list(t)
print(t)
if 76 in t:
    print(t.index(76))
else:
    print("not found")