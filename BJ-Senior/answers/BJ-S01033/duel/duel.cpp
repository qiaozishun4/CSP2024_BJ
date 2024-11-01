#include<bits/stdc++.h>
using namespace std;
int p[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,x,cnt=0,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        p[x]++;
    }
    for(int i=1;i<=1e5;i++)
    {
        //if(p[i])
        //    printf("%d %d\n",i,p[i]);
        if(p[i]>=cnt)
        {
            ans+=cnt;
            cnt=p[i];
        }
        else
            ans+=p[i];
    }
    printf("%d",n-ans);
    return 0;
}
