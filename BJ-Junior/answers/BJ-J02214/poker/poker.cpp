#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=20;
int n,ans=0;
char ch1,ch2;
int d[N],c[N],h[N],s[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ch1>>ch2;
        if(ch1=='D')
        {
            if(ch2=='A') d[1]=1;
            else if(ch2=='T') d[10]=1;
            else if(ch2=='J') d[11]=1;
            else if(ch2=='Q') d[12]=1;
            else if(ch2=='K') d[13]=1;
            else d[ch2-'0']=1;
        }
        else if(ch1=='C')
        {
            if(ch2=='A') c[1]=1;
            else if(ch2=='T') c[10]=1;
            else if(ch2=='J') c[11]=1;
            else if(ch2=='Q') c[12]=1;
            else if(ch2=='K') c[13]=1;
            else c[ch2-'0']=1;
        }
        else if(ch1=='H')
        {
            if(ch2=='A') h[1]=1;
            else if(ch2=='T') h[10]=1;
            else if(ch2=='J') h[11]=1;
            else if(ch2=='Q') h[12]=1;
            else if(ch2=='K') h[13]=1;
            else h[ch2-'0']=1;
        }
        else if(ch1=='S')
        {
            if(ch2=='A') s[1]=1;
            else if(ch2=='T') s[10]=1;
            else if(ch2=='J') s[11]=1;
            else if(ch2=='Q') s[12]=1;
            else if(ch2=='K') s[13]=1;
            else s[ch2-'0']=1;
        }
    }
    for(int i=1;i<=13;i++)
    {
        if(d[i]==0) ans++;
    }
    for(int i=1;i<=13;i++)
    {
        if(c[i]==0) ans++;
    }
    for(int i=1;i<=13;i++)
    {
        if(h[i]==0) ans++;
    }
    for(int i=1;i<=13;i++)
    {
        if(s[i]==0) ans++;
    }
    cout<<ans;
    return 0;
}
