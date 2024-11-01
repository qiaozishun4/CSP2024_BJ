#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if((n-1)%7==0)
        {
            ll a=(n-1)/7;
            a--;
            cout<<1;
            for(ll i=1;i<=a;i++)
            {
                cout<<8;
            }
            cout<<9;
        }
        else if(n%7==0)
        {
            ll a=n/7;
            for(ll i=1;i<=a;i++)
            {
                cout<<8;
            }
        }
        else
        {
            cout<<-1;
        }
        cout<<endl;
    }
    return 0;
}
