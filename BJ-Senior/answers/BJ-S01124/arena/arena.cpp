#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[510],ar[510],b[510],c[510];
string g[110];
int t, ta[510][5],ans;
int yh(int x,int y)
{
    return ((~(x&y))&(x|y));
}
int cal(int aim)
{
    int sum=1;
    k=0;
    while(aim>sum)
    {
        k++;
        sum*=2;
    }
    return k;
}
int dfs(int l,int r,int dep)
{
    int sum=0;
    if(dep==2)
    {
        int mid=(l+r)/2,a,b;
        a=dfs(l,mid,dep-1);
        b=dfs(mid+1,r,dep-1);
        if(a==-1)
        {
            sum+=3;
        }
        else{
            sum+=a;
        }
        if(b==-1)
        {
            sum+=7;
        }
        else{
            sum+=b;
        }
        return sum;
    }if(dep==3)
    {
        int mid=(l+r)/2,a,b;
        a=dfs(l,mid,dep-1);
        b=dfs(mid+1,r,dep-1);
        return a+b;
    }
    if(b[g[1][r/2]-'0'+l]>=dep)
    {
        return g[1][r/2]-'0'+l;
    }
    else if(b[g[1][r/2]-'0'+l]!=-1)
    {
        return r*2-1-(g[1][r/2]-'0'+l);
    }
    else if(b[g[1][r/2]-'0'+l]==-1)
    {
        return 0;
    }
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>g[k];
    }
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        for(int j=0;j<=3;j++)
        {
            cin>>ta[i][j];
        }
       for(int j=1;j<=n;j++)
       {
           ar[j]=yh(a[j],ta[i][j%4]);
       }
       ans=0;
       for(int j=1;j<=m;j++)
       {
           for(int w=1;w<=pow(2,cal(c[j]));w++)
           {
               if(w<=c[j])
               {
                   b[w]=ar[w];
               }
               else
               {
                   b[w]=-1;
               }
           }
           ans+=j*dfs(1,pow(2,cal(c[j])),cal(c[j]));
       }
       cout<<ans<<endl;
    }
    return 0;
}
