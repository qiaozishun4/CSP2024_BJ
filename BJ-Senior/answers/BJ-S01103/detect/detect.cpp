/*
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int d,v,a;
}c[100005];
int p[100005];
int q[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,l,V;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>c[i].d>>c[i].v>>c[i].a;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        int cnt1=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(c[i].d<=p[j])
                {
                    int s=p[j]-c[i].d;
                    double vt=sqrt((double)c[i].v*c[i].v+2*c[i].a*s);
                    if(vt>(double)V)
                    {
                        cnt1++;
                        break;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(c[i].d<=p[j])
                {
                    int s=p[j]-c[i].d;
                    double vt=sqrt((double)c[i].v*c[i].v+2*c[i].a*s);
                    if(vt>(double)V)
                    {
                        q[j]++;
                        cout<<i<<" "<<j<<"\n";
                    }
                }
            }
        }
        int cnt2=0;
        for(int i=1;i<=m;i++)
        {
            if(q[i])
            {
                cnt2++;
            }
        }
        //cout<<cnt1<<" "<<cnt2<<"\n";
    }
    return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 ‐2
6 4 ‐4
2 5 8 9 15
*/
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int d,v,a;
}c[100005];
int p[100005];
int q[100005];
int n,m,l,V;
inline void work1()
{
    int cnt1=0;
    for(int i=1;i<=n;i++)
    {
        if(c[i].d<=p[m])
        {
            int s=p[m]-c[i].d;
            double vt=sqrt((double)c[i].v*c[i].v+2*c[i].a*s);
            if(vt>(double)V)
            {
                cnt1++;
            }
        }
    }
    if(cnt1)
    {
        cout<<cnt1<<" "<<m-1<<"\n";
    }else
    {
        cout<<cnt1<<" "<<m<<"\n";
    }
}
int cnt[100005],ans;
int tmp[100005];
bool chao[100005];
void dfs(int x,int cntt)
{
    if(cntt>=ans)
    {
        return;
    }
    if(x>m)
    {/*
        for(int i=1;i<=m;i++)
        {
            cout<<tmp[i]<<" ";
        }
        cout<<"\n";
        for(int i=1;i<=m;i++)
        {
            cout<<cnt[i]<<" ";
        }
        cout<<"\n";*/
        bool flg=true;
        for(int i=1;i<=n;i++)
        {
            if(!cnt[i]&&chao[i])
            {
                flg=false;
                break;
            }
        }
        if(flg)
        {
            ans=min(ans,cntt);
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(c[i].d<=p[x])
        {
            int s=p[x]-c[i].d;
            double vt=sqrt((double)c[i].v*c[i].v+2*c[i].a*s);
            if(vt>(double)V)
            {
                cnt[i]++;
            }
        }
    }
    tmp[x]=1;
    dfs(x+1,cntt+1);
    for(int i=1;i<=n;i++)
    {
        if(c[i].d<=p[x])
        {
            int s=p[x]-c[i].d;
            double vt=sqrt((double)c[i].v*c[i].v+2*c[i].a*s);
            if(vt>(double)V)
            {
                cnt[i]--;
            }
        }
    }
    tmp[x]=0;
    dfs(x+1,cntt);
}
inline void work2()
{
    memset(chao,0,sizeof(chao));
    //cout<<114<<"\n";
    int cnt1=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(c[i].d<=p[j])
            {
                int s=p[j]-c[i].d;
                double vt=sqrt((double)c[i].v*c[i].v+2*c[i].a*s);
                if(vt>(double)V)
                {
                    cnt1++;
                    chao[i]=1;
                    break;
                }
            }
        }
    }
    ans=m;
    dfs(1,0);
    cout<<cnt1<<" "<<m-ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l>>V;
        bool flg=1;
        for(int i=1;i<=n;i++)
        {
            cin>>c[i].d>>c[i].v>>c[i].a;
            if(c[i].a<0)
            {
                flg=0;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        if(flg)
        {
            work1();
        }else
        {
            work2();
        }
        //cout<<cnt1<<" "<<cnt2<<"\n";
    }
    return 0;
}
