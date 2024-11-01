#include <bits/stdc++.h>
using namespace std;
int h[5][15],ans=52;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        char a,b;
        int c,d;
        cin>>a>>b;
        if(a=='D') c=1;
        if(a=='C') c=2;
        if(a=='H') c=3;
        if(a=='S') c=4;
        if(b=='J') d=11;
        else if(b=='Q') d=12;
        else if(b=='K') d=13;
        else if(b=='T') d=10;
        else if(b=='A') d=1;
        else d=int(b-48);
        //cout<<c<<" "<<d<<endl;
        h[c][d]++;
    }
    for(int i=1;i<=4;i++)
    for(int j=1;j<=13;j++)
    if(h[i][j]) ans--;
    cout<<ans;
    return 0;
}
