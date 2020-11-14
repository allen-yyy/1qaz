import random
x=1        #设置范围
y=100
c=7        #设置次数
print('猜数范围',x,'—',y,'，共',c,'次机会')
r = random.randint(x, y)
i=0
while i<c:
    i=i+1
    a = int(input('第'+str(i)+'次猜数('+str(x)+'—'+str(y)+')：'))
    if a>r:
        print('大了')
        if a<=y:
            y=a-1
    elif a<r:
        print('小了')
        if a>=x:
            x=a+1
    else :
        print('恭喜你猜对了')
        break
if a!=r:
    print('很遗憾，你输了')

