#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    ll l,r,v;
};
node s[1000005];
ll m=0;
ll a[200005];
ll cnt[1000005];
ll l[1000005];
ll r[1000005];
ll cnt2[1000005];
bool cmp(node a,node b)
{
    return a.v>b.v;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ll t;
    cin>>t;
    while(t--)
    {
        m=0;
        memset(cnt,0,sizeof(cnt));
        memset(cnt2,0,sizeof(cnt2));
        ll n;
        cin>>n;
        for(ll i=1; i<=n; i++)
        {
            cin>>a[i];
            cnt[a[i]]++;
            if(cnt[a[i]]==1)l[a[i]]=i;
            r[a[i]]=i;
            // cout<<s[i].l<<" "<<s[i].r<<endl;
        }
        for(int i=1; i<=1000000; i++)
        {
            if(cnt[i]>=2)
            {
                m++;
                s[m].l=l[i];
                s[m].r=r[i];
                s[m].v=cnt[i]*i-i;
                // cout<<"|"<<l[i]<<" "<<r[i]<<" "<<i<<endl;
            }
        }
        sort(s+1,s+m+1,cmp);
        ll ans=0;
        for(int i=1; i<=m; i++)
        {
            // cout<<"!";
            bool flag=false;
            for(int j=s[i].l; j<=s[i].r; j++)
            {
                if(cnt2[j]>=2)
                {
                    flag=true;
                    break;
                }
            }
            // cout<<s[i].l<<" "<<s[i].r<<endl;
            if(flag==true)continue;
            for(int j=s[i].l; j<=s[i].r; j++)
            {
                cnt2[j]++;
                // cout<<"*"<<j<<"\n";
            }
            ans+=s[i].v;
        }
        cout<<ans<<endl;
    }
    return 0;
}