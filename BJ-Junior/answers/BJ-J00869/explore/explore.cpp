#include<bits/stdc++.h>
using namespace std;
char a[10005][10005];
int ans=1;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++)
        {
            for(int o=1;o<=m;o++)
            {
                cin>>a[j][o];
            }
        }
        int now=x;
        int now1=y;
        for(int j=1;j<=k;j++)
        {
            if(d==1&&a[now+1][now1]=='.'&&now+1<=m)
            {
                ans++;
                now++;
            }
            else if(d==0&&a[now][now1+1]=='.'&&now1+1<=n)
            {
                ans++;
                now1++;
            }
            else if(d==2&&a[now][now1-1]=='.'&&now1-1>=1)
            {
                ans++;
                now1-=1;
            }
            else if(d==3&&a[now-1][now1]=='.'&&now-1>=1)
            {
                ans++;
                now-=1;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
        ans=1;
    }
    return 0;
}
