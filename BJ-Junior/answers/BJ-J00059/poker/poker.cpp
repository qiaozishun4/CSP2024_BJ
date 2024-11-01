#include<bits/stdc++.h>
using namespace std;
int pai[5][14];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        int k;
        if(isdigit(b)) k=b-'0';
        else if(b=='A') k=1;
        else if(b=='T') k=10;
        else if(b=='J') k=11;
        else if(b=='Q') k=12;
        else if(b=='K') k=13;

        if(a=='D') pai[1][k]++;
        else if(a=='C') pai[2][k]++;
        else if(a=='H') pai[3][k]++;
        else if(a=='S') pai[4][k]++;
    }
    int cnt=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(pai[i][j]==0) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
