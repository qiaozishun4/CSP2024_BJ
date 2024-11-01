// 事已至此，先写暴力吧。
// 考前为什么会有能上300的错觉。
// 人事已尽，天命难违。

#include<bits/stdc++.h>
using namespace std;
const int Maxn=2e5+10;
int n;
int Ar[Maxn];
int col[Maxn];
int ans=0;
int solve()
{
    int res=0;
    int lst0=-1,lst1=0;
    for(int i=1;i<=n;i++)
    {
        if(col[i]==0 && lst0==Ar[i])
        {
            res+=Ar[i];
        }
        if(col[i]==1 && lst1==Ar[i])
        {
            res+=Ar[i];
        }

        if(col[i]==0) lst0=Ar[i];
        if(col[i]==1) lst1=Ar[i];
    }
    return res;
}
void dfs(int pos)
{
    if(pos==n+1)
    {
        ans=max(ans,solve());
        return ;
    }
    col[pos]=0;
    dfs(pos+1);

    col[pos]=1;
    dfs(pos+1);
}
void work1()
{
    ans=0;
    memset(col,0,sizeof(col));
    dfs(1);

    printf("%d\n",ans);
}
void work()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&Ar[i]);
    }
    if(n<=15)
    {
        work1();
        return ;
    }
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        work();
    }
    return 0;
}
