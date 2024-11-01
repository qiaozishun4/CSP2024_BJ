#include <bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
    int x=0,f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c-'0');
    return x*f;
}
void read(int &x){
    int f=1; x=0;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c-'0');
    x*=f;
}
void write(int x){
    if(x<10){
        putchar(x+'0');
        return ;
    }
    write(x/10);
    putchar(x%10+'0');
}
const int N=1e3+5;
bool a[N][N],go[N][N];
int T,n,m,k,x,y,d;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool check(int xx,int yy){
    if(xx<1||xx>n||yy<1||yy>m) return 0;
    return a[xx][yy];
}
void nxt(){
    int nx=x+dx[d],ny=y+dy[d];
    if(check(nx,ny)) x=nx,y=ny;
    else d=(d+1)%4;
    go[x][y]=1;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char c;
                cin>>c;
                a[i][j]=(c=='.');
                go[i][j]=0;
            }
        }
        go[x][y]=1;
        for(int i=1;i<=k;i++) nxt();
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(go[i][j]) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
