#include<bits/stdc++.h>
using namespace std;
int n;
int col[20];
int val[20];
int ans;
void dfs(int now)
{
    if(now==n+1)
    {
        int nowans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=1;j--)
            {
                if(col[i]==col[j])
                {
                    if(val[i]==val[j])
                    {
                        nowans+=val[i];
                    }
                    break;
                }
            }
        }
        if(nowans>ans)ans=nowans;
        return;
    }
    col[now]=1;
    dfs(now+1);
    col[now]=0;
    dfs(now+1);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&val[i]);
        }
        dfs(1);
        printf("%d\n",ans);
    }
}
