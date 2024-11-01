#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check[100];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ll n;cin>>n;
    for(ll i=1;i<=100;i++) check[i]=false;
    for(ll i=1;i<=n;i++)
    {
        string s;cin>>s;
        ll flag=0;
        if(s[0]=='H') flag=26;
        else if(s[0]=='C') flag=13;
        else if(s[0]=='D') flag=0;
        else if(s[0]=='S') flag=39;
        if(s[1]>='0'&&s[1]<='9')
        {
            check[flag+s[1]-'0']=true;
        }
        if(s[1]=='A') check[flag+1]=true;
        if(s[1]=='T') check[flag+10]=true;
        if(s[1]=='J') check[flag+11]=true;
        if(s[1]=='Q') check[flag+12]=true;
        if(s[1]=='K') check[flag+13]=true;
    }
    ll ans=0;
    for(ll i=1;i<=52;i++)
    {
        if(check[i]==false) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
