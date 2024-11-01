#include<bits/stdc++.h>
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d;
    cin>> t;
    while(t--){
        cin>> n >> m >> k >> x >> y >> d;
        char a[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>> a[i][j];
            }
        }
        int nx=x+dx[d],ny=y+dy[d];
        if(nx<=0 || nx>m || ny<=0 || ny>n || a[nx][ny]=='x'){
            cout<< 1 << endl;
        }
        else cout<< 2 << endl;
    }
    return 0;
}
