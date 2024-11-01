#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ll n=0;
    cin>>n;
    vector<ll> duel(n,0);
    vector<bool> vis(n,1);
    for(ll i=0;i<n;i++)
    {
        cin>>duel[i];
    }
    sort(duel.begin(),duel.end());
    ll sum=n;
    for(ll i=0;i<n-1;i++)
    {
        for(ll j=i;j<n;j++)
        {
            if(duel[i]<duel[j]&&vis[j])
            {
                sum--;
                vis[j]=0;
                break;
            }
            else
            {
                continue;
            }
        }
    }
    cout<<sum;
}
