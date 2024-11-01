#include<iostream>
using namespace std;
const int N=1e3+10;
int t;
int d[4][2]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};
string a[N];
bool h[N][N];
int ans=1;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int n,m,k,x,y,dn;
        cin>>n>>m>>k;
        cin>>x>>y>>dn;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                h[i][j]=false;
        }
        h[x][y]=true;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        while(k--){
            int newx=x+d[dn][0];
            int newy=y+d[dn][1];
            if(newx>=1&&newy>=1&&newx<=n&&newy<=m&&a[newx][newy-1]=='.'){
                x=newx;
                y=newy;
                if(!h[x][y]){
                    ans++;
                    h[x][y]=true;
                }
            }
            else{
                dn=(dn+1)%4;
            }
        }
        cout<<ans<<endl;
        ans=1;
    }
    return 0;
}
