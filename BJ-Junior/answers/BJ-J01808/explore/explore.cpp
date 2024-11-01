#include<bits/stdc++.h>
using namespace std;
int T;
char MAP[1005][1005];
int n,m,k;
int x0,yyy,d0;
int dqczb;
int zlsum;
int dx[6] = {0, 1, 0, -1};
int dy[6] = {1, 0, -1, 0};
bool vis[1005][1005];
int dfs(int x,int y,int fx){
    if(dqczb==k){
        cout<<zlsum<<endl;
        return -1;
    }
    int xzfx=fx;
    int xx=x+dx[fx];
    int yy=y+dy[fx];

    if(xx<1||xx>n||yy<1||yy>m||vis[xx][yy]||MAP[xx][yy]=='x'){
        vis[x][y]=1;
        int flag=1;
        for(;;flag++){
            if(flag>=4||dqczb==k){
                cout<<zlsum<<endl;
                return -1;
            }
            xx=x,yy=y;
            if(xx==x0&&yy==yyy&&flag==1){
                zlsum++;
                vis[x][y]=1;
                //cout<<xx<<" "<<yy<<" "<<xzfx<<endl;
            }
            xzfx=(xzfx+1)%4;
            xx+=dx[xzfx];
            yy+=dy[xzfx];
            dqczb++;
            //cout<<xx<<" "<<yy<<" "<<xzfx<<" "<< dqczb<<endl;
            if(dqczb==k){
                cout<<zlsum<<endl;
                return -1;
            }
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]&&MAP[xx][yy]=='.'){
                zlsum++;
                dqczb++;
                vis[xx][yy]=1;
                //cout<<fx<<" "<<xx<<" "<<yy<<" "<< dqczb<<endl;
                if(dqczb==k){
                    cout<<zlsum<<endl;
                    return -1;
                }
                if(dfs(xx,yy,xzfx)==-1){
                    return -1;
                }
            }
        }

    }else{
        zlsum++;
        dqczb++;
        vis[xx][yy]=1;
        //cout<<fx<<" "<<xx<<" "<<yy<<" "<< dqczb<<endl;
        if(dqczb==k){
            cout<<zlsum<<endl;
            return -1;
        }
        if(dfs(xx,yy,xzfx)==-1){
            return -1;
        }
    }
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);


    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x0,&yyy,&d0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>MAP[i][j];
            }
        }
        int p=dfs(x0,yyy,d0);
        for(int i=0;i<1005;i++){
            for(int j=0;j<1005;j++){
                vis[i][j]=0;
                MAP[i][j]=' ';
            }
        }
        zlsum=0;
        dqczb=0;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

