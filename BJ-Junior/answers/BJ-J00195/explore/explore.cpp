#include<bits/stdc++.h>
using namespace std;
string mapi[1005];
bool mpt[1005][1005];
int T,n,m,k,xf,yf,df;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&xf,&yf,&df);
        for(int i=0;i<n;i++){
                cin>>mapi[i];
            for(int j=0;j<=m;j++){
                mpt[i][j]=false;
            }
        }
        int sumi=0;
        xf--;yf--;
        for(int i=0;i<k;i++){
            int nx=xf,ny=yf;
            if(mpt[xf][yf]==false) sumi++;
            mpt[xf][yf]=true;
            if(df==0) ny=yf+1;
            else if(df==1) nx=xf+1;
            else if(df==2) ny=yf-1;
            else if(df==3) nx=xf-1;
            if(mapi[nx][ny]=='.'&&0<=nx&&nx<n&&0<=ny&&ny<m){
                xf=nx;yf=ny;
            }else df=(df+1)%4;
        }
        if(mpt[xf][yf]==false) sumi++;
        printf("%d\n",sumi);
    }
    return 0;
}
