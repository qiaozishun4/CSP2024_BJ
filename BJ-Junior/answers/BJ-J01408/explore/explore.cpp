#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n,m,k,x,y,d,ans=0;
    int xd[4]={0,1,0,-1};
    int yd[4]={1,0,-1,0};
    cin>>T;
    for(int i=1;i<=T;i++){
        ans=0;
        cin>>n>>m>>k;
        char map[n][m];
        int biaoj[n][m];
        for(int c=0;c<n;c++){
            for(int b=0;b<m;b++){
                biaoj[c][b]=0;
            }
        }
        cin>>x>>y>>d;
        x--;
        y--;
        for(int p=0;p<n;p++){
            for(int o=0;o<m;o++){
                cin>>map[p][o];
            }
        }
        for(int l=1;l<=k;l++){
            if(biaoj[x][y]==0){
                biaoj[x][y]=1;
                ans++;
            }
            if(0<=x+xd[d] and x+xd[d]<=n-1 and 0<=y+yd[d] and y+yd[d]<=m-1 and map[x+xd[d]][y+yd[d]]=='.'){
                x+=xd[d];
                y+=yd[d];
            }
            else{
                d=(d+1)%4;
            }
        }
        if(biaoj[x][y]==0){
            biaoj[x][y]=1;
            ans++;
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}