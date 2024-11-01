#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool f[1005][1005];
void f0(){
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            f[i][j]=0;
        }
    }
}
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        f0();
        int sum=1;
        for(int i=1;i<=k;i++){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.'){
                x=nx;
                y=ny;
                if(!f[nx][ny]){
                    sum++;
                    f[nx][ny]=1;
                }
            }
            else{
                d=(d+1)%4;
                cout<<"(^-^)\n";
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}