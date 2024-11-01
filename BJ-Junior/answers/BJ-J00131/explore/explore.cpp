#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mkp make_pair
#define ins insert
#define endl '\n'
using namespace std;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int N=1e3+5;
int T,n,m,k,x,y,d;
char mp[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>x>>y>>d;
        FOR(i,1,n)
            FOR(j,1,m)cin>>mp[i][j];
        set<pair<int,int>> st;
        REP(i,k,1){
            st.ins(mkp(x,y));
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.')x=nx,y=ny;
            else d=(d+1)%4;
        }
        st.ins(mkp(x,y));
        cout<<st.size()<<endl;
    }
    return 0;
}
