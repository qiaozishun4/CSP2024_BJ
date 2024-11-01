#include <bits/stdc++.h>
#define int long long
using namespace std;
set<char>a,b,c,d;
int n;
signed main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    while(n--)
    {
        char op,who;
        cin>>op>>who;
        if(op=='D')
        {
            a.insert(who);
        }
        if(op=='C')
        {
            b.insert(who);
        }
        if(op=='H')
        {
            c.insert(who);
        }
        if(op=='S')
        {
            d.insert(who);
        }
    }
    int ans=52;
    ans-=a.size();
    ans-=b.size();
    ans-=c.size();
    ans-=d.size();
    cout<<ans;
    return 0;
}
