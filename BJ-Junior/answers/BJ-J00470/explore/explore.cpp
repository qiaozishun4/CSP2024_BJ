#include<bits/stdc++.h>
using namespace std;
int T,xx[4]={0,1,0,-1},yy[4]={1,0,-1,0};
char c[1005][1005];
bool b[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        int n,m,k,x,y,d,sum=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>c[i][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                b[i][j]=0;
        b[x][y]=1;
        while(k--){
            int x_=x+xx[d],y_=y+yy[d];
            if(x_>n||x_<1||y_>m||y_<1||c[x_][y_]=='x') d=(d+1)%4;
            else{
                if(!b[x_][y_]){
                    sum++;
                    b[x_][y_]=1;
                }
                x=x_,y=y_;
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}
