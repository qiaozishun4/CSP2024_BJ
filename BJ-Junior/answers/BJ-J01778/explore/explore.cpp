#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T;
int sx[4]={0,1,0,-1};
int sy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int t=0;t<T;t++){
        int n,m,k,x,y,d,ans=0;
        int a[1010][1010]={};
        int b[1010][1010]={};
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char s;
                cin>>s;
                if(s=='x')a[i][j]=1;
                else a[i][j]=0;
            }
        }
        b[x][y]=1;
        for(int i=0;i<k;i++){
            int xx=x+sx[d];
            int yy=y+sy[d];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]!=1){
                x=xx;
                y=yy;
                b[x][y]=1;
            }else{
                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j])ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
