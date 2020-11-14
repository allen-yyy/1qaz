import random
x=1        #设置范围
y=10
r = random.randint(x, y)
i=0
while i<3:
    i=i+1
    a = int(input('第'+str(i)+'次猜数('+str(x)+'—'+str(y)+')：'))
    if a>r:
        print('大了')
        y=a
    elif a<r:
        print('小了')
        x=a
    else :
        print('恭喜你猜对了')
        break
if a!=r:
    print('很遗憾，你输了')
