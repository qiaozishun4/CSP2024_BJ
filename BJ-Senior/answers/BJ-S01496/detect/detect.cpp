#include<bits/stdc++.h>
using namespace std;
const long long N=100005;
long long n,m,L,V,T,d[N],v[N],a[N],p[N],mid,ans,sum,cnt;
bool vis[N];
long long midb(long long le,long long ri,long long u)
{
    ans = -1;
    while(le<=ri)
    {
        mid = (le+ri)/2;
        if(p[mid]>=u)
        {
            ans = mid;
            ri = mid-1;
        }
        else
        {
            le = mid+1;
        }
    }
    return ans;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(v[i]<=V)
                {
                    continue;
                }
                else
                {
                    long long f=midb(1,m,d[i]);
                    if(f!=-1)
                    {
                        sum++;
                        vis[f] = 1;
                    }
                    continue;
                }
            }
            if(a[i]<0&&v[i]<=V)
            {
                continue;
            }
            long long f=V*V-v[i]*v[i],ff=2*a[i];
            bool tf=(abs(f)%abs(ff)!=0);
            if(a[i]>0)
            {
                long long fff=(1,m,d[i]+f/ff+(1-tf));
                if(fff!=-1)
                {
                    sum++;
                    vis[fff] = 1;
                }
            }
            else
            {
                long long fff=(1,m,d[i]);
                if(fff!=-1&&p[fff]<=d[i]+f/ff+tf-1)
                {
                    sum++;
                    vis[fff] = 1;
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(vis[i]==0)
            {
                cnt++;
            }
        }
        cout<<sum<<" "<<cnt<<endl;
    }
    return 0;
}