#include<bits/stdc++.h>
using namespace std;
struct node{
    int d,v,a;
    float t;
    float s;
    bool vis;
}c[100005];
struct nodee
{
    int va,su;
}cs[100005];
int cmp(nodee A,nodee B)
{
    return A.va>B.va;
}
int sum,ans;
int T,n,m,L,V;
void dfs(int cur,int ch,int db)
{
    if(cur==m) return;
    int sum=0;
    for(int i=cur+1;i<=m;i++)
    {
        if(i==db) continue;
        for(int j=1;j<=n;j++)
        {
            if(cs[i].va>=c[j].s && !c[j].vis && c[i].a>0)
            {
                c[j].vis=true;
                sum++;
            }
            else if(cs[i].va<c[j].s && cs[i].va>=c[j].d && !c[j].vis && c[i].a<0)
            {
                c[j].vis=true;
                sum++;
            }
            else if(c[j].a==0 && !c[j].vis)
            {
                c[j].vis=true;
                sum++;
            }
        }
        if(sum==ch)
        {
            ans=max(ans,cur+1);
            dfs(cur,ch,db+1);
        }
    }
    dfs(cur+1,ch,cur+1);
    return ;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin>>T;
    while(T--)
    {
        sum=0,ans=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>c[i].d>>c[i].v>>c[i].a;
            if(c[i].a==0)
            {
                if(c[i].v>V)
                {
                    c[i].vis=false;
                }
                else c[i].vis=true;
            }
            else if(c[i].a<0)
            {
                if(c[i].v<=V) c[i].vis=true;
                else
                {
                    c[i].t=float((V-c[i].v)/c[i].a);
                    c[i].s=float(c[i].v*c[i].t+0.5*c[i].a*c[i].t*c[i].t+c[i].d);
                    c[i].vis=false;
                }

            }
            else{
                c[i].t=float((V-c[i].v)/c[i].a);
                c[i].s=float(c[i].v*c[i].t+0.5*c[i].a*c[i].t*c[i].t+c[i].d);
                c[i].vis=false;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cin>>cs[i].va;
            for(int j=1;j<=n;j++)
            {
                if(cs[i].va>=c[j].s && !c[j].vis && c[i].a>0)
                {
                    c[j].vis=true;
                    sum++;
                }
                else if(cs[i].va<c[j].s && cs[i].va>=c[j].d && !c[j].vis && c[i].a<0)
                {
                    c[j].vis=true;
                    sum++;
                }
                else if(c[j].a==0 && !c[j].vis)
                {
                    c[j].vis=true;
                    sum++;
                }
            }
        }
        sort(cs,cs+m+1,cmp);
        int minn=1e9,maxx=-1e9;
        for(int i=1;i<=n;i++)
        {
            minn=min(minn,c[i].d);
            maxx=max(maxx,c[i].d+L);
        }
        dfs(1,sum,1);
        cout<<sum<<" "<<ans<<endl;
    }
}
