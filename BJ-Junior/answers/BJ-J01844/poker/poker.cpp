#include<bits/stdc++.h>
using namespace std;
int d[15],c[15],h[15],s[15];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w".stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char t;
        cin>>t;
        char t1;
        cin>>t1;
        int shuzi=0;
        if(t1=='T')
        {
            shuzi=10;
        }
        else if(t1=='J')
        {
            shuzi=11;
        }
        else if(t1=='Q')
        {
            shuzi=12;
        }
        else if(t1=='K')
        {
            shuzi=13;
        }
        else if(t1=='A')
        {
            shuzi=1;
        }
        else
        {
            shuzi=t1-'0';
        }
        if(t=='D')
        {
            d[shuzi]++;

        }
        if(t=='C')
        {
            c[shuzi]++;

        }
        if(t=='H')
        {
            h[shuzi]++;

        }
        if(t=='S')
        {
            s[shuzi]++;

        }
    }
    int ans=0;
    for(int i=1;i<=13;i++)
    {
        if(d[i]==0)
            ans++;
        if(h[i]==0)
            ans++;
        if(s[i]==0)
            ans++;
        if(c[i]==0)
            ans++;
    }
    cout<<ans;
    return 0;
}
