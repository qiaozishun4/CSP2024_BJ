#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
char maps[1005][1005];
int n,m;
int dx[15]={0,1,0,-1},dy[15]={1,0,-1,0};

int dfs(int a,int b,int c,int d1){
    int go[1005][1005]={};
    int x=a,y=b,d=c,k=d1,counts=1;

    //cout << x << " " << y <<" "<< d <<"\n";

    while(k--){

        int tx=x+dx[d],ty=y+dy[d];
        if(tx>=1&&tx<=n&&ty>=0&&ty<m&&maps[tx][ty]=='.'){

            x=tx;
            y=ty;
            if(go[x][y]==0){
                counts++;
                go[x][y]=999;
            }
        }
        else{
            d=(d+1)%4;
        }
        //cout << x << " " << y <<" "<< d <<"\n";
    }return counts;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int x,y,d,k;
        cin >> n >> m >>k >> x >> y >>d;

        for(int j=1;j<=n;j++){
            scanf("%s",maps[j]);

        }
        int anser=dfs(x,y,d,k);
        cout <<anser << "\n";

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
