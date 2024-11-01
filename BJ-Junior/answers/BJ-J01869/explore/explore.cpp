#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<list>
#define endl '\n'
using namespace std;
int T,n,m,k,cnt,ans;
char mp[1005][1005];
bool vis[1005][1005];
void solve()
{
    cnt=0,ans=0;
    int x0,y0,d0;
    memset(vis,false,sizeof(vis));
    //clear
    cin>>n>>m>>k;
    cin>>x0>>y0>>d0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
        }
    while(cnt<k)
    {
        if(!vis[x0][y0])
        {
            ans++;
            vis[x0][y0]=true;
        }
        cnt++;
        int nowx=x0,nowy=y0;
        if(d0==0) nowy++;
        if(d0==1) nowx++;
        if(d0==2) nowy--;
        if(d0==3) nowx--;
        if(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m&&mp[nowx][nowy]=='.')
        {
            x0=nowx;
            y0=nowy;
        }
        else
        {
            d0=(d0+1)%4;
        }
    }
    if(!vis[x0][y0])
    {
        ans++;
        vis[x0][y0]=true;
    }
    cout<<ans<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}

