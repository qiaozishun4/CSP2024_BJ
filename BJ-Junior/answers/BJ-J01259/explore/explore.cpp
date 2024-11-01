#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int f=0;f<t;f++)
    {
    char mp[1005][1005];
    memset(mp,'x',sizeof(mp));
    bool v[1005][1005]={0};
    int n,m,k,qx,qy,qd;
    cin>>n>>m>>k>>qx>>qy>>qd;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
        }
    }
    for(int r=0;r<k;r++)
    {
        v[qx][qy]=1;

        if((qx>=1&&qx<=n&&qy>=1&&qy<=m)&&mp[qx+dx[qd]][qy+dy[qd]]!='x')
        {
        qx+=dx[qd];
        qy+=dy[qd];
        }
        else
        {
            qd=(qd+1)%4;
        }
    }
    v[qx][qy]=1;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans+=v[i][j];
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}