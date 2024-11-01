#include <bits/stdc++.h>
using namespace std;
const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int T;
bool f[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        string mp[1005];
        memset(f,false,sizeof(f));
        for(int i=1;i<=n;i++){
            cin>>mp[i];
            mp[i]=" "+mp[i];
        }
        f[x][y]=true;
        while(k--){
            int fx=x+dir[d][0];
            int fy=y+dir[d][1];
            if(1<=fx&&fx<=n&&1<=fy&&fy<=m&&mp[fx][fy]=='.'){
                x=fx,y=fy;
            }else{
                d=(d+1)%4;
            }
            f[x][y]=true;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(f[i][j]==true){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
