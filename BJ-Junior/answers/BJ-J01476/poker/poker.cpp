#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int p[20][20];
char a,b;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a>>b;
        int x,y;
        if(a=='D') x=1;
        else if(a=='C') x=2;
        else if(a=='H') x=3;
        else if(a=='S') x=4;
        if('2'<=b&&b<='9') y=b-'0';
        else if(b=='A') y=1;
        else if(b=='T') y=10;
        else if(b=='J') y=11;
        else if(b=='Q') y=12;
        else if(b=='K') y=13;
        p[x][y]=6;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(p[i][j]==6) cnt++;
        }
    }
    int ans=52-cnt;
    cout<<ans<<endl;
    return 0;
}
