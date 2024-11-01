#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int ok[N][N],used[N][N],d,x,y,T,n,m,k;
struct node{
    int fi,se;
};
node newpos(int x1,int y1,int d1){
    if(d1==0) return {x1,y1+1};
    if(d1==1) return {x1+1,y1};
    if(d1==2) return {x1,y1-1};
    if(d1==3) return {x1-1,y1};
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        int ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        int xf=x,yf=y,df=d,kf=k;
        memset(ok,0,sizeof(ok));
        memset(used,0,sizeof(used));
        for(int i=1;i<=n;i++){
            string l;
            cin>>l;
            for(int j=0;j<m;j++){
                if(l[j]=='.') ok[i][j+1]=1;
            }
        }
        int last_move=k;
        used[x][y]=1,ans=1;
        while(k){
            if(x==xf&&y==yf&&d==df&&k!=kf) break;
            //cout<<x<<' '<<y<<endl;
            k--;
            int x0=newpos(x,y,d).fi,y0=newpos(x,y,d).se;
            //cout<<x0<<' '<<y0<<endl;
            if(x0>=1&&x0<=n&&y0>=1&&y0<=m&&ok[x0][y0]){
                x=x0,y=y0;
                if(!used[x0][y0]){
                    ans++;
                    used[x0][y0]=1;
                }
                last_move=k;
            }
            else{
                d=(d+1)%4;
                if(last_move-k>=4) break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}