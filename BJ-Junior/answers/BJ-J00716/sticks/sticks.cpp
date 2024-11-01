#include<bits/stdc++.h>
using namespace std;
int T,a[21]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688};
int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        if(n<=100000 && n>=100 && n%7==0)
            for(int i=1;i<=n/7;i++) cout<<8;
        else if(n<=20){
            cout<<a[n];
        }
        else {
            int k=n/7,m=n%7;
            if(m!=0) k++;
            if(m==1) {
                cout<<10;
                k-=2;
                while(k--) cout<<8;
            }
            if(m==2) {
                cout<<1;
                k-=1;
                while(k--) cout<<8;
            }
            if(m==3) {
                cout<<200;
                k-=3;
                while(k--) cout<<8;
            }
            if(m==4) {
                cout<<20;
                k-=2;
                while(k--) cout<<8;
            }
            if(m==5) {
                cout<<2;
                k-=1;
                while(k--) cout<<8;
            }
            if(m==6) {
                cout<<6;
                k-=1;
                while(k--) cout<<8;
            }
            if(m==0)
                while(k--) cout<<8;
        }
        cout<<"\n";
    }
    return 0;
}
