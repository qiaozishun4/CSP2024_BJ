#include<bits/stdc++.h>
using namespace std;
bool a[10][100];
long long n,ans;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        char x,y;
        long long u,v;
        cin>>x>>y;
        if(x=='D') u=1;
        if(x=='C') u=2;
        if(x=='H') u=3;
        if(x=='S') u=4;
        if(y=='A') v=1;
        else if(y=='T') v=10;
        else if(y=='J') v=11;
        else if(y=='Q') v=12;
        else if(y=='K') v=13;
        else v=y-'0';
        a[u][v]=true;
    }
    for(long long i=1;i<=4;i++) for(long long j=1;j<=13;j++) ans+=a[i][j];
    cout<<52-ans;
    return 0;
}
