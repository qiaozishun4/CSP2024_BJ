#include<bits/stdc++.h>
using namespace std;
int a[1001][1001]={0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n,m,k,x0,y0,d,ans=0;
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    char p;
    cin>>T;
    while(T--){
        ans=0;
        cin>>n>>m>>k;
        cin>>x0>>y0>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>p;
                if(p=='.'){
                    a[i][j]=0;
                }else if(p=='x'){
                    a[i][j]=-1;
                }
            }
        }
        a[x0][y0]=-5;
        for(int x=0;x<k;x++){
            if(1<=x0+dx[d] && x0+dx[d]<=n && 1<=y0+dy[d] && y0+dy[d]<=m){
                if(a[x0+dx[d]][y0+dy[d]]==-1){
                    d=(d+1)%4;
                }else if(a[x0+dx[d]][y0+dy[d]]==0||a[x0+dx[d]][y0+dy[d]]==-5){
                    x0+=dx[d];
                    y0+=dy[d];
                    a[x0][y0]=-5;
                }
            }else{
                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==-5){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}