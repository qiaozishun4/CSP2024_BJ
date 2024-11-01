#include<iostream>
using namespace std;
const int N=1005;
int t;
char a[N][N];
bool vis[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int n,m,k,x0,y0,d0;
        cin>>n>>m>>k;
        cin>>x0>>y0>>d0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=false;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j]='#';
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=k;i++){
            int x=0;
            int y=0;
            if(d0==0){
                x=x0;
                y=y0+1;
                //cout<<"dong"<<i<<endl;
            }
            if(d0==1){
                x=x0+1;
                y=y0;
                //cout<<"nan"<<i<<endl;
            }
            if(d0==2){
                x=x0;
                y=y0-1;
                //cout<<"xi"<<i<<endl;
            }
            if(d0==3){
                x=x0-1;
                y=y0;
                //cout<<"bei"<<i<<endl;
            }
            if((x>=1&&x<=n)&&(y>=1&&y<=m)&&(a[x][y]=='.')){
                //cout<<x<<" "<<y<<" "<<i<<" "<<d0<<endl;
                vis[x][y]=true;
                x0=x;
                y0=y;
            }
            else{
                d0=((d0+1)%4);
                //cout<<d0<<endl;
            }
        }
        vis[1][1]=true;
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==true){
                    ++cnt;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
