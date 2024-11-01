#include<bits/stdc++.h>
using namespace std;
int n,m,k,h[4][2]={0,1,1,0,0,-1,-1,0};
bool M[1002][1002],vis[1002][1002];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int T;
    cin >> T;
    while(T--){
        int x,y,d,sum=1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char c;
                cin >> c;
                if(c=='x'){
                    M[i][j]=1;
                }else{
                    M[i][j]=0;
                }
                vis[i][j]=0;
            }
        }
        vis[x][y]=1;
        while(k--){
            int nx=x+h[d][0];
            int ny=y+h[d][1];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!M[nx][ny]){
                x=nx;
                y=ny;
                if(!vis[nx][ny]){
                    sum++;
                    vis[nx][ny]=1;
                }
            }else{
                d=(d+1)%4;
            }
        }
        cout << sum << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
