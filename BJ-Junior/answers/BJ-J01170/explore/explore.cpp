#include<bits/stdc++.h>
using namespace std;
int t,n,m,x,y,d,ans,k;
int fx[10]={0,1,0,-1};
int fy[10]={1,0,-1,0};
bool f[1000][1000];
char c[1000][1000];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        memset(f,0,sizeof(f));
        f[x][y]=true;
        for(int i=1;i<=k;i++){
            int x2=x+fx[d];
            int y2=y+fy[d];
            if(x2<1||x2>n||y2<1||y2>m||c[x2][y2]=='x'){
                d=(d+1)%4;
            }else{
                x=x2;
                y=y2;
            }
            f[x][y]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(f[i][j]) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
