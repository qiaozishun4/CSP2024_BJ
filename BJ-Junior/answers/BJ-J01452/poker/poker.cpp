#include<bits/stdc++.h>
using namespace std;
int a[100][100]={};
string z;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>z;
        int x=0,y=0;
        if(z[0]=='D') x=1;
        else if(z[0]=='C') x=2;
        else if(z[0]=='H') x=3;
        else if(z[0]=='S') x=4;
        if(z[1]=='A') y=1;
        else if(z[1]=='T') y=10;
        else if(z[1]=='J') y=11;
        else if(z[1]=='Q') y=12;
        else if(z[1]=='K') y=13;
        else y=z[1]-'0';
        a[x][y]=1;
    }
    long long cnt=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}