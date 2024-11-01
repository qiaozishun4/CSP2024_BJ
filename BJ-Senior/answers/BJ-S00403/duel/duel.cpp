#include<bits/stdc++.h>
using namespace std;

int a[100010];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int s=1,ans=0,x;
    for(int i=2;i<=n;i++)
    {
        if(a[i]!=a[i-1])
        {
            x=i-s;
            ans=max(0,ans-x);
            ans+=x;
            s=i;
        }
    }
    x=n-s+1;
    ans=max(0,ans-x);
    ans+=x;
    printf("%d",ans);
    return 0;
}
