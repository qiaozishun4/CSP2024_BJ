#include<bits/stdc++.h>
using namespace std;
bool vis[1010][1010];
char a[1010][1010];
int dir[8]={0,1,1,0,0,-1,-1,0};
int t,m,n,x,y,k,d,sum=0;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        while(k--){
            vis[x][y]=1;
            if(a[x+dir[d*2]][y+dir[d*2+1]]=='.'&&x+dir[d*2]<=n&&y+dir[d*2+1]<=m&&x+dir[d*2]>=1&&y+dir[d*2+1]>=1){
                x+=dir[d*2]; y+=dir[d*2+1];
            }
            else{
                int b=0;
                do{
                    if(b>=3) break;
                    d=(d+1)%4;
                    b++;
                }while(a[x+dir[d*2]][y+dir[d*2+1]]=='x'||x+dir[d*2]>n||y+dir[d*2+1]>m||x+dir[d*2]<1||y+dir[d*2+1]<1);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1){
                    sum++;
                    vis[i][j]=0;
                }
            }
        }
        cout<<sum<<endl;
        sum=0;
    }

    return 0;
}
