#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define lb lower_bound
#define ub upper_bound
using namespace std;
ll read(){
    ll k=0;char c=getchar();bool flag=1;
    while(!isdigit(c)){if(c=='-')flag=0;c=getchar();}
    while(isdigit(c)){k=(k<<1)+(k<<3)+(c^48);c=getchar();}
    if(flag)return k;else return -k;
}
char readc(){
    char c=getchar();
    while(!isgraph(c))c=getchar();
    return c;
}
string reads(){
    string s="";char c=getchar();
    while(!isgraph(c))c=getchar();
    while(isgraph(c)){s+=c;c=getchar();}
    return s;
}
const int N=1010;
int n,m,k,x,y,d;
char a[N][N];
bool vis[N][N];
bool check(int x,int y){return x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]=='.';}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T=read();
    while(T--){
        memset(vis,0,sizeof vis);
        n=read(),m=read(),k=read();
        x=read(),y=read(),d=read();
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j)a[i][j]=readc();
        }
        vis[x][y]=1;
        while(k--){
            int xx=x,yy=y;
            if(d==0)++yy;
            else if(d==1)++xx;
            else if(d==2)--yy;
            else --xx;
            if(check(xx,yy))x=xx,y=yy;
            else{
                if(d<3)++d;
                else d=0;
            }
            vis[x][y]=1;
        }
        int ans=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(vis[i][j])++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
//by 2c_s in luogu
