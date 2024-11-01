#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int groups,n,m,k,xa,ya,d;
long long ans;
string str[maxn];
bool vis[maxn][maxn];
bool inbound(int nx,int ny){
    return (nx>=0&&nx<n)&&(ny>=0&&ny<m);}
void init(){
    cin>>n>>m>>k>>xa>>ya>>d;ans=0;
    for (int i=0;i<n;i++)
        cin>>str[i];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            vis[i][j]=false;}
void dfs(int xa,int ya,int d,int k){
    //cout << xa << " " << ya << " " << d << '\n';
    if (k==-1) return;
    vis[xa][ya]=true;
    int nx=xa+dx[d];
    int ny=ya+dy[d];
    if (inbound(nx,ny)&&str[nx][ny]=='.')
        dfs(nx,ny,d,k-1);
    else dfs(xa,ya,(d+1)%4,k-1);}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>groups;
    while (groups--){
        init();
        dfs(xa-1,ya-1,d,k);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (vis[i][j]) ans++;
        cout << ans << '\n';}
    return 0;}
