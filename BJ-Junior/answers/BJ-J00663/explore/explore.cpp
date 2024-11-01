#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int x,y,d;
char b[1010][1010];
int a[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        memset(b,0,sizeof(b));
        memset(a,0,sizeof(a));
        int zouguo=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int q=1;q<=m;q++){
                cin>>b[j][q];
            }
        }
        a[x][y]=1;
        int xn=x,yn=y;
        for(int u=1;u<=k;u++){
            if(d==0)yn=y+1,xn=x;
            else if(d==1)xn=x+1,yn=y;
            else if(d==2)yn=y-1,xn=x;
            else if(d==3)xn=x-1,yn=y;
            if(xn>=1&&xn<=n&&yn>=1&&yn<=m&&b[xn][yn]=='.'){
                x=xn,y=yn;
                if(a[xn][yn]==0)zouguo++,a[xn][yn]=1;
            }
            if(!(xn>=1&&xn<=n&&yn>=1&&yn<=m&&b[xn][yn]=='.')){
                d=(d+1)%4;
            }
        }
        cout<<zouguo<<endl;

    }
return 0;

}
