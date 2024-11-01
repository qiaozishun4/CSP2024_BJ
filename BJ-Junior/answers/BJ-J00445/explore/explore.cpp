#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n,m,k;
        cin >> n >> m >> k;
        int x0,y0,d0;
        cin >> x0 >> y0 >> d0;
        vector<vector<char>> maps(n+1,vector<char>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> maps[i][j];
            }
        }
        vector<vector<bool>> vis(n+1,vector<bool>(m+1,false));
        int ans=1;
        vis[x0][y0]=true;
        for(int i=1;i<=k;i++){
            int newX,newY;
            if(d0==0){
                newX=x0;
                newY=y0+1;
            }
            else if(d0==1){
                newX=x0+1;
                newY=y0;
            }
            else if(d0==2){
                newX=x0;
                newY=y0-1;
            }
            else if(d0==3){
                newX=x0-1;
                newY=y0;
            }
            //cout << newX << " " << newY << " " << ans << endl;
            if(newX>=1&&newX<=n&&newY>=1&&newY<=m&&maps[newX][newY]=='.'){
                if(!vis[newX][newY]){
                    ans++;
                    vis[newX][newY]=true;
                }
                x0=newX;
                y0=newY;
            }
            else{
                d0=(d0+1)%4;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
