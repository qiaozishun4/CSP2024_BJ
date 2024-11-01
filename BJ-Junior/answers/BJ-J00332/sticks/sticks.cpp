#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int f[20]={6,2,5,5,4,5,6,3,7,6};
int shu[100000];
using namespace std;
int find(int p){
    int ans=11;
    for(int i=0;i<=9;i++){
        if(f[i]==p){
            ans=min(ans,i);
        }
    }
    if(p<=1){
        return -1;
    }else{
        return ans;
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int x;
        cin>>x;
        if(x==6){
            cout<<6<<endl;
            continue;
        }
        int len=x/7;
        if(len*7!=x){
            len++;//答案序列长度
        }
        int a=len*7-x;
        a=7-a;
        if(len==1){
            cout<<find(a)<<endl;
            continue;
        }
        if(a==1){
            cout<<10;
        }else if(a==2){
            cout<<18;
        }else if(a==3){
            cout<<22;
        }else if(a==4){
            cout<<20;
        }else if(a==5){
            cout<<28;
        }else if(a==6){
            cout<<68;
        }else if(a==7){
            cout<<88;
        }
        for(int i=1;i<=len-2;i++){
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
