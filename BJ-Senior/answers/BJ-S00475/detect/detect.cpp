#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,ans,n,m,ans1,L,flag[N];double d[N],v[N],a[N],t[N],p[N];bool vis[N];
inline void dfs(int cur,int cnt)
{
    if(cur>m)
    {
        int sum=0;for(int i=1;i<=n;i++) sum+=bool(flag[i]);
        if(sum==ans1) ans=min(ans,cnt);
        return;
    }
    dfs(cur+1,cnt);queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=0&&p[cur]>t[i]&&p[cur]<=L) flag[i]++,q.push(i);
        if(a[i]<0&&p[cur]>=d[i]&&p[cur]<t[i]) flag[i]++,q.push(i);
    }
    dfs(cur+1,cnt+1);
    while(!q.empty()){int i=q.front();q.pop();flag[i]--;}
}
int main()
{
    freopen("detect.in","r",stdin);freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        int V;cin>>n>>m>>L>>V;ans1=0;ans=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]>=0&&v[i]>V){t[i]=d[i]-1;continue;}
            if(a[i]==0&&v[i]<=V){t[i]=L;continue;}
            if(a[i]<0&&v[i]<=V){t[i]=0;continue;}
            if(a[i]) t[i]=d[i]+(V*V-v[i]*v[i])/a[i]/2;
        }
        for(int i=1;i<=m;i++) cin>>p[i];
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=0)
            {
                int pos=upper_bound(p+1,p+m+1,t[i])-p;
                if(pos>=1&&pos<=m)
                {
                    int pos2=upper_bound(p+pos,p+m+1,L)-p-1;
                    ans1+=(vis[i]=(pos2>=pos&&pos2<=m));
                }
            }
            else
            {
                int pos=lower_bound(p+1,p+m+1,d[i])-p;
                if(pos>=1&&pos<=m)
                {
                    int pos2=lower_bound(p+pos,p+m+1,t[i])-p-1;
                    ans1+=(vis[i]=(pos2>=pos&&pos2<=m));
                }
            }
        }
        cout<<ans1<<" ";
        if(n<=20) dfs(1,0),cout<<m-ans<<"\n";
        else cout<<(ans1?m-1:m)<<"\n";
    }
    return 0;
}