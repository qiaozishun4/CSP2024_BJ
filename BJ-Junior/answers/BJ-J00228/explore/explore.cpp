include<bits/stdc++.h>
using namespace std;
void f(){
    int n,m,k,x,y,d;
    char a[1005][1005]={};
    cin>>n>>m>>k>>x>>y>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int mv[5][5],ans=1;
    mv[0][0]=0;
    mv[0][1]=1;
    mv[1][0]=1;
    mv[1][1]=0;
    mv[2][0]=0;
    mv[2][1]=-1;
    mv[3][0]=-1;
    mv[3][1]=0;
    for(int i=0;i<k;i++){
        int nx=x,ny=y;
        nx+=mv[d][0];
        ny+=mv[d][1];
        if((nx>=1&&nx<=n)&&(ny>=1&&ny<=m)){
            if(a[nx][ny]=='.'){
                x=nx;
                y=ny;
                ans++;
            }
            else {
                d=(d+1)%4;
            }
        }
        else {
            d=(d+1)%4;
        }
    }
    cout<<ans;
    return;
}
int main(){

    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int t;
    cin>>t;
    for(int i=0;i<t;i++)f();

    return 0;
}
