#include<bits/stdc++.h>
using namespace std;
bool d[15],c[15],h[15],s[15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char a,b;
        int t;
        cin>>a>>b;
        if(b=='A')
        {
            t=1;
        }
        else if(b=='T')
        {
            t=10;
        }
        else if(b=='J')
        {
            t=11;
        }
        else if(b=='Q')
        {
            t=12;
        }
        else if(b=='K')
        {
            t=13;
        }
        else
        {
            t=int(b-'0');
        }
        if(a=='D')
        {
            d[t]=1;
        }
        else if(a=='C')
        {
            c[t]=1;
        }
        else if(a=='H')
        {
            h[t]=1;
        }
        else
        {
            s[t]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=13;i++)
    {
        if(d[i]==0)
        {
            ans++;
        }
        if(c[i]==0)
        {
            ans++;
        }
        if(h[i]==0)
        {
            ans++;
        }
        if(s[i]==0)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
