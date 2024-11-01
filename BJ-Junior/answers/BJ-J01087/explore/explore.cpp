#include<bits/stdc++.h>
using namespace std;
char ch[1010][1010];
int k,n,m,T,ans=1;
int x,y,f,vis[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T>0){
        ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>f;
        memset(ch,'/',sizeof(ch));
        memset(vis,0,sizeof(vis));
        vis[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>ch[i][j];
            }
        }
        for(int z=1;z<=k;z++){
            if(f==0){
                if(ch[x][y+1]=='.'){
                    y++;
                    if(vis[x][y]!=1){
                        vis[x][y]=1;
                    }
                }
                else if(ch[x][y+1]=='/'||ch[x][y+1]=='x'){
                    f++;
                    f%=4;
                }
            }
            else if(f==1){
                if(ch[x+1][y]=='.'){
                    x++;
                    if(vis[x][y]!=1){
                        vis[x][y]=1;
                    }
                }
                else if(ch[x+1][y]=='/'||ch[x+1][y]=='x'){
                    f++;
                    f%=4;
                }
            }
            else if(f==2){
                if(ch[x][y-1]=='.'){
                    y--;
                    if(vis[x][y]!=1){
                        vis[x][y]=1;
                    }
                }
                else if(ch[x][y-1]=='/'||ch[x][y-1]=='x'){
                    f++;
                    f%=4;
                }
            }
            else if(f==3){
                if(ch[x-1][y]=='.'){
                    x--;
                    if(vis[x][y]!=1){
                        vis[x][y]=1;
                    }
                }
                else if(ch[x-1][y]=='/'||ch[x-1][y]=='x'){
                    f++;
                    f%=4;
                }
            }
        }

        //for(int i=1;i<=n;i++){
        //    for(int j=1;j<=m;j++){
        //       cout<<vis[i][j]<<" ";
        //    }
        //    cout<<endl;
        //}
        T--;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1){
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
