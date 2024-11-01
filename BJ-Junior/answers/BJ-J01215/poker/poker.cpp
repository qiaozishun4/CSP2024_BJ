#include<bits/stdc++.h>
using namespace std;
int n,pok[100],ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int t=1;t<=n;t++){
        string s;
        cin>>s;
        char xc=s[0],yc=s[1];
        int i,j;
        if(xc=='S') i=1;
        if(xc=='H') i=2;
        if(xc=='D') i=3;
        if(xc=='C') i=4;
        if(yc=='A') j=1;
        if(yc=='K') j=13;
        if(yc=='Q') j=12;
        if(yc=='J') j=11;
        if(yc=='T') j=10;
        if(yc>='2'&&yc<='9') j=yc-'0';
        pok[i*13+j]=1;
    }
    for(int i=1;i<=52;i++) if(!pok[i]) ans++;
    cout<<ans;
    return 0;
}
