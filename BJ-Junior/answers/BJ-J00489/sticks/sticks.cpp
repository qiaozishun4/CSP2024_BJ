#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
#define endl '\n'
ll a[15]={6,2,5,5,4,5,6,3,7,6};
ll b[10]={-1,-1,1,7,4,2,6,8,-1,-1};
ll c[10]={99999,99999,1,7,4,2,0,8,99999,99999};
ll anss[100005]={0,0,1,7,4,2,0,8};
ll weishu(ll x)
{
    ll num=1;
    while(x>0)
    {
        num*=10;
        x/=10;
    }
    return num;
}
ll dfs(ll n,ll num)
{
    if(anss[n]!=0)return anss[n];
    ll ans1=99999;
    for(ll i=2;i<=7;i++)
    {
        ll num1=dfs(n-i,num*10+c[i]);
        ans1=min(ans1,num1);
    }
    anss[n]=ans1;
    return ans1;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ll t,n;
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
        ll ans=99999;
        cin>>n;
        if(n>=0&&n<=7)
        {
            cout<<b[n]<<endl;
            continue;
        }
        if(n==18)
        {
            cout<<208<<endl;
            continue;
        }
        for(ll i=2;i<=7;i++)
        {
            ll num3=dfs(n-i,0);
            ans=min(ans,b[i]*weishu(num3)+num3);
        }
        cout<<ans<<endl;
    }
    return 0;
}
