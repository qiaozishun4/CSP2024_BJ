#include<bits/stdc++.h>
using namespace std;
int d[100010],v[100010],a[100010],p[100010],vis[100010];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,l,V;
        cin>>n>>m>>l>>V;
        for(int i=1; i<=n; i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1; i<=m; i++)
        {
            cin>>p[i];
        }
        int ans=m,num=0;
        for(int i=1; i<=n; i++)
        {
            int po;
            if(a[i]==0)
            {
                if(v[i]<=V)
                {
                    continue;
                }
                else
                {
                    po=d[i];
                }
            }
            if(a[i]>0)
            {
                if(v[i]>V)
                {
                    po=d[i];
                }
                else
                {
                    double s=ceil((V-v[i])/a[i]);
                    po=(v[i]+v[i]+a[i]*s)*s/2+d[i];
                    if(po>l)
                    {
                        continue;
                    }
                }
            }
            int L=1,R=m;
            while(L<R)
            {
                int mid=(L+R)/2;
                if(p[mid]<po)
                {
                    L=mid+1;
                }
                else
                {
                    R=mid;
                }
            }
            if(!vis[L])
            {
                vis[L]=1;
                ans--;
            }
            num++;
        }
        cout<<num<<" "<<ans<<endl;
    }
}
