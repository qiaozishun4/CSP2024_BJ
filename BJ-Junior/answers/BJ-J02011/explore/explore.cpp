#include<bits/stdc++.h>
using namespace std;
char jjj[10000][10000];
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int res=0;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;cin >> t;
    while(t--){
        int n,m,k; scanf("%d %d %d",&n,&m,&k);
        int x,y,d; scanf("%d %d %d",&x,&y,&d);
        for(int i=0;i<=n+1;i++) jjj[i][0]=jjj[i][m+1]='x';
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) cin >> jjj[i][j];
        jjj[x][y]='v';
        while(k--)
            if(jjj[x+dx[d]]||y+dy[d]=='x'){
                d++;
                d%=4;
            }else{
                x+=dx[d];
                y+=dy[d];
                jjj[x][y]='v';
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(jjj[i][j]=='v');res++;
        cout <<res<<'\n';
    }return 0;
}
