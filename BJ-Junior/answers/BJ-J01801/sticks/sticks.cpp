#include <bits/stdc++.h>
using namespace std;
int n;
int weishu(int x){
    int sum=0;
    while(x/=10)sum++;
    return sum+1;
}
int findmin(int num,bool way){
    if(num==2)return 1;
    if(num==3)return 7;
    if(num==4)return 4;
    if(num==5)return 2;
    if(num==7)return 8;
    if(num==6)return (way==true?0:6);
    int numnow=100000000;
    for(int p=2;p<=num/2;++p){
        int q=num-p;
        int pt=findmin(p,true),pf=findmin(p,false),qt=findmin(q,true),qf=findmin(q,false);
        int wp=weishu(pt);
        int wq=weishu(qt);
        for(int i=1;i<=wq;++i)pf*=10;
        for(int i=1;i<=wp;++i)qf*=10;
        if(min(pf+qt,qf+pt)<numnow)numnow=min(pf+qt,qf+pt);
    }
    return numnow;
}
int main(){

    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int T;
    cin>>T;
    while(T--){
        cin>>n;
        if(n<=1){
            cout<<-1<<endl;
            continue;
        }
        cout<<findmin(n,false)<<endl;
    }
    return 0;
}
