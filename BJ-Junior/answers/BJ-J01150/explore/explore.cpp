#include<bits/stdc++.h>
using namespace std;
int n,m,k,st[1010][1010],ans=0;
bool vis[1010][1010];
bool pd(int x,int y){
    return ((1<=x)&&(x<=n)&&(1<=y)&&(y<=m)&&!st[x][y]);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        memset(st,0,sizeof(st));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char ch;
                cin>>ch;
                if(ch=='x'){
                    st[i][j]=1;
                }
            }
        }
        vis[x][y]=true;
        for(int i=1;i<=k;i++){
            bool tf=true;
            if(d==0){
                if(pd(x,y+1)){
                    y+=1;
                    vis[x][y]=true;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==1){
                if(pd(x+1,y)){
                    x+=1;
                    vis[x][y]=true;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==2){
                if(pd(x,y-1)){
                    y-=1;
                    vis[x][y]=true;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==3){
                if(pd(x-1,y)){
                    x-=1;
                    vis[x][y]=true;
                }
                else{
                    d=(d+1)%4;
                }
            }
        }
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
