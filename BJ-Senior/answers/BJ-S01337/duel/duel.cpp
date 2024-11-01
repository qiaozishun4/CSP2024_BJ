#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,r[100005],t[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        t[r[i]]++;
    }
    if(t[1]+t[2]==n) cout<<max(t[1],t[2])<<endl;
    else cout<<1<<endl;
    return 0;
}
/*
# CSP-Judger(Linux) v0.2.0
import os,json,time
js=json.load(open("judge-config.json","r"))
name=input()
if os.system("g++ -o "+name+" "+name+".cpp -O2 -std=c++14 -static")==0:
    for i in range(1,js[name][0]+1):
        os.system("cp "+name+str(i)+".in "+name+".in")
        start=time.time()
        if os.system("./"+name)==0:
            end=time.time()
            if end-start>js[name][1]:
                print(i,"TLE")
            elif os.system("diff "+name+".out "+name+str(i)+".ans")==0:
                print(i,"AC\n")
            else:
                print(i,"WA\n")
        else:
            print(i,"RE\n")
        time.sleep(1)
else:
    print("CE")
*/