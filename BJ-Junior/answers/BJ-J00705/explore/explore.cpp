#include<iostream>
using namespace std;
int t;
int n,m,k;
int x,y,d;
int step;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    int xx,yy,dd;
    dd=d;
    char in[n][m];
    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
            cin>>in[i][j];
        }
    }
    for(int i=1;i<=k;i++){
        if(d=0){xx=yy=y+1;}
        if(d=1){xx=x+1,yy=y;}
        if(d=2){xx=x,yy=y+1;}
        if(d=3){xx=x+1,yy=y;}
        if(1<=xx<=n&&1<=yy<=m&&in[xx][yy]=='.'){
            xx-1;
            step++;
        }else{
            d=(dd+1)%4;
        }
        x=xx;
        y=yy;


    }cout<<step+1;
    }
    return 0;
}
