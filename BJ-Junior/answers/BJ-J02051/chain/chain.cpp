#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l;
int a[200005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    int r,c;
    while(t--)
    {
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&l);
            for(int j=1;j<=l;j++) scanf("%d",&a[j]);
        }
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d",&r,&c);
            printf("%d\n",(r+c)%2);
        }
    }
    return 0;
}
