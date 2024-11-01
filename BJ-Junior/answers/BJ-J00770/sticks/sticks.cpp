#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

void sol() {
    int n; cin>>n;

    if(n==1) {
        cout<<-1;puts("");
        return ;
    }
    if(n==2) {
        cout<<1;puts("");
        return ;
    }
    if(n==3) {
        cout<<7;puts("");
        return ;
    }
    if(n==4) {
        cout<<4;puts("");
        return ;
    }
    if(n==5) {
        cout<<2;puts("");
        return ;
    }
    if(n==6) {
        cout<<6;puts("");
        return ;
    }
    if(n==7) {
        cout<<8;puts("");
        return ;
    }

    int y=n%7,k=n/7;
    if(y==0) {
        forr(i,1,k) printf("8");puts("");
        return ;
    }
    if(y==1) {
        cout<<"10";
        forr(i,1,k-1) printf("8");puts("");
        return ;
    }
    if(y==2) {
        cout<<"18";
        forr(i,1,k-1) printf("8");puts("");
        return ;
    }
    if(y==3) {
        cout<<"40";
        forr(i,1,k-1) printf("8");puts("");
        return ;
    }
    if(y==4) {
        cout<<"20";
        forr(i,1,k-1) printf("8");puts("");
        return ;
    }
    if(y==5) {
        cout<<"28";
        forr(i,1,k-1) printf("8");puts("");
        return ;
    }
    if(y==6) {
        cout<<"80";
        forr(i,1,k-1) printf("8");puts("");
        return ;
    }




    return ;
}



int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int T; cin>>T; while(T--) sol();



    return 0;
}
