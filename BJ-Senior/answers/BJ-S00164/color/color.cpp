#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,s,t;
map<int,int> mp;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int i,j,k,x;
    cin>>t;
    while (t--)
    {
        cin>>n;
        mp.clear();
        for (s=0,i=1;i<=n;i++)
        {
            cin>>x;
            if (mp[x])
                s+=x;
            mp[x]=1;
        }
        cout<<s<<endl;
    }
    return 0;
}
