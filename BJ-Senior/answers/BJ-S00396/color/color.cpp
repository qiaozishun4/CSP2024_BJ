#include<bits/stdc++.h>
using namespace std;
int a[200005],n,ans;
void dfs(int i,int s,int r,int b)
{
    if(i>n)
    {
        ans=max(s,ans);
        return ;
    }
    if(a[i]==r)
    {
        dfs(i+1,s+a[i],r,b);
        return ;
    }
    if(a[i]==b)
    {
        dfs(i+1,s+a[i],r,b);
        return ;
    }
    dfs(i+1,s+(a[i]==r?r:0),a[i],b);
    dfs(i+1,s+(a[i]==b?b:0),r,a[i]);
}
int f[2005][2005][2],h[200005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int i,j,m,k,x,y,s=0,l,r;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(n<=15)
        {
        ans=0;
        dfs(1,0,0,0);
        cout<<ans<<"\n";
        continue;
        }
        if(n<=2000)
        {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                f[i][j][0]=f[i-1][j][0]+(a[i]==a[i-1]?a[i]:0);
                for(k=1;k<i;k++)
                {
                    f[i][j][0]=max(f[i][j][0],f[i-1][k][1]+(a[i]==a[k]?a[i]:0));
                }
            }
            for(j=1;j<i;j++)
            {
                f[i][j][1]=f[i-1][j][1]+(a[i]==a[i-1]?a[i]:0);
                for(k=1;k<i;k++)
                {
                    f[i][j][1]=max(f[i][j][1],f[i-1][k][0]+(a[i]==a[k]?a[i]:0));
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            s=max(f[n][i][0],s);
            s=max(f[n][i][1],s);
        }
        cout<<s<<"\n";
        continue;
        }
        int b;
        r=b=0;
        s=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]==r)
            {
                s+=a[i];
            }
            if(a[i]==b)
            {
                s+=a[i];
            }
            if(a[i]!=r&&a[i]!=b)
            {
                if(r<b)
                {
                    r=a[i];
                }
                else
                {
                    b=a[i];
                }
            }
        }
        cout<<s<<"\n";
    }
    return 0;
}