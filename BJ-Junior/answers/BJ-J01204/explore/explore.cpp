#include<iostream>
using namespace std;
int ans=0,n,m,cz;
char map[1005][1005];
bool txt[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int qwq;
    cin>>qwq;
    for(int awa=1;awa<=qwq;awa++){
        ans=0;
        cin>>n>>m>>cz;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>map[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                txt[i][j]=false;
            }
        }
        ans++;
        txt[x][y]=true;
        for(int i=1;i<=cz;i++){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>0 && nx<n+1 && ny>0 && ny<m+1 && map[nx][ny]!='x'){
                x=nx;
                y=ny;
                if(!txt[x][y]){
                    ans++;
                    txt[x][y]=true;

                }
            }
            else{
                d=(d+1)%4;
            }
        }
        /*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(txt[i][j])cout<<1;
                else cout<<0;
            }
            cout<<endl;
        }
        */
        cout<<ans<<endl;
    }
    return 0;
}
