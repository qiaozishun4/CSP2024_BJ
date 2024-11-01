#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
bool book[5][20];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char a,b;
        cin>>a>>b;
        int k;
        if(b=='T') k=10;
        else if(b=='J') k=11;
        else if(b=='Q') k=12;
        else if(b=='K') k=13;
        else if(b=='A') k=1;
        else k=b-'0';
        if(a=='D') book[1][k]=1;
        else if(a=='C') book[2][k]=1;
        else if(a=='H') book[3][k]=1;
        else if(a=='S') book[4][k]=1;
    }
    int ans=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(!book[i][j]) ans++;
        }
    }
    cout<<ans;
    return 0;
}