#include <bits/stdc++.h>

using namespace std;
int ans=0;
int n,m,L,V;
int d[100010],v[100010],a[100010],p[100010];
bool b[100010];
int xx[100010],yy[100010];
int cnt=0;
void check(string s)
{
    bool bb[100010];
    int cnt1=0;
    int numl=0;
    for(int i=1;i<=m;i++)
    {
        if(s[i-1]=='0')
        {
            numl++;
            continue;
        }
        for(int j=1;j<=n;i++)
        {
            if(b[j]==0)
            {
                if(xx[j]<=p[i]&&p[i]<<yy[j])
                {
                    cnt1++;
                    bb[j]=1;
                }
            }
        }
    }
    if(cnt1==cnt) ans=max(ans,numl);
    return ;
}
void dfs(int step,string s)
{
    if(step==m)
    {
        //cout<<s;
        check(s);
        return ;
    }
    dfs(step+1,s+"1");
    dfs(step+1,s+"0");
    return ;
}
void solve()
{
    memset(b,0,sizeof(b));
    memset(xx,-1,sizeof(xx));
    memset(yy,-1,sizeof(yy));
    ans=0;
    cin>>n>>m>>L>>V;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i]>>v[i]>>a[i];
        if(a[i]==0)
        {
            if(v[i]>V)
            {
                xx[i]=d[i];
                yy[i]=L;
            }

        }
        if(a[i]>0)
        {
            if(v[i]>=V)
            {
                if(v[i]==V) xx[i]=d[i]+1,yy[i]=L;
                else xx[i]=d[i],yy[i]=L;
            }
            else
            {
                double ss=1.0*d[i]+1.0*(V*V-v[i]*v[i])/2/a[i];
                if(ss<=1.0*L)
                {
                    xx[i]=ss;
                    xx[i]++;
                    yy[i]=L;
                }
            }
        }
        if(a[i]<0)
        {
            if(v[i]>V)
            {
                a[i]=-a[i];
                xx[i]=d[i];
                yy[i]=1.0*(v[i]*v[i]-V*V)/2/a[i]+d[i];
                a[i]=-a[i];
            }
        }
    }

    cnt=0;

    for(int i=1;i<=m;i++)
    {
        cin>>p[i];
        for(int j=1;j<=n;j++)
        {
            if(b[j]==0 && xx[j]<=p[i] && p[i]<=yy[j])
            {
                cnt++;
                b[j]=true;
            }
        }
    }

    cout<<cnt<<" ";

    dfs(0,"");
    cout<<ans;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
