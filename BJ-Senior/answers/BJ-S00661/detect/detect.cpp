#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,p[114514],rem[114514],c[114514];
double np[114514];
double d[114514],v[114514],a[114514],V;
vector<int> g[114514];
double plaspeed(int vv,int x,int s)
{
    if(x<0) return -1;
    if(vv*vv+2*x*s<0) return -1;
    return sqrt(vv*vv+2*x*s);
}
bool check()
{
    for(int i=1;i<=n;i++)
    {
        //cout<<rem[i];
        if(rem[i]==0&&c[i]==1)
            //cout<<"\n";
            return 0;
    }
    //cout<<"\n";
    return 1;
}
int dfs(int x,int num)
{
    if(x==m+1)
    {
        if(check())
            return num;
        return 114514;
    }
    int cnt=114514;
    cnt=min(cnt,dfs(x+1,num));
    for(int i=0;i<g[x].size();i++)
    {
        //cout<<i;
        rem[g[x][i]]=1;
    }
    cnt=min(cnt,dfs(x+1,num+1));
    for(int i=0;i<g[x].size();i++)
    {
        rem[g[x][i]]=0;
    }
    //cout<<cnt<<"\n";
    return cnt;
}
void tsszA()
{
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int j=m;
            double ts=plaspeed(v[i],p[j]-d[i],a[i]);
            if(ts>V)
            {
                ans++;
            }
        }
        cout<<ans<<" ";
        if(ans==0) cout<<m<<"\n";
        else cout<<m-1<<"\n";
        return;
}
void tsszB()
{
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int j=m;
            double ts=plaspeed(v[i],p[j]-d[i],a[i]);
            if(ts>V)
            {
                ans++;
            }
        }
        cout<<ans<<" ";
        if(ans==0) cout<<m<<"\n";
        else cout<<m-1<<"\n";
        return;
}
void tsszC()
{
        int ans=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            bool flag=0;
            for(int j=1;j<=m;j++)
            {
                double ts=plaspeed(v[i],p[j]-d[i],a[i]);
                if(ts>V)
                {
                    c[i]=1;
                    if(flag==0)
                    {
                        ans++;
                        flag=1;
                    }
                    g[j].push_back(i);
                }
            }
        }
        cnt=dfs(1,0);
        cout<<ans<<" "<<m-cnt<<"\n";
        return;
}
void tsszNAN()
{
        int ans=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            bool flag=0;
            for(int j=1;j<=m;j++)
            {
                double ts=plaspeed(v[i],p[j]-d[i],a[i]);
                if(ts>V)
                {
                    c[i]=1;
                    if(flag==0)
                    {
                        ans++;
                        flag=1;
                    }
                    g[j].push_back(i);
                }
            }
        }
        cnt=dfs(1,0);
        cout<<ans<<" "<<m-cnt<<"\n";
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(p,0,sizeof(p));
        memset(rem,0,sizeof(rem));
        memset(c,0,sizeof(c));
        for(int i=1;i<114514;i++) g[i].clear();
        cin>>n>>m>>l>>V;
        bool tssz1=1,tssz2=1,tssz3=1;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]!=0) tssz1=0;
            if(a[i]<=0) tssz2=0;
            if(a[i]>=0) tssz3=0;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        sort(p+1,p+m+1);
        if(tssz1) tsszA();
        else if(tssz2) tsszB();
        else if(tssz3) tsszC();
        else tsszNAN();
    }
    return 0;
}
