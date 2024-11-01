#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,i,x0,y0,d0,ans=1,j;
    scanf("%d",&t);
    while(t--)
    {
        cin>>n>>m>>k>>x0>>y0>>d0;
        for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>a[i][j];
        if(a[x0][y0+1]=='.')ans++;
        if(a[x0][y0-1]=='.')ans++;
        if(a[x0-1][y0]=='.')ans++;
        if(a[x0+1][y0]=='.')ans++;
    }
    cout<<ans;
    return 0;
}