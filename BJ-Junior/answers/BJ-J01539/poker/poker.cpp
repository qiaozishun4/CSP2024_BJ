#include<bits/stdc++.h>
using namespace std;
char p[55][3];
struct card{
    int D,C,H,S;
}c[100001];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio;
    cin.tie(0);

    int n;
    cin>>n;
    int Mmax=0;
    int m=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2;j++){
            cin>>p[i][j];
        }
        m=p[i][2];
        Mmax=max(Mmax,m);
        if(p[i][1]=='D'){
            c[m].D=1;
        }else if(p[i][1]=='C'){
            c[m].C=1;
        }else if(p[i][1]=='H'){
            c[m].H=1;
        }else if(p[i][1]=='S'){
            c[m].S=1;
        }
    }
    int ans=0;
    for(int i=1;i<=Mmax;i++){
        if(c[i].D==1){
            ans++;
        }
        if(c[i].C==1){
            ans++;
        }
        if(c[i].H==1){
            ans++;
        }
        if(c[i].S==1){
            ans++;
        }
    }
    ans=52-ans;
    cout<<ans;
    return 0;
}
