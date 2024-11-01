#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int ans=1;
char a[N][N];
int n,m,k;
int mx[]={0,1,0,-1};
int my[]={1,0,-1,0};
void dfs(int x,int y,int d){
    if(k==0) return;
    k--;
    int xx=x+mx[d],yy=y+my[d];
    if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.'){
        ans++;
        dfs(xx,yy,d); 
    }
    else{
        dfs(x,y,(d+1)%4);
    }

}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin>>q;
    while(q){
        int x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cin>>a[i][j];
            }
        }
        dfs(x,y,d);
        cout<<ans<<endl;
        ans=0;
        q--;
    }

    return 0;
}
