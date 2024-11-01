#include<bits/stdc++.h>
using namespace std;
int n,m,dx[5]={0,1,0,-1},dy[5]={1,0,-1,0},t,k,x,y,d;
char a[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int b[1001][1001]={0},c=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
        b[x][y]=1;
        for(int i=1;i<=k;i++){
            if(x+dx[d]<=n&&x+dx[d]>0&&y+dy[d]<=m&&y+dy[d]>0&&a[x+dx[d]][y+dy[d]]=='.'){
                x+=dx[d];
                y+=dy[d];
                if(b[x][y]==0){
                    b[x][y]=1;
                    c++;
                }
            }
            else d=(d+1)%4;
        }
        cout<<c<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
