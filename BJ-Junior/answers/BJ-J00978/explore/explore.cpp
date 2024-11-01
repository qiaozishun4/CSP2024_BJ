#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x,y,d;
char a[1004][1004];
bool v[1004][1004];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(v,0,sizeof(v));
        memset(a,'0',sizeof(a));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        int sum=1;
        v[x][y]=1;
        while(k--){
            int nx,ny;
            if(d==0){
                nx=x;
                ny=y+1;
            }else if(d==1){
                nx=x+1;
                ny=y;
            }else if(d==2){
                nx=x;
                ny=y-1;
            }else if(d==3){
                nx=x-1;
                ny=y;
            }
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.'&&a[nx][ny]!='x'){
                x=nx;
                y=ny;
                if(v[x][y]==0){
                    sum++;
                }
                v[x][y]=1;
            }else{
                d=(d+1)%4;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
