#include <bits/stdc++.h>

using namespace std;

int n,a[100005],cha[100005],cnt,ans;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    ans=n;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])cha[++cnt]=i-1;
    }
    cha[cnt+1]=n;
    for(int i=1;i<=cnt;i++)
    {
        int low=min(cha[i]-(n-ans),cha[i+1]-cha[i]);
        ans-=low;
    }
    cout<<ans;
    return 0;
}
