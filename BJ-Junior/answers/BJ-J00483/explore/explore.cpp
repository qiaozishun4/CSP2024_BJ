#include <bits/stdc++.h>
#define _for(i,x,y) for(int i=x; i<=y; i++)
using namespace std;
typedef long long ll;
const int MAXN=1e3+10;
char a[MAXN][MAXN];
int n,m,k;
int vis[MAXN][MAXN][6];
int v[MAXN][MAXN];
int ans[MAXN*MAXN],cnt=0;
struct Node{
    int x,y,d;
};
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void bfs(int sx,int sy,int sd){
    ans[0]=1;
    v[sx][sy]=1;
    queue<Node> q;
    bool f=0;
    int la=0;
    q.push({sx,sy,sd});
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int d=q.front().d;
        if(vis[x][y][d]) break;
        vis[x][y][d]=1;
//        cout<<x<<" "<<y<<" "<<d<<" "<<cnt<<endl;
        q.pop();
        int lx=x,ly=y,l=0;
        while(1){
            l++;
            int xx=x+dx[d],yy=y+dy[d];
//            cout<<xx<<" "<<yy<<" "<<a[xx][yy]<<" "<<n<<" "<<m<<" "<<cnt<<" "<<ans[cnt]<<" "<<la<<endl;
            cnt++;
            if(xx<1||xx>n||yy<1||yy>m||a[xx][yy]=='x') break;
//            cout<<1<<endl;
            if(vis[xx][yy][d]){
                f=1;
                break;
            }
            if(!v[xx][yy]) ans[cnt]=ans[la]+1;
            else ans[cnt]=ans[la];
            v[xx][yy]=1;
            vis[xx][yy][d]=1;
            lx=xx;
            ly=yy;
            x=xx;
            y=yy;
            la=cnt;
//            cout<<x<<" "<<y<<endl;
        }
        if(l>1) cnt--;
        if(f) break;
        d=(d+1)%4;
        q.push({lx,ly,d});
    }
}
void init(){
    cnt=0;
    memset(vis,0,sizeof(vis));
    memset(v,0,sizeof(v));
    memset(ans,0,sizeof(ans));
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int T;
    cin>>T;
    while(T--){
        init();
        int x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        _for(i,1,n){
            _for(j,1,m)cin>>a[i][j];
        }
        bfs(x,y,d);
//        cout<<cnt<<endl;
        if(k>=cnt) cout<<ans[cnt]<<endl;
        else cout<<ans[k]<<endl;
    }

    return 0;
}
