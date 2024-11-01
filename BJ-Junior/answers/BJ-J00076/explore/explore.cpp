#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int t,n,m,k,x,y,d,b[1005][1005];
char c[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        memset(b,0,sizeof(b));
        b[x][y]=1;
        while(k--){
            int xn,yn;
            if(d==0)xn=x,yn=y+1;
            if(d==1)xn=x+1,yn=y;
            if(d==2)xn=x,yn=y-1;
            if(d==3)xn=x-1,yn=y;
            if(xn>=1&&xn<=n&&yn>=1&&yn<=m&&c[xn][yn]=='.'){
                b[xn][yn]=1;
                x=xn;
                y=yn;
            }
            else{
                d=(d+1)%4;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]==1)cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}