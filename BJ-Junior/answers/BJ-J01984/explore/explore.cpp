#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int m,n,k,xc,yc,d,xn,yn;
        cin>>n>>m>>k;
        cin>>xc>>yc>>d;
        char mapn[n][m];
        int step[n][m];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mapn[i][j];
            }
        }
        for(int i=1;i<=k;i++){
            step[xc][yc]=12345;
            if(d==0){
                    xn=xc;
                    yn=yc+1;
            }
            if(d==1){
                    xn=xc+1;
                    yn=yc;
            }
            if(d==2){
                    xn=xc;
                    yn=yc-1;
            }
            if(d==3){
                    xn=xc-1;
                    yn=yc;
            }
            if(xn>=1&&xn<=n&&yn>=1&&yn<=m&&mapn[xn][yn]=='.'){
                xc=xn;
                yc=yn;
            }
            else{
                d=(d+1)%4;
            }
            step[xc][yc]=12345;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(step[i][j]==12345){
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
