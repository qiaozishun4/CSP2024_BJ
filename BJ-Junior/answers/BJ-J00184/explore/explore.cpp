#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,xi,yi,d,ans;
char w;
int mp[1005][1005];
int up[1005][1005];
int gp[1005][1005][10];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int l=1;l<=t;l++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int p=0;p<=3;p++){
                    gp[i][j][p]=0;
                }
                cin>>w;
                if(w=='.'){
                    mp[i][j]=1;
                }
                if(w=='x'){
                    mp[i][j]=0;
                }
                up[i][j]=0;
            }
        }
        for(int j=1;j<=k;j++){
            if(gp[x][y][d]==1){
                break;
            }
            up[x][y]=1;
            gp[x][y][d]=1;
            if(d==0&&y+1<=m&&mp[x][y+1]!=0){
                y++;
            }
            else if(d==1&&x+1<=n&&mp[x+1][y]!=0){
                x++;
            }
            else if(d==2&&y-1>=1&&mp[x][y-1]!=0){
                y--;
            }
            else if(d==3&&x-1>=1&&mp[x-1][y]!=0){
                x--;
            }
            else{
                d=(d+1)%4;
                continue;
            }
            if(up[x][y]==0){
                ans++;
                up[x][y]=1;
            }

        }
        cout<<ans+1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
