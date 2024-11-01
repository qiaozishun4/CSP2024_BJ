#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[1005][1005];
bool v[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int d;
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y;
        cin>>x>>y>>d;
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        int cnt=1;
        v[x][y]=1;
        for(int i=1;i<=k;i++){
            if(d==0){
                int yy=y+1;
                int xx=x;
                if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.'){
                    y=yy;
                    x=xx;
                    if(v[x][y]==0){
                        v[x][y]=1;
                        cnt++;
                    }
                }else{
                    d++;
                    d%=4;
                }
            }else if(d==1){
                int yy=y;
                int xx=x+1;
                if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.'){
                    y=yy;
                    x=xx;
                    if(v[x][y]==0){
                        v[x][y]=1;
                        cnt++;
                    }
                }else{
                    d++;
                    d%=4;
                }
            }else if(d==2){
                int yy=y-1;
                int xx=x;
                if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.'){
                    y=yy;
                    x=xx;
                    if(v[x][y]==0){
                        v[x][y]=1;
                        cnt++;
                    }
                }else{
                    d++;
                    d%=4;
                }
            }else{
                int yy=y;
                int xx=x-1;
                if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.'){
                    y=yy;
                    x=xx;
                    if(v[x][y]==0){
                        v[x][y]=1;
                        cnt++;
                    }
                }else{
                    d++;
                    d%=4;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
