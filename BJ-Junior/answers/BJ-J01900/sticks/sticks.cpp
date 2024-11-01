#include<bits/stdc++.h>
using namespace std;
long long t,n,a[101]={0,-1,1,7,4,2,6,8,10,18,22,26,28,68,88,108,188,208,288,688,888};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1)cout<<-1<<endl;
        else if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==1){
            cout<<10;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n<=20&&n>1){
            if(n==2)cout<<1;
            if(n==3)cout<<7;
            if(n==4)cout<<4;
            if(n==5)cout<<2;
            if(n==6)cout<<6;
            if(n==9)cout<<18;
            if(n==10)cout<<22;
            if(n==11)cout<<26;
            if(n==12)cout<<28;
            if(n==13)cout<<68;
            if(n==16)cout<<188;
            if(n==17)cout<<200;
            if(n==18)cout<<208;
            if(n==19)cout<<288;
            if(n==20)cout<<688;
            cout<<endl;
        }else{
            int p;
            for(p=1;n>=21;p++){
                n-=7;
            }
            cout<<a[n];
            for(int i=1;i<p;i++){
                cout<<8;
            }
            cout<<endl;
        }
    }
    return 0;
}
