#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--) {
        cin>>n;
        if(n%7==0) {
            m=n/7;
            for(int i=1;i<=m;i++) {
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n==1) {
            cout<<-1;
            cout<<endl;
            continue;
        }
        if(n<7) {
            if(n==2) {
                cout<<1<<endl;
            }
            if(n==3) {
                cout<<7<<endl;
            }
            if(n==4) {
                cout<<4<<endl;
            }
            if(n==5) {
                cout<<2<<endl;
            }
            if(n==6) {
                cout<<6<<endl;
            }
            continue;
        }
        m=n/7;
        if(n%7==1) {
            m-=1;
            cout<<10;
        }
        if(n%7==2) {
            cout<<1;
        }
        if(n%7==3) {
            m-=1;
            cout<<23;
        }
        if(n%7==4) {
            m-=1;
            cout<<20;
        }
        if(n%7==5) {
            cout<<2;
        }
        if(n%7==6) {
            m-=1;
            cout<<80;
        }
        for(int i=1;i<=m;i++) {
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}

