
import os,time,random

money=0
meimiaozengjia=0

while True:
    os.system("clear")
    with open("a.txt","r") as f:
        money=int(f.readline())
        meimiaozengjia=int(f.readline())
    print("")
    print(""+str(money))
    print(""+str(meimiaozengjia))
    money+=meimiaozengjia
    with open("a.txt","w") as f:
        f.write(str(money)+"\n")
        f.write(str(meimiaozengjia)+"\n")
        
    time.sleep(1)




import os
a="""
花费0获得1
花费100获得1/s
花费1000获得10/s
花费10000获得100/s
花费100000获得10000/s
"""
money=0
meimiaozengjia=0
while True:
    os.system("clear")
    print(a)
    p=input("请输入你的选择：")
    if(p=="1"):
        with open("a.txt","r") as f:
            money=int(f.readline())
            meimiaozengjia=int(f.readline())
        money+=1
        with open("a.txt","w") as f:
            f.write(str(money)+"\n")
            f.write(str(meimiaozengjia)+"\n")
    if(p=="2"):
        with open("a.txt","r") as f:
            money=int(f.readline())
            meimiaozengjia=int(f.readline())
        if(money>=100):
            money-=100
            meimiaozengjia+=1
        with open("a.txt","w") as f:
            f.write(str(money)+"\n")
            f.write(str(meimiaozengjia)+"\n")
    if(p=="3"):
        with open("a.txt","r") as f:
            money=int(f.readline())
            meimiaozengjia=int(f.readline())
        if(money>=1000):
            money-=1000
            meimiaozengjia+=10
        with open("a.txt","w") as f:
            f.write(str(money)+"\n")
            f.write(str(meimiaozengjia)+"\n")
    if(p=="114514"):
        with open("a.txt","r") as f:
            money=int(f.readline())
            meimiaozengjia=int(f.readline())

        money-=10000
        meimiaozengjia+=1000
        with open("a.txt","w") as f:
            f.write(str(money)+"\n")
            f.write(str(meimiaozengjia)+"\n")
    
    

    
        
