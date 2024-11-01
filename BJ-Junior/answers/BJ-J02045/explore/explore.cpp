#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int tx;
    cin>>tx;
    for(int sp=0;sp<tx;sp++){
        int n,m,k,x,y,d,ans=0;
        char t[1005][1005];
        bool vis[1005][1005]={false};
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            string kk;
            cin>>kk;
            for(int j=1;j<=m;j++){
                t[i][j]=kk[j-1];
            }
        }
        for(int i=0;i<k;i++){
            int gox,goy;
            vis[x][y]=true;
            if(d==0){
                gox=x;
                goy=y+1;
            }else if(d==1){
                gox=x+1;
                goy=y;
            }else if(d==2){
                gox=x;
                goy=y-1;
            }else{
                gox=x-1;
                goy=y;
            }
            if(gox<1 || goy<1 || gox>n || goy>m || t[gox][goy]!='.'){
                d++;
                if(d==4){
                    d=0;
                }
                continue;
            }
            x=gox;
            y=goy;
        }
        vis[x][y]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]){
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
