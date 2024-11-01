#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        char c[1010][1010];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        int cnt=0;
        if(c[x+dx[d]][y+dy[d]]=='x'||x+dx[d]<=0||x+dx[d]>n||y+dy[d]<=0||y+dy[d]>m) cnt++;
        while(k>0){
            int u=x+dx[d%4],v=y+dy[d%4];
            if(u<=0||u>n||v<=0||v>m||c[u][v]=='x'){
                k--,d++;
            }
            else{
                x=u,y=v;
                cnt++;
                k--;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
