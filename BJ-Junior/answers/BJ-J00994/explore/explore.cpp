#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
long long t,x,y,d;
long long n,m,k;
bool v[N][N];
char map1[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>map1[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) v[i][j]=0;
        }
        v[x][y]=1;
        long long cnt=1;
        while(k--){
            int xx,yy;
            if(d==0){
                xx=x;
                yy=y+1;
                if(xx<1||xx>n||yy<1||yy>m){
                    d++;
                    continue;
                }
                else if(map1[xx][yy]=='x'){
                    d++;
                    continue;
                }
                x=xx;
                y=yy;
            }
            else if(d==1){
                xx=x+1;
                yy=y;
                if(xx<1||xx>n||yy<1||yy>m){
                    d++;
                    continue;
                }
                else if(map1[xx][yy]=='x'){
                    d++;
                    continue;
                }
                x=xx;
                y=yy;
            }
            else if(d==2){
                xx=x;
                yy=y-1;
                if(xx<1||xx>n||yy<1||yy>m){
                    d++;
                    continue;
                }
                else if(map1[xx][yy]=='x'){
                    d++;
                    continue;
                }
                x=xx;
                y=yy;
            }
            else{
                xx=x-1;
                yy=y;
                if(xx<1||xx>n||yy<1||yy>m){
                    d=0;
                    continue;
                }
                else if(map1[xx][yy]=='x'){
                    d=0;
                    continue;
                }
                x=xx;
                y=yy;
            }
            if(v[x][y]==0){
                v[x][y]=1;
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}