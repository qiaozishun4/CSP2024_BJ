#include<iostream>
#include<cmath>
using namespace std;
int T,n,a[100005],ans;
bool clr[100005];
void cnt()
{
    int cn=0,lb=-1,lr=-1;
    for(int i=1;i<=n;i++)
    {
        if(clr[i])
        {
            if(lb!=-1&&a[lb]==a[i])
                cn+=a[i];
            lb=i;
        }
        else
        {
            if(lr!=-1&&a[lr]==a[i])
                cn+=a[i];
            lr=i;
        }
    }
    ans=max(ans,cn);
}
void dfs(int w)
{
    if(w==n+1)
    {
        cnt();
        return;
    }
    for(int i=0;i<=1;i++)
    {
        clr[w]=i;
        dfs(w+1);
    }
}
int main(void)
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        ans=0;
        dfs(1);
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
