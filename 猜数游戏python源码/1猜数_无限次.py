import random     #使用随机模块
r = random.randint(1,10)  #生成一个随机数
a=0               #玩家猜的数初始化为0，以便进入猜数的循环
while a!=r:       
    a = int(input('请输入你想猜的数（1~10）')) #玩家输入说猜的数
    if a>r:                #比较用户猜的数与计算机随机数的大小关系
        print('大了')
    elif a<r:
        print('小了')
    else :
        print('恭喜你猜对了')
