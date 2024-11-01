#include<bits/stdc++.h>
using namespace std;
int t,n,ans[21]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,228,208,288,688};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=20){
            cout<<ans[n]<<endl;
            continue;
        }
        if(n%7==1){
            n-=8;
            cout<<10;
        }else if(n%7==2){
            n-=2;
            cout<<1;
        }else if(n%7==3){
            n-=10;
            cout<<22;
        }else if(n%7==4){
            cout<<20;
            n-=11;
        }else if(n%7==5){
            cout<<2;
            n-=5;
        }else if(n%7==6){
            cout<<6;
            n-=6;
        }
        while(n){
            printf("8");
            n-=7;
        }
        cout<<endl;
    }
    return 0;
}
