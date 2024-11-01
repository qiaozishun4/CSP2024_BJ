#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,k;
int x,y,d;
bool a[N][N],b[N][N];
bool j(int x,int y){
    //cout<<x<<" "<<y<<" "<<a[x][y]<<" ";
    return (x<=n&&y<=m&&a[x][y]);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.ans","w",stdout);
    int t; cin>>t;
    char tmp;
    cin.tie(0);
    while(t--){
        long long  cnt=0;
        memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
        cin>>n>>m>>k;
        cin>>x>>y>>d;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>tmp;
                if(tmp=='.') a[i][j]=1;
                else if(tmp=='*') a[i][j]=0;
            }
        }
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<i<<j<<a[i][j]<<" ";
            }
            cout<<"\n";
        }*/
        b[x][y]=1;
        for(int i=1;i<=k;i++){
            int x1=x,y1=y;
            if(d==0) y1+=1;
            else if(d==1) x1+=1;
            else if(d==2) y1-=1;
            else if(d==3) x1-=1;
            //cout<<x1<<" "<<y1<<" "<<d<<" ";
            if(!j(x1,y1)){
                d+=1; d%=4;
            }
            else {
                x=x1; y=y1;
            }
            //cout<<x<<" "<<y<<" "<<d<<" ";
            b[x][y]=1;
            //cout<<"\n";
        }
        /* for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<i<<j<<b[i][j]<<" ";
            }
            cout<<"\n";
        }*/
         for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j])
                    cnt++;
            }
        }
        printf("%d\n",cnt);

    }
    return 0;
}
