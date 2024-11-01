#include <bits/stdc++.h>
using namespace std;
int a[7][16];
int fun1(char ch)
{
    if(ch=='D') return 0;
    if(ch=='C') return 1;
    if(ch=='H') return 2;
    if(ch=='S') return 3;
}
int fun2(char ch)
{
    if(ch=='A') return 1;
    if(ch=='2') return 2;
    if(ch=='3') return 3;
    if(ch=='4') return 4;
    if(ch=='5') return 5;
    if(ch=='6') return 6;
    if(ch=='7') return 7;
    if(ch=='8') return 8;
    if(ch=='9') return 9;
    if(ch=='T') return 10;
    if(ch=='J') return 11;
    if(ch=='Q') return 12;
    if(ch=='K') return 13;
}
int main()
{
    // freopen("poker3.in","r",stdin);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        a[fun1(s[0])][fun2(s[1])]=1;
    }
    int ans=0;
    for(int i=0;i<=3;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(a[i][j]==0) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}