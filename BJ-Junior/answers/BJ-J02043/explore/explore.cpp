#include <bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d;
vector<vector<char> > v;
vector<vector<int> > vis;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        v.clear();
        vis.clear();
        cin>>n>>m>>k>>x>>y>>d;
        x--;
        y--;
        v.resize(n,vector<char>(m,'.'));
        vis.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        long long ans=0;
        vis[x][y]=1;
        while(k--){
            if(d==0){
                if(y+1<m&&v[x][y+1]=='.'){
                    y++;
                }else{
                    d=1;
                }
            }else if(d==1){
                if(x+1<n&&v[x+1][y]=='.'){
                    x++;
                }else{
                    d=2;
                }
            }else if(d==2){
                if(y-1>=0&&v[x][y-1]=='.'){
                    y--;
                }else{
                    d=3;
                }
            }else{
                if(x-1>=0&&v[x-1][y]=='.'){
                    x--;
                }else{
                    d=0;
                }
            }
            vis[x][y]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=vis[i][j];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
