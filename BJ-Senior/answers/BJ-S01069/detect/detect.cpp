#include <bits/stdc++.h>
#define int long long
#define MAXN 500010
#define INF 1000000000000000
using namespace std;
int n,m,L,V,p[MAXN],dif[MAXN],cnt;
struct car
{
    int d,v,a;
    int l,r;
}a[MAXN];
int vis[MAXN];
int id[MAXN],s[MAXN];
bool cmp(int i,int j)
{
    return s[i]>s[j];
}
int fA,fB,fC;
void Clear()
{
    memset(dif,0,sizeof(dif));
    memset(vis,0,sizeof(vis));
    memset(s,0,sizeof(s));
    memset(p,0,sizeof(p));
    cnt=0;
    fA=fB=fC=1;
}
int vvis[MAXN];
void solve()
{
    Clear();
    cin>>n>>m>>L>>V;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].d>>a[i].v>>a[i].a,a[i].l=a[i].r=0;
        if(a[i].a) fA=0;
        if(a[i].a<=0) fB=0;
        if(a[i].a>=0) fC=0;
    }
    for(int i=1;i<=m;i++) cin>>p[i];
   // p[m+1]=INF;
    for(int i=1;i<=n;i++)
    {
        if(!a[i].a)
        {
            if(a[i].v>V)
            {
                int pos=lower_bound(p+1,p+1+m,a[i].d)-p;
                if(p[pos]>=a[i].d)
                {
                    cnt++;
                    dif[pos]++;
                    dif[m+1]--;
                    a[i].l=pos;
                    a[i].r=m;
                    //cout<<"!!!  "<<i<<endl;
                }
            }
        }
        else if(a[i].a>0)
        {
            int dx=(1.0*(V*V-a[i].v*a[i].v)/(2*a[i].a));
            int pos=lower_bound(p+1,p+1+m,a[i].d+dx)-p;
            if(pos>0&&pos<=m&&p[pos]>=a[i].d+dx)
            {
                cnt++;
                dif[pos]++;
                dif[m+1]--;
                a[i].l=pos,a[i].r=m;
                //cout<<"!!!  "<<i<<endl;
            }
        }
        else
        {
            if(a[i].v<V) continue;
            int dx=(floor)(1.0*(a[i].v*a[i].v-V*V)/(-2*a[i].a));
            int pos=upper_bound(p+1,p+2+m,a[i].d+dx)-p-1;
            //if(pos<=0)pos=
            int lpos=lower_bound(p+1,p+1+m,a[i].d)-p;
            if(lpos>0&&lpos<=m&&pos>0&&pos<=m&&p[pos]<=a[i].d+dx&&lpos<=pos)
            {
                cnt++;
                dif[lpos]++;
                dif[pos+1]--;
                a[i].l=lpos;a[i].r=pos;
                //cout<<"!!!  "<<i<<" "<<lpos<<" "<<pos<<endl;
            }
        }
    }
    cout<<cnt<<' ';
    if(n<=20&&m<=20)
    {
        int ans=m;
        for(int S=0;S<(1<<m);S++)
        {
            int pc=0,flag=1;
            for(int i=1;i<=m;i++) vvis[i]=0;
            for(int i=1;i<=m;i++)
                if(S&(1<<i-1))
                    vvis[i]++,vvis[i+1]--,pc++;
            for(int i=1;i<=m;i++) vvis[i]+=vvis[i-1];
            for(int i=1;i<=m;i++) vvis[i]+=vvis[i-1];
            for(int i=1;i<=n;i++)
                if(a[i].l&&a[i].r&&vvis[a[i].r]-vvis[a[i].l-1]<=0)
                {
                    flag=0;
                    break;
                }
            if(flag) ans=min(ans,pc);
        }
        cout<<m-ans<<'\n';
        return;
    }
    if(fA||fB)
    {
        int flag=0;
        for(int i=1;i<=n;i++)
            if(a[i].l&&a[i].r){
                flag=1;
                break;
            }
        cout<<m-flag<<'\n';
        return;
    }
    for(int i=1;i<=m;i++) s[i]=s[i-1]+dif[i],id[i]=i;
    sort(id+1,id+1+m,cmp);
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int c=0;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&a[j].l<=id[i]&&id[i]<=a[j].r)
                vis[j]=1,c++;
        }
        if(c)
        {
            //cout<<endl<<"!!! "<<i<<' '<<a[j].l<<" "<<a[j].r;
            ans++;
        }
    }
    cout<<m-ans<<'\n';
}
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    int _T=1;cin>>_T;
    while(_T--)solve();
    return 0;
}
// cmp /home/csps/detect/detect.out /home/csps/detect/detect2.ans
