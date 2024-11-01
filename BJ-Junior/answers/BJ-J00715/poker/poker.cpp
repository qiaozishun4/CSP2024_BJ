#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans;
char p[3];
bool d[15],c[15],s[15],h[15];
int po(char a)
{
    if(a=='A')
    {
        return 1;
    }
    else if(a=='T')
    {
        return 10;
    }
    else if(a=='J')
    {
        return 11;
    }
    else if(a=='Q')
    {
        return 12;
    }
    else if(a=='K')
    {
        return 13;
    }
    else
    {
        return int(a-48);
    }
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[1]>>p[2];
        if(p[1]=='D')
        {
            d[po(p[2])]=1;
        }
        if(p[1]=='C')
        {
            c[po(p[2])]=1;
        }
        if(p[1]=='S')
        {
            s[po(p[2])]=1;
        }
        if(p[1]=='H')
        {
            h[po(p[2])]=1;
        }
    }
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
        if(s[i]==0)
        {
            ans++;
        }
        if(h[i]==0)
        {
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}