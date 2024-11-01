#include<bits/stdc++.h>
using namespace std;
char mp[1005][1005];
int b[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(mp,' ',sizeof mp);
        memset(b,0,sizeof b);
        int n,m,k,x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        b[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        for(int o=1;o<=k;o++){
            int xx=dx[d]+x;
            int yy=dy[d]+y;
            if(xx<=n&&xx>=1&&yy<=m&&yy>=1&&mp[xx][yy]=='.'){
                b[xx][yy]=1;
                x=xx;y=yy;
            }else{
                d=(d+1)%4;
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum+=b[i][j];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);

}
