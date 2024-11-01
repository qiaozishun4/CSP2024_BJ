#include <bits/stdc++.h>
using namespace std;
char a[10005][10005];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long n,m,t,k,sx,sy,sd;
    long long step=1;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m>>k>>sx>>sy>>sd;
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>a[i][j];
            }
        }
        long long tx,ty;

        while(k--){
            tx=sx+dx[sd];
            ty=sy+dx[sd];
            if(tx>m||tx<1||ty>n||ty<1||a[tx][ty]=='x'){
                tx-=dx[sd];
                ty-=dy[sd];sd =(sd+1)%4;
                cout<<sx<<","<<sy<<endl;
                continue;
            }
            sx+=dx[sd];
            sy+=dy[sd];
            step++;
        }
        cout<<step<<endl;
    }
return 0;
}
