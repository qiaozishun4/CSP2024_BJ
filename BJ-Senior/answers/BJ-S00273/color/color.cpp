#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T;
int n;
int a[N];
int ans;
int fa[N];
int pre[N];

void read()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
}
int col[N];
void dfs(int x,int sum)
{
    if (x>n)
    {
        ans=max(ans,sum);
        return ;
    }
    bool flag1=false,flag2=false;
    for (int i=x;i>=1;i--)
    {
        if (flag1&&flag2) break;
        if (col[i]==1&&flag1==false)
        {
            flag1=true;
            col[x]=1;
            if (a[i]==a[x]) dfs(x+1,sum+a[i]);
            else dfs(x+1,sum);
            col[x]=0;
        }
        if (col[i]==2&&flag2==false)
        {
            flag2=true;
            col[x]=2;
            if (a[i]==a[x]) dfs(x+1,sum+a[i]);
            else dfs(x+1,sum);
            col[x]=0;
        }
    }
    if (flag1==false)
    {
        col[x]=1;
        dfs(x+1,sum);
        col[x]=0;
    }
    if (flag2==false)
    {
        col[x]=2;
        dfs(x+1,sum);
        col[x]=0;
    }
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
        ans=0;
        memset(col,0,sizeof col);
        read();
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
