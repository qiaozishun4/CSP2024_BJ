#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
int T,n;
ll ans=1e18;
int s[10]={6,2,5,5,4,5,6,3,7,6};
void dfs(int k,ll sum)
{
    if(k<2) return;
    for(int i=0;i<10;i++)
    {
        if(k==6&&sum==0&&i==0) continue;
        if(s[i]==k)
        {
            ll p=sum*10+i;
            ans=min(ans,p);
            return;
        }
    }
    for(int i=0;i<10;i++)
    {
        if(!sum&&!i) continue;
        else if(i==6||i==3||i==5||i==9) continue;
        int l=k-s[i];
        if(l==1) continue;
        ll p=sum*10+i;
        dfs(l,p);
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        int h=n%7;
        if(h==0)
        {
            for(int i=1;i<=n/7;i++) cout<<"8";
            cout<<"\n";
            continue;
        }
        else if(h==1&&n!=1)
        {
            cout<<"10";
            n-=8;
            for(int i=1;i<=n/7;i++) cout<<"8";
            cout<<"\n";
            continue;
        }
        if(n>20) h+=14;
        else h=n;
        ans=1e18;
        dfs(h,0);
        if(ans==1e18) cout<<"-1\n";
        else 
        {
            cout<<ans;
            int g=n-h;
            for(int i=1;i<=g/7;i++) cout<<"8";
            cout<<"\n";
        }
    }
    return 0;
}