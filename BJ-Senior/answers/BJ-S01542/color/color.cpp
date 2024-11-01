#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int cnt[1000005];
int ans;
int maxl;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--)
    {
        maxl=0;
        ans=0;
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>m;
            cnt[m]++;
            maxl=max(maxl,m);
        }
        for(int i=1;i<=maxl;i++)
        {
            ans+=max((cnt[i]-1)*i,0);
        }
        cout<<ans<<endl;
    }
    return 0;
}
