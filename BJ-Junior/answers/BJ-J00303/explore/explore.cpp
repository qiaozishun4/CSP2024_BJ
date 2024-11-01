#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
char dt[1010][1010];
bool f[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        int x,y,d,ans=0;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>dt[i][j];
            }
        }
        while(k--){
            f[x][y]=1;
            bool kkk=0;
            if(d==0&&y+1<=m&&dt[x][y+1]=='.'){
                y++;
                kkk=1;
            }else if(d==1&&x+1<=n&&dt[x+1][y]=='.'){
                x++;
                kkk=1;
            }else if(d==2&&y-1>=1&&dt[x][y-1]=='.'){
                y--;
                kkk=1;
            }else if(d==3&&x-1>=1&&dt[x-1][y]=='.'){
                x--;
                kkk=1;
            }
            if(!kkk){
                d=(d+1)%4;
            }
            f[x][y]=1;
//            cout<<x<<" "<<y<<" "<<d<<endl;
        }
        f[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(f[i][j]){
                    ans++;
 //                   cout<<i<<" "<<j<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
