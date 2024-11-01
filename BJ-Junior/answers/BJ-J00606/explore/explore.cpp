#include <bits/stdc++.h>
using namespace std;
long long t,ans=0,n,m;
long long d[4]={0,1,0,-1};
long long e[4]={1,0,-1,0};
struct node {
    char c;
    bool b=false;
};
vector< vector<node> > v;
//vector< vector<bool> > b;
bool f;
void dfs(long long x,long long y,long long z,long long k){
    //cout<<x<<" "<<y<<" "<<z<<" "<<k<<" "<<ans<<endl;
    if(!f) return;
    if(!v[x][y].b){
        ans++;
        v[x][y].b=1;
    }
    if(k==0) {cout<<ans<<endl;f=0;return;}

    if(x+d[z]<=0||x+d[z]>n||y+e[z]>m||y+e[z]<=0||v[x+d[z]][y+e[z]].c=='x') dfs(x,y,(z+1)%4,k-1);
    dfs(x+d[z],y+e[z],z,k-1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(long long w=1;w<=t;w++){
        ans=0;
        f=1;
        long long k,x,y,z;
        cin>>n>>m>>k;
        cin>>x>>y>>z;
        v.assign(n+5,vector<node>(m+5));
        //b.assign(n+1,vector<bool>(m+1,false));
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                cin>>v[i][j].c;
            }
        }
        dfs(x,y,z,k);
    }
    return 0;
}


