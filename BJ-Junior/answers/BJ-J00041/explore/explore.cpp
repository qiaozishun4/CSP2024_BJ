#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,xx,yy;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        char mapp[1010][1010]={};
        int cnt=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                cin>>mapp[j][l];
            }
        }
        mapp[x][y]='#';
        for(int j=1;j<=k;j++){
            if(d==0){
                xx=x;
                yy=y+1;
            }
            else if(d==1){
                xx=x+1;
                yy=y;
            }
            else if(d==2){
                xx=x;
                yy=y-1;
            }
            else if(d==3){
                xx=x-1;
                yy=y;
            }
            if(xx>0 && xx<=n && yy>0 && yy<=m){
                if(mapp[xx][yy]!='x'){
                    mapp[xx][yy]='#';
                    x=xx;
                    y=yy;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else{
                d=(d+1)%4;
            }
        }
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                if(mapp[j][l]=='#'){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
