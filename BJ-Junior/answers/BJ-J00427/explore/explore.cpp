#include<iostream>
using namespace std;
int T,n,m,k,x,y,d,ans=0;
int mp[1005][1005],via[1005][1005];
char c;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>x>>y>>d;
        via[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c;
                if(c=='x'){
                    mp[i][j]=1;
                }else{
                    mp[i][j]=0;
                }
            }
        }
        while(k--){
            if(d==0){
                if(y+1<=m&&mp[x][y+1]==0){
                    y++;
                    via[x][y]=1;
                }else{
                    d=1;
                }
            }else if(d==1){
                if(x+1<=n&&mp[x+1][y]==0){
                    x++;
                    via[x][y]=1;
                }else{
                    d=2;
                }
            }else if(d==2){
                if(y-1>=1&&mp[x][y-1]==0){
                    y--;
                    via[x][y]=1;
                }else{
                    d=3;
                }
            }else if(d==3){
                if(x-1>=1&&mp[x-1][y]==0){
                    x--;
                    via[x][y]=1;
                }else{
                    d=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(via[i][j]==1)ans++;
                via[i][j]=0;
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
