//passwd:GL@17SXYZ
//PDF:Y#C*GF@24
//LUCK COMES TO ME
//EXPLORE
//CHECK:
//long long
//freopen
//return 0

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn][maxn];
bool vis[maxn][maxn];
long long ans=1;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        long long n,m,k,x0,y0,d0;
        ans=1;
        cin>>n>>m>>k;
        cin>>x0>>y0>>d0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char c;
                cin>>c;
                if(c=='x') a[i][j]=1;
                else a[i][j]=0;
            }
        }
        long long x=x0,y=y0,d=d0;
        vis[x][y]=1;
        for(int i=1;i<=k;i++){
            int tmpx=x,tmpy=y;
            if(d==0) tmpx=x,tmpy=y+1;
            else if(d==1) tmpx=x+1,tmpy=y;
            else if(d==2) tmpx=x,tmpy=y-1;
            else tmpx=x-1,tmpy=y;
            //cout<<"---"<<i<<"th,d="<<d<<",old_x="<<x<<",old_y="<<y<<",new_x="<<tmpx<<",new_y="<<tmpy<<endl;
            if((tmpx>=1 && tmpx<=n) && (tmpy>=1 && tmpy<=m)){
                if(a[tmpx][tmpy]==0){
                    x=tmpx;y=tmpy;
                    //cout<<"---can move,x="<<x<<",y="<<y<<",d="<<d<<endl;
                    if(vis[tmpx][tmpy]==0){
                        ans++;
                        //cout<<"---can visit,ans="<<ans<<endl;
                        vis[tmpx][tmpy]=1;
                    }
                    //else cout<<"---visited,x="<<x<<",y="<<y<<",ans="<<ans<<endl;
                }
                else {
                        //cout<<"---can't move because of 'x'\n";
                    d=(d+1)%4;
                }
            }
            else {
                //cout<<"---can't move,x="<<x<<",y="<<y<<",d="<<d<<",new_d="<<(d+1)%4<<endl;
                d=(d+1)%4;
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
