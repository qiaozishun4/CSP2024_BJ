#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s;
const int N=1e3+10;


int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};
bool f[N][N];
ll cnt;
ll n,m,k,x,y,d;
char a[N][N];
void dfs(ll x,ll y,ll pos,ll d){
    f[x][y]=1;
    if(pos==k){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(f[i][j]) cnt++;
            }
        }
    cout<<cnt<<endl;
        return;
    }
    ll tx=x+fx[d];
    ll ty=y+fy[d];
    if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]=='.'){

        dfs(tx,ty,pos+1,d);
    }else{
            if(d==3){
                dfs(x,y,pos+1,0);
            }else{
                dfs(x,y,pos+1,d+1);
            }

    }

}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>s;
    while(s--){
        cin>>n>>m>>k>>x>>y>>d;

        memset(f,0,sizeof(f));
        cnt=0;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        dfs(x,y,0,d);
    }
    return 0;
}

