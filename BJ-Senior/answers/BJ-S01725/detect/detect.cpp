#include<bits/stdc++.h>
using namespace std;
int t,d[100005],a[100005],b[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(d,0,sizeof(d));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int n,m,l,v,p=0,ans=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>a[i]>>b[i];
        }
        for(int i=1;i<=m;i++)
        {
            int k;
            cin>>k;
            p=max(p,k);
        }
        for(int i=1;i<=n;i++)
        {
            if(sqrt(a[i]+2*b[i]*(p-d[i]))>v)
            {
                ans++;
            }
        }
        cout<<ans<<" "<<m-1<<endl;
    }
    return 0;
}
