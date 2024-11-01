#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n;
int t;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%7!=0)
        {
            cout<<-1<<'\n';
            continue;
        }
        for(int i=1;i<=n/7;i++)
        {
            cout<<8;
        }
        cout<<'\n';
    }
    return 0;
}
