#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int m,n,k,ans=1;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        char M[1005][1005];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>M[i][j];
            }
        }
        M[x][y]='b';
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        while(k--){
            int n_x,n_y;
            n_x=x+dir[d][0];
            n_y=y+dir[d][1];
            if(n_x>=1&&n_x<=n&&n_y>=1&&n_y<=m&&M[n_x][n_y]!='x'){
                x=n_x;
                y=n_y;
                if(M[x][y]=='.') ans++;
                M[x][y]='b';
            }else{
                d=(d+1)%4;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
