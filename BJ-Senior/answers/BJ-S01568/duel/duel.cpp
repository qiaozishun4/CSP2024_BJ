#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll n;
ll a[200005];
void solve()
{
    n=read();
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        ll x=read();
        a[x]++;
        res=max(res,a[x]);
    }
    cout<<res<<'\n';
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ll t=1;
    while(t--)solve();
    return 0;
}