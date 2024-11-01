#include<bits/stdc++.h>
using namespace std;
struct det
{
    int pos;
};
det cam[100010];
int d[100010];
int color[100010];
int v[100010];
int a[100010];
int n,m,L,V;
int ans2=0;
int ans3=0;
int ans1=0;
int getnum()
{
    int ans=0,tmp=999999;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(cam[j].pos<d[i])
            {
                continue;
            }
            double spedn=sqrt(1.0*v[i]*v[i]+1.0*2*a[i]*(cam[j].pos-d[i]));
            if(spedn<=0.0)
            {
                break;
            }
            if(spedn>1.0*V)
            {
                ans++;
                break;
            }
        }
    }
    return ans;
}
void dfs(int dep)
{
    if(dep==m)
    {
        int ans=0,tmp=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(color[j-1]==1)
                {
                    continue;
                }
                if(cam[j].pos<d[i])
                {
                    continue;
                }
                int spedn=1.0*v[i]*v[i]+1.0*2*a[i]*(cam[j].pos-d[i]);
                if(spedn<0)
                {
                    continue;
                }
                spedn=sqrt(spedn);
                //cout<<j<<endl;
                if(spedn<=0)
                {
                    break;
                }
                if(spedn>V)
                {
                    tmp++;
                    break;
                }
            }
        }
        //cout<<endl;
        for(int i=0;i<m;i++)
        {
            if(color[i]==1)
            {
                ans++;
            }
        }
        if(tmp==ans1)
        {
            /*cout<<ans1<<" "<<tmp<<endl;
            for(int i=0;i<m;i++)
            {
                cout<<color[i];
            }
            cout<<endl;*/
            ans3=max(ans3,ans);
        }
        return ;
    }
    color[dep]=0;
    dfs(dep+1);
    color[dep]=1;
    dfs(dep+1);
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int segnum=0;
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&cam[i].pos);
        }
        ans1=getnum();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(cam[j].pos<d[i])
                {
                    continue;
                }
                double spedn=sqrt(1.0*v[i]*v[i]+1.0*2*a[i]*(cam[j].pos-d[i]));
                if(spedn<=0.0)
                {
                    break;
                }
                if(spedn>1.0*V)
                {
                    ans2=max(ans2,j);
                    break;
                }
            }
        }
        if(n<=20 && m<=20)
        {
            dfs(0);
            ans2=ans3;
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}