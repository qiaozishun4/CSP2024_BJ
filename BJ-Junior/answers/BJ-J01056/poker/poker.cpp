#include <bits/stdc++.h>
using namespace std;
int n, v[5][20], ans;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    std::cin>>n;
    for(int i=1;i<=n;i++)
    {
        char a, b;
        int c, d;
        std::cin>>a>>b;
        if(b>'0' && b<='9') d=b-'0';
        if(b=='A') d=1;
        if(b=='T') d=10;
        if(b=='J') d=11;
        if(b=='Q') d=12;
        if(b=='K') d=13;
        if(a=='D') c=1;
        if(a=='H') c=2;
        if(a=='C') c=3;
        if(a=='S') c=4;
        v[c][d]=1;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(v[i][j]) ans++;
        }
    }
    std::cout<<52-ans;
    return 0;
}
