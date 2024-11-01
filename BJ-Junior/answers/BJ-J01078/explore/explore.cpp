#include <iostream>
using namespace std;
char mp[1005][1005];
int cnt;
int dfs(int x,int y,int z,int dd){
    int d=dd;
    if(z==0){
        return cnt;
    }
    cnt++;
    if(mp[x-1][y]=='.')dfs(x-1,y,z-1,d);
    else d++,d%=4;
    if(mp[x+1][y]=='.')dfs(x+1,y,z-1,d);
    else d++,d%=4;
    if(mp[x][y-1]=='.')dfs(x,y-1,z-1,d);
    else d++,d%=4;
    if(mp[x][y+1]=='.')dfs(x,y+1,z-1,d);
    else d++,d%=4;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m,k;
        int xx,yy,zz;
        cin>>n>>m>>k>>xx>>yy>>zz;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        cout<<dfs(xx,yy,k,zz);
    }
    return 0;
}
