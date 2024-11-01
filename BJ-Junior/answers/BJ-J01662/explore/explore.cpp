#include<iostream>
using namespace std;
int T,f1[4]={0,1,0,-1},f2[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
     cin>>T;
     for(int i=1;i<=T;i++){
        int n,m,k,x,y,d,vis[100][100]={};
        char a[101][101]={};
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }

        }
        int x1=x+f1[d];
        int y1=y+f1[d];
        if(x1<=n&&y1<=m&&a[x1][y1]=='.'){
            cout<<2;
        }else{
            cout<<1;
        }
     }




}
