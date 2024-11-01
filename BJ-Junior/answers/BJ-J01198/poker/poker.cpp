#include<bits/stdc++.h>
using namespace std;
int t[60];
int ch(char a,char b)
{
    int x,y;
    if(a=='D')x=1;
    if(a=='C')x=2;
    if(a=='H')x=3;
    if(a=='S')x=4;
    if(b=='A')y=1;
    else if(b=='T')y=10;
    else if(b=='J')y=11;
    else if(b=='Q')y=12;
    else if(b=='K')y=13;
    else y=b-'0';
    return (x-1)*13+y;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    char a,b;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        t[ch(a,b)]=1;
    }
    int ans=0;
    for(int i=1;i<=52;i++)
    {
        if(t[i]==0)ans++;
    }
    cout<<ans;
    return 0;
}