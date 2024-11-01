#include<bits/stdc++.h>
using namespace std;
int times,xmax,ymax,k,x,y,d,xd,yd,ans=0;
char m[1010][1010];
bool vis[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>times;
    for(int t=0;t<times;t++){
        cin>>xmax>>ymax>>k;
        cin>>x>>y>>d;
        x--;
        y--;
        for(int i=0;i<xmax;i++){
            for(int j=0;j<ymax;j++){
                cin>>m[i][j];
            }
        }
        for(int i=0;i<k;i++){
            xd=x;
            yd=y;
            vis[xd][yd]=true;
            if(d==0){
                yd++;
            }
            else if(d==1){
                xd++;
            }
            else if(d==2){
                yd--;
            }
            else if(d==3){
                xd--;
            }
            if(xd<0||yd<0||xd>=xmax||yd>=ymax||m[xd][yd]=='x'){
                d++;
                d%=4;
                continue;
            }
            else{
                vis[xd][yd]=true;
                x=xd;
                y=yd;
            }
        }
        for(int i=0;i<xmax;i++){
            for(int j=0;j<ymax;j++){
                if(vis[i][j]==true){
                    ans++;
                }
                vis[i][j]=false;
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
