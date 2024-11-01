#include<iostream>
using namespace std;
long long n,m,k,ans=0;
int x,y;
int t,d;
int dx[5]={0,1,0,-1},dy[5]={1,0,-1,0};
char a[1008][1008];
int main(){
    freopen("explore.in","r",stdin);
   freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        ans=0;
        int v[1008][1008]={0};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int q=1;q<=k;q++){
            if(v[x][y]==0){
                ans++;
              //  cout<<x<<' '<<y<<endl;
            }
            v[x][y]=1;
            int tx=x+dx[d],ty=y+dy[d];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]=='.'){
                x=tx;
                y=ty;
            }
            else{
                d=(d+1)%4;
            }
        }
        if(v[x][y]==0){
                ans++;
             //   cout<<x<<' '<<y<<endl;
            }
        cout<<ans<<endl;
    }
    return 0;
}
