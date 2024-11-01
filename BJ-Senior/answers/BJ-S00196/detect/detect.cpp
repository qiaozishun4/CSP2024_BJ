#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,L,t,p[N],d[N],cnt[N],maxright,minleft,ans,ed[N],stt[N],cats[N];
vector <int> G[N];//每个探测能抓到哪些车
vector <int> cat[N];//每辆车被哪些探抓到
double V,v[N],a[N];
bool f[N];
struct Node
{
    int vl,id;
}sum[N];
inline bool cmp(Node x,Node y)
{
    return x.vl<y.vl;
}
inline bool check(int x)
{
    int last=1;
    while(x--)
    {
        bool ls=false;
        for(int i=last;i<=m;i++)
        {
            int now=sum[i].id;
            ls=false;
            for(auto q:G[now])
            {
                if(cats[q]==1)
                {
                    ls=true;
                    break;
                }
                else cats[q]--;
            }
            if(!ls)
            {
                last=i+1;
                break;
            }
        }
        if(ls) return false;
    }
    return true;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
        {
            f[i]=false;
            cin>>d[i]>>v[i]>>a[i];
        }
        minleft=1e9+7,maxright=0;
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
            maxright=max(maxright,p[i]);
            minleft=min(minleft,p[i]);
        }
        for(int i=1;i<=n;i++)
        {
            int l=1,r=m;
            while(l<r)
            {
                int mid=l+r>>1;
                if(d[i]>p[mid]) l=mid+1;
                else  r=mid;
            }
            stt[i]=l;
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(v[i]<=V||d[i]>maxright) continue;
                else
                {
                    ans++;
                    f[i]=true;
                } 
                ed[i]=m;
            }
            else if(a[i]>0)
            {
                if(d[i]>maxright) continue;
                double vs=sqrt(v[i]*v[i]+2*a[i]*double(1.0*(p[m]-d[i])));
                if(vs>V)
                {
                    ans++;
                    f[i]=true;
                } 
                ed[i]=m;
            }
            else 
            {
                if(d[i]>maxright) continue;
                double vs=sqrt(v[i]*v[i]+2*a[i]*double(1.0*(p[stt[i]]-d[i])));
                if(vs>V)
                {
                    ans++;
                    f[i]=true;
                } 
                int l=1,r=m;
                while(l<r)
                {
                    int mid=l+r+1>>1;
                    int cur=-1*v[i]*v[i]/(2*a[i]);
                    if(cur+d[i]>=p[mid]) l=mid;
                    else r=mid-1;
                }
                ed[i]=l;
            }
        }
        cout<<ans<<" ";



        for(int i=1;i<=n;i++)
        {
            if(f[i])
            {
                if(a[i]>0)
                {
                    int l=1,r=m;
                    while(l<r)
                    {
                        int mid=l+r>>1;
                        int cur=(V*V-v[i]*v[i])/(2*a[i]);
                        if(cur+d[i]<p[mid]) r=mid;
                        else l=mid+1;
                    }
                   // sum[l]++;
                  //  sum[m+1]--;
                    for(int j=l;j<=m;j++) 
                    {
                        G[j].push_back(i);
                        cat[i].push_back(j);
                    }
                }
                else if(a[i]==0)
                {
                  //  sum[stt[i]]++;
                    //sum[m+1]--;
                    for(int j=stt[i];j<=m;j++) 
                    {
                        G[j].push_back(i);
                        cat[i].push_back(j);
                    }
                }
                else if(a[i]<0)
                {
                  //  sum[stt[i]]++;
                   // sum[ed[i]+1]--;
                    for(int j=stt[i];j<=ed[i];j++) 
                    {
                        G[j].push_back(i);
                        cat[i].push_back(j);
                    }
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            sum[i].vl=G[i].size();
            sum[i].id=i;
        }
        for(int i=1;i<=n;i++)
        {
            cats[i]=cat[i].size();
        }
        sort(sum+1,sum+1+m,cmp);
        int l=0,r=m;
        while(l<r)
        {
            int mid=l+r+1>>1;
            if(check(mid)) l=mid;
            else r=mid-1;
        }   
        cout<<l<<endl;
    }
    return 0;
}