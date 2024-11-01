#include <bits/stdc++.h>
using namespace std;
int t,n;
void p(int x,int y){
    for (int i=1;i<=x;i++) cout<<y;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while (t--){
        cin>>n;
        if (n<7){
            if (n==1) cout<<-1;
            if (n==2) cout<<1;
            if (n==3) cout<<7;
            if (n==4) cout<<4;
            if (n==5) cout<<2;
            if (n==6) cout<<6;
            continue;
        }
        int a=n/7,b=n%7;
        if (b==0){
            p(a,8);
        }
        if (b==1){
            cout<<10;
            p(a-1,8);
        }
        if (b==2){
            cout<<1;
            p(a,8);
        }
        if (b==3){
            cout<<22;
            p(a-1,8);
        }
        if (b==4){
            cout<<20;
            p(a-1,8);
        }
        if (b==5){
            cout<<2;
            p(a,8);
        }
        if (b==6){
            cout<<6;
            p(a,8);
        }
        cout<<endl;
    }
    return 0;
}