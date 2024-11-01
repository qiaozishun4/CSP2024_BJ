#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
int few[10]={0,-1,1,7,4,2,6};
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while (t--){
        cin>>n;
        if (n<7){
            cout<<few[n]<<"\n";
            continue;
        }
        int p=n%7;
        if (p==1){
            cout<<10;
            n-=8;
        }
        else if (p==2){
            cout<<18;
            n-=9;
        }
        else if (p==3){
            cout<<22;
            n-=10;
        }
        else if (p==4){
            cout<<20;
            n-=11;
        }
        else if (p==5){
            cout<<28;
            n-=12;
        }
        else if (p==6){
            cout<<68;
            n-=13;
        }
        while (n>0){
            cout<<8;
            n-=7;
        }
        cout<<"\n";
    }
    return 0;
}
