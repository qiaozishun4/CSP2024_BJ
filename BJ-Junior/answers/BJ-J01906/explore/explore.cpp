#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
char a[1005][1005];
bool b[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=0;
        memset(b,0,sizeof(b));
        //b[x][y]=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        while(k--){
            b[x][y]=1;
            int xx=x,yy=y;
            if(d==0) yy++;
            else if(d==1) xx++;
            else if(d==2) yy--;
            else xx--;
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.'){
                x=xx,y=yy;

            }else d=(d+1)%4;
        }
        b[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]) ans++;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
