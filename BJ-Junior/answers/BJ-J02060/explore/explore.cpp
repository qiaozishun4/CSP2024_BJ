#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n,m,k;
const int N=1e3+5;
bool vis[N][N];//xia biao since thero
int nx,ny,nd;
string s[N];
void init()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)vis[i][j]=0;
    }
}
int cal()
{
    int ret=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)ret+=vis[i][j];
    }
    return ret;
}
void Move()
{
    if(nd==0)ny++;
    if(nd==1)nx++;
    if(nd==2)ny--;
    if(nd==3)nx--;
}
void down()
{
    while(k--)
    {
        //cout<<nx<<" "<<ny<<" "<<nd<<"\n";
        vis[nx][ny]=1;
        int bfx=nx,bfy=ny;//cpy
        Move();
        if(nx<0 || nx>=n || ny<0 || ny>=m || s[nx][ny]=='x')//zhuan wan
        {
            nx=bfx;
            ny=bfy;
            nd=(nd+1)%4;
        }
        vis[nx][ny]=1;
    }

}
signed main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>nx>>ny>>nd;
        nx--,ny--;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        init();
        down();
        cout<<cal()<<"\n";
    }
}


