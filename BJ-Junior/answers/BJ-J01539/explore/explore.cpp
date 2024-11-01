#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio;
    cin.tie(0);

    int T;
    cin>>T;
    while(T--){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        char ma[1005][1005];
        int visit[1005][1005];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ma[i][j]='.';
                visit[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>ma[i][j];
            }
        }
        int ans=0;
        k++;
        while(k--){
            if(visit[x][y]==0){
                ans++;
                visit[x][y]=1;
            }
            if(d==0){
                if(ma[x][y+1]=='.'&&x>=1&&x<=n&&y+1>=1&&y+1<=m){
                    y++;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==1){
                if(ma[x+1][y]=='.'&&x+1>=1&&x+1<=n&&y>=1&&y<=m){
                    x++;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==2){
                if(ma[x][y-1]=='.'&&x>=1&&x<=n&&y-1>=1&&y-1<=m){
                    y--;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==3){
                if(ma[x-1][y]=='.'&&x-1>=1&&x-1<=n&&y>=1&&y<=m){
                    x--;
                }else{
                    d=(d+1)%4;
                }
            }
//                cout<<"("<<x<<","<<y<<")"<<" d="<<d<<'\n';
        }
 //       cout<<endl;
        cout<<ans<<'\n';
    }
    return 0;
}
