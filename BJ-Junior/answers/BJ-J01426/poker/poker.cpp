#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll num(string s)
{
    char c1=s[0],c2=s[1];
    ll ans;
    if(c1=='D')
    {
        if(c2=='T') ans=10;
        else if(c2=='A') ans=1;
        else if(c2=='J') ans=11;
        else if(c2=='Q') ans=12;
        else if(c2=='K') ans=13;
        else ans=c2-'0';
    }else if(c1=='C')
    {
        if(c2=='T') ans=10;
        else if(c2=='A') ans=1;
        else if(c2=='J') ans=11;
        else if(c2=='Q') ans=12;
        else if(c2=='K') ans=13;
        else ans=c2-'0';
        ans+=13;
    }else if(c1=='H')
    {
        if(c2=='T') ans=10;
        else if(c2=='A') ans=1;
        else if(c2=='J') ans=11;
        else if(c2=='Q') ans=12;
        else if(c2=='K') ans=13;
        else ans=c2-'0';
        ans+=26;
    }else if(c1=='S')
    {
        if(c2=='T') ans=10;
        else if(c2=='A') ans=1;
        else if(c2=='J') ans=11;
        else if(c2=='Q') ans=12;
        else if(c2=='K') ans=13;
        else ans=c2-'0';
        ans+=39;
    }
    return ans;
}
ll a[60];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        a[num(s)]++;
    }
    ll ans=0;
    for(int i=1;i<=52;i++)
    {
        if(a[i]==0)
            ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
