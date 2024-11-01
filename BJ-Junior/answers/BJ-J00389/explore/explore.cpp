#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char p[1005][1005];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int check(int x,int y){
    if(x<0) return 0;
    if(x>=n) return 0;
    if(y<0) return 0;
    if(y>=m) return 0;
    if(p[x][y]=='x') return 0;
    return 1;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int x,y,i;
    int t;
    cin>>t;
    int ans;
    while(t--){
        for(int i=0;i<1005;i++){
            for(int j=0;j<1005;j++){
                p[i][j]=' ';
            }
        }
        ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>i;
        x--;
        y--;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>p[i][j];
        p[x][y]='#';
        while(k--){
            int tx=x+dx[i];
            int ty=y+dy[i];
            if(check(tx,ty)){
                x=tx;
                y=ty;
                if(p[x][y]!='#') ans++;
                p[x][y]='#';
            }
            else i=(i+1)%4;
        }
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
