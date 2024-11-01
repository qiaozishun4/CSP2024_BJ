#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
#define F(i,a,b) for(int i=a;i<=b;i++)
#define dF(i,b,a) for(int i=b;i>=a;i--)
#define LL long long
int T,n,m,V,L,ans,cnt;
LL d[N],v[N],a[N],p[N],q[N];
double l[N],r[N];
bool vis[N],st[N];
void dfs(int x)
{
    if(x > m)
    {
        int cur = 0;
        F(i,1,n) st[i] = 0;
        F(i,1,m)
            if(v[i]) q[++cur] = p[i];
        F(i,1,n)
            F(j,1,cur)
            {
                if(l[i] > r[i]) continue;
                if(l[i] <= q[j] && q[j] <= r[i]) st[i] = 1;
            }
        int num = 0;
        F(i,1,n) if(st[i]) num++;
        if(num == cnt) ans = max(ans,m-cur);
        return;
    }
    v[x] = 1;
    dfs(x+1);
    v[x] = 0;
    dfs(x+1);
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cnt = 0; ans = 0;
        cin>>n>>m>>L>>V;
        memset(vis,0,sizeof vis);
        F(i,1,n) cin>>d[i]>>v[i]>>a[i];
        F(i,1,m) cin>>p[i];
        F(i,1,n)
        {
            if(a[i] < 0)
            {
                l[i] = d[i];
                r[i] = 1.0*d[i]+1.0*(V*V-v[i]*v[i])/(2*a[i])-0.01;
            }
            else if(a[i] == 0)
            {
                if(v[i] > V)
                {
                    l[i] = d[i];
                    r[i] = L;
                }
                else
                {
                    l[i] = L+1;
                    r[i] = L;
                }
            }
            else
            {
                l[i] = 1.0*d[i]+1.0*(V*V-v[i]*v[i])/(2*a[i])+0.01;
                r[i] = L;
            }
        }
        F(i,1,n)
        {
            if(l[i] > r[i]) continue;
            F(j,1,m)
            {
                if(l[i] <= p[j] && p[j] <= r[i]) vis[i] = 1;
            }
        }
        F(i,1,n)
            if(vis[i]) cnt++;
        dfs(1);
        cout << cnt << ' ' << ans << '\n';
    }
    return 0;
}