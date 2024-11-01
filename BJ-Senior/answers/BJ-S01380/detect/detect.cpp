#include<bits/stdc++.h>
using namespace std;
double n,m,t,l,xian,weizhi,d[100005],v[100005],a[100005],tou[100005],wei[100005];
int buer,y[100005],ans,qu,sum,sam;
bool b[100005],che[100005];
void pan()
{
    memset(che,0,sizeof(che));
    sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[j]==1)
            {
                if(tou[i]<=y[j]&&y[j]<=wei[i])
                {
                    if(che[i]==0)
                    {
                        sum++;
                    }
                    che[i]=1;
                }
            }

        }
    }
    if(sum!=ans)
        return ;
    for(int i=1;i<=n;i++)
    {
        if(b[i]==0)
            sam++;
    }
    qu=max(qu,sam);
    sam=0;
    return ;
}
void dfs(int wei,bool liu)
{
    b[wei]=liu;
    if(wei>=n)
    {
        pan();
        return ;
    }
    dfs(wei+1,1);
    dfs(wei+1,0);
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        memset(y,0,sizeof(y));
        memset(b,0,sizeof(b));
        memset(che,0,sizeof(che));
        ans=0;
        qu=0;
        cin>>n>>m>>l>>xian;
        for(int j=1;j<=n;j++)
        {
            cin>>d[j]>>v[j]>>a[j];
        }
        for(int j=1;j<=m;j++)
        {
            cin>>y[j];
        }
        for(int j=1;j<=n;j++)
        {
            if(a[j]==0)
            {
                if(v[j]>xian)
                {
                    tou[j]=d[j];
                    wei[j]=l;
                }
            }
            if(a[j]>0)
            {
                if(v[j]<=xian)
                    tou[j]=d[j]+(pow(xian,2)-pow(v[j],2))/(2*a[j]),wei[j]=l-0.001;
                if(v[j]>xian)
                    tou[j]=d[j],wei[j]=l;
            }
            if(a[j]<0)
            {
                if(v[j]>xian)
                    wei[j]=d[j]+(pow(xian,2)-pow(v[j],2))/(2*a[j])-0.001,tou[j]=d[j];
            }
            for(int k=1;k<=m;k++)
            {
                if(tou[j]<=y[k]&&y[k]<=wei[j])
                {
                    if(che[j]==0)
                    {
                        ans++;
                    }
                    che[j]=1;
                }
            }
        }
        dfs(1,1);
        dfs(1,0);
        cout<<ans<<" "<<qu<<endl;
    }
    return 0;
}
