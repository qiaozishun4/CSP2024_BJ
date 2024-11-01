#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
char c[1010][1010];
bool f[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int x0,y0,d0;
    cin>>k;
    while(k--){
        cin>>n>>m>>t>>x0>>y0>>d0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                f[i][j]=false;
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin>>c[i][j];
            }
        }
        int x=x0,y=y0,d=d0;
        f[x][y]=true;
        while(t--){
            int x1=x,y1=y;
            if(d==0){
                y1++;
            }
            if(d==1){
                x1++;
            }
            if(d==2){
                y1--;
            }
            if(d==3){
                x1--;
            }
            if(x1>=1 && x1<=n && y1>=1 && y1<=m && c[x1][y1]=='.'){
                f[x1][y1]=true;
                x=x1;
                y=y1;
            }else{
                d=(d+1)%4;
            }
        }
        int ans=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                ans+=f[i][j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
