#include<bits/stdc++.h>
using namespace std;
bool vis[4][14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        int x,y;
        if(a=='D') x=0;
        if(a=='C') x=1;
        if(a=='H') x=2;
        if(a=='S') x=3;
        if(b=='A') y=1;
        else if(b=='T') y=10;
        else if(b=='J') y=11;
        else if(b=='Q') y=12;
        else if(b=='K') y=13;
        else y=b-'0';
        vis[x][y]=1;
    }
    for(int i=0;i<4;i++){
        for(int j=1;j<=13;j++){
            if(!vis[i][j]) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
