#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,xs,ys,d;
char hh[1001][1001];
bool zouguo[1001][1001];
void qidong(){
    int cnt=1;
    zouguo[xs][ys]=1;
    while(k--){
        int xx=xs,yy=ys;
        if(d==0){
            yy++;
        }else if(d==1){
            xx++;
        }else if(d==2){
            yy--;
        }else xx--;
        if(xx<=n&&xx>=1&&yy<=m&&yy>=1&&hh[xx][yy]=='.'){
            if(zouguo[xx][yy]==0)cnt++;
            zouguo[xs][ys]=1;
            xs=xx,ys=yy;
            zouguo[xs][ys]=1;

        }else{
            d=(d+1)%4;

        }
    }
    cout<<cnt<<endl;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){

        cin>>n>>m>>k;
        cin>>xs>>ys>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cin>>hh[i][j];
        }
        qidong();
    }
    return 0;
}
