#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=2e5+10;
int a[N];
signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        map<int,int> mp;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(mp[a[i]]!=0) ans+=a[i];
            mp[a[i]]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
