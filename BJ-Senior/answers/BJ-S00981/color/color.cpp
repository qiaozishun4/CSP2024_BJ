#include <bits/stdc++.h>

using namespace std;

int t,n,a[200005],same[200005][2],col[200005],ans,cnt;
void dfs(int x)
{
    if(x==n+1)
    {
        int num=0;
        for(int i=1;i<=cnt;i++)
        {
            bool flag=0;
            for(int j=same[i][0]+1;j<same[i][1];j++)
            {
                if(col[j]==col[same[i][0]])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)num+=a[same[i][0]];
        }
        ans=max(ans,num);
        return;
    }
    col[x]=1;
    dfs(x+1);
    col[x]=2;
    dfs(x+1);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        cnt=0;
        ans=0;
        scanf("%d",&n);
        for(int j=1;j<=n;j++)scanf("%d",&a[j]);
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<j;k++)
            {
                if(a[j]==a[k])
                {
                    same[++cnt][0]=k;
                    same[cnt][1]=j;
                }
            }
        }
        if(cnt==0)
        {
            printf("0\n");
            continue;
        }
        if(cnt==1)
        {
            printf("%d\n",a[same[cnt][0]]);
            continue;
        }
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}
