#include<bits/stdc++.h>
using namespace std;
int t;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int n,m,k,xx,yy,dd;
        char a[1009][1009];
        bool b[1009][1009];
        cin>>n>>m>>k;
        cin>>xx>>yy>>dd;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                b[i][j]=false;
            }
        }
        b[xx][yy]=true;
        for(int i=1;i<=k;i++){
            int xm,ym;
            if(dd==1){
                xm=xx+1;
                ym=yy;
            }
            if(dd==2){
                xm=xx;
                ym=yy-1;
            }
            if(dd==3){
                xm=xx-1;
                ym=yy;
            }
            if(dd==0){
                xm=xx;
                ym=yy+1;
            }
            if(xm>=1&&xm<=n&&ym>=1&&ym<=m&&a[xm][ym]=='.'){
                xx=xm;
                yy=ym;
                b[xx][yy]=true;
            }else{
                dd=(dd+1)%4;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]==true){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
}