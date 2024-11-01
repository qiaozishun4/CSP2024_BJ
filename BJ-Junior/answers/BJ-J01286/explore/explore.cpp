#include<iostream>
#include<cstdio>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
bool inmap(int x,int y,int n,int m){
    if(1<=x&&x<=n&&1<=y&&y<=m) return true;
    else return false;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                vis[i][j]=false;
        int cnt=1;
        for(int i=1;i<=k;i++){
            if(d==0){
                if(a[x][y+1]=='.'&&1<=x&&x<=n&&1<=y+1&&y+1<=m){
                    if(!vis[x][y+1]) cnt++;
                    vis[x][y+1]=true;
                    y++;
                    //cout<<x<<" "<<y<<" "<<"true"<<" "<<"cnt="<<cnt<<endl;
                }
                else d=(d+1)%4;
                continue;
            }
            if(d==1){
                if(a[x+1][y]=='.'&&1<=x+1&&x+1 <=n&&1<=y&&y<=m){
                    if(!vis[x+1][y]) cnt++;
                    vis[x+1][y]=true;
                    x++;
                  //  cout<<x<<" "<<y<<" "<<"true"<<" "<<"cnt="<<cnt<<endl;
                }
                else d=(d+1)%4;
                continue;
            }
            if(d==2){
                if(a[x][y-1]=='.'&&1<=x&&x<=n&&1<=y-1&&y-1<=m){
                    if(!vis[x][y-1]) cnt++;
                    vis[x][y-1]=true;
                    y--;
                    //cout<<x<<" "<<y<<" "<<"true"<<" "<<"cnt="<<cnt<<endl;
                }
                else d=(d+1)%4;
                continue;
            }
            if(d==3){
                if(a[x-1][y]=='.'&&1<=x-1&&x-1<=n&&1<=y&&y<=m){
                    if(!vis[x-1][y]) cnt++;
                    vis[x-1][y]=true;
                    x--;
                    //cout<<x<<" "<<y<<" "<<"true"<<" "<<"cnt="<<cnt<<endl;
                }
                else d=(d+1)%4;
                continue;
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}
