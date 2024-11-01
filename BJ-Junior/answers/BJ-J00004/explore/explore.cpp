#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d,b[1001][1001];
char a[1001][1001];
long long fxx[4]={0,1,0,-1};
long long fyy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                b[i][j]=0;
            }
        }

        b[x][y]=1;
        while(k--){
        x+=fxx[d];
        y+=fyy[d];
        if((a[x][y]=='x')||(x<1)||(x>n)||(y<1)||(y>m)){
            x-=fxx[d];
            y-=fyy[d];
            d=(d+1)%4;
        }
        b[x][y]=1;}
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans+=b[i][j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
