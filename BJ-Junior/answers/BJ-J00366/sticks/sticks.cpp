#include<bits/stdc++.h>
using namespace std;
int t[30]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
int main(){
    //The Great Idea of Hao3Shu4
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        if(a<21) cout<<t[a];
        else{
            int s7=(a-7)/7;
            if(a%7==0) cout<<8;
            if(a%7==1) cout<<16;
            if(a%7==2) cout<<18;
            if(a%7==3) cout<<22;
            if(a%7==4) cout<<26;
            if(a%7==5) cout<<28;
            if(a%7==6) cout<<68;
            for(int x=1;x<=s7;x++) putchar('8');
        }
        putchar('\n');
    }
    return 0;
}
