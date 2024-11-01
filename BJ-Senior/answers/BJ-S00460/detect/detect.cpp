#include <bits/stdc++.h>
#define ll long long
using namespace std;
int d[100005],v[100005],a[100005],p[100005],ans;
bool b[100005];
int cnt1,cnt2,n,m,l,V,cnt;
bool check()
{
    int res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!b[j])
            {
                if(p[j]>=d[i])
                {
                    if(1ll*(1ll*v[i]*v[i]+2ll*a[i]*(p[j]-d[i]))>1ll*V*V)
                    {
                        res++;
                        break;
                    }
                }
            }
        }
    }
    return res==cnt1;
}
void dfs(int cur)
{
    if(cur>m)
    {
        if(check())
        {
            int Count=0;
            for(int i=1;i<=m;i++)
            {
                if(b[i])
                {
                    Count++;
                }
            }
            ans=max(ans,Count);
        }
        return ;
    }
    cnt++;
    b[cnt]=1;
    dfs(cur+1);
    b[cnt]=0;
    dfs(cur+1);
    cnt--;
    return ;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        cnt1=0,cnt2=0;
        if(n<=20&&m<=20)
        {
            memset(b,0,sizeof(b));
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(p[j]>=d[i])
                    {
                        if(1ll*(1ll*v[i]*v[i]+2ll*a[i]*(p[j]-d[i]))>1ll*V*V)
                        {
                            cnt1++;
                            break;
                        }
                    }
                }
            }
            ans=-2e9+5;
            cnt=0;
            dfs(1);
            cout<<cnt1<<" "<<ans<<"\n";
        }
        else//特殊性质A，B
        {
            for(int i=1;i<=n;i++)
            {
                if(p[m]>=d[i])
                {
                    if(1ll*(1ll*v[i]*v[i]+2ll*a[i]*(p[m]-d[i]))>1ll*V*V)//在最后一个点会被判超速
                    {
                        cnt1++;
                    }
                }
            }
            if(cnt1==0)
            {
                cnt2=m;
            }
            else
            {
                cnt2=m-1;
            }
            cout<<cnt1<<" "<<cnt2<<"\n";
        }
    }
    return 0;
}
