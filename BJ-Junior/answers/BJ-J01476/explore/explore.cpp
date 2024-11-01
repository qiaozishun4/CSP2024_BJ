#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
char w[2000][2000];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>w[i][j];
            }
        }
        w[x][y]='6';
        while(k--){
            int xn,yn;
            if(d==0) xn=x,yn=y+1;
            else if(d==1) xn=x+1,yn=y;
            else if(d==2) xn=x,yn=y-1;
            else if(d==3) xn=x-1,yn=y;
            if(1<=xn&&xn<=n&&1<=yn&&yn<=m&&(w[xn][yn]=='.'||w[xn][yn]=='6')){
                w[xn][yn]='6';
                x=xn;y=yn;d=d;
            }else{
                d=(d+1)%4;
                x=x;y=y;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(w[i][j]=='6') ans++;
                w[i][j]=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}