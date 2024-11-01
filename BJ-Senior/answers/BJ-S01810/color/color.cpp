#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int nn;
int a[200005],n;
int ans;
int nextt[1000005];
int nextid[200005];
int f[200005];
signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>nn;
        ans=0;
        n=0;
        int x;
        for(int i=1;i<=nn;i++)
        {
            cin>>x;
            nextt[x]=0;
            if(a[n]!=x)
            {
                a[++n]=x;
            }
            else
            {
                ans+=x;
            }
        }
        for(int i=n;i>=1;i--)
        {
            nextid[i]=nextt[a[i]];
            nextt[a[i]]=i;
        }
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            f[i]=max(f[i],f[i-1]);
            if(nextid[i]!=0)
            {
                f[nextid[i]-1]=max(f[nextid[i]-1],f[i]+a[i]);
            }
        }
        cout<<ans+f[n]<<endl;
    }
    return 0;
}
