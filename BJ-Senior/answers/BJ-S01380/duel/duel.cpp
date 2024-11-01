#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans,b[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(b[i]!=0)
            continue;
        for(int j=i;j<=n;j++)
        {
            if(a[j]>a[i]&&b[j]==0)
            {
                b[i]=1;
                b[j]=2;
                ans++;
                break;
            }
        }
    }
    ans=n-ans;
    printf("%d",ans);
    return 0;
}