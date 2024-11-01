#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ll n,a[10]={6,2,5,5,4,5,6,3,7,6},m;
    ll ans;
    cin>>m;
    for(ll j=0;j<m;j++)
    {
        bool fl=1;
        cin>>n;
        ll ap=n/2;
        ll nm=1;
        for(ll i=0;i<=ap;i++)
        {
            nm=nm*10+1;
        }
        //cout<<nm;
        for(ll i=0;i<=nm;i++)
        {
            ans=0;
            ll t=i;
            while(t>0)
            {
                ans+=a[t%10];
                t/=10;
            }
            //cout<<ans<<" ";
            if(ans==n)
            {
                cout<<i<<"\n";
                fl=0;
                break;
            }
        }
        if(fl) cout<<"-1\n";
    }
    return 0;
}
