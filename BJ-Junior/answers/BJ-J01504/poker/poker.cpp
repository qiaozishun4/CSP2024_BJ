#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, c[10][20], ans;
char a, b;

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        int x, y;
        if(a=='D') x=1;
        if(a=='C') x=2;
        if(a=='H') x=3;
        if(a=='S') x=4;

        if(b=='A') y=1;
        if(b=='T') y=10;
        if(b=='J') y=11;
        if(b=='Q') y=12;
        if(b=='K') y=13;
        if(isdigit(b)) y=b-'0';

        c[x][y]=1;
    }
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(!c[i][j])
                ans++;
    cout<<ans<<endl;
    return 0;
}
