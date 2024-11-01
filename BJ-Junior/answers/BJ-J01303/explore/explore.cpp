#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        x--;
        y--;
        string s[n];
        vector<vector<int>>vis(n+11,vector<int>(m+11,0));
        for(int i=0;i<n;i++){
            cin>>s[i];
            for(int j=0;j<m;j++){
                if(s[i][j]=='x'){
                    vis[i][j]=-1;
                }
            }
        }
        vis[x][y]=1;
        while(k--){
            int xx=x+dx[d],xy=y+dy[d];
            if(xx<0){
                d=(d+1)%4;
                //cout<<"xxiao"<<endl;
                continue;
            }
            if(xx>=n){
                d=(d+1)%4;
                //cout<<"xchao"<<endl;
                continue;
            }
            if(xy<0){
                d=(d+1)%4;
                //cout<<"yxiao"<<endl;
                continue;
            }
            if(xy>=m){
                d=(d+1)%4;
                //cout<<"ychao"<<endl;
                continue;
            }
            if(vis[xx][xy]==-1){
                d=(d+1)%4;
                //cout<<"zhangai"<<endl;
                continue;
            }
            x=xx;
            y=xy;
            vis[x][y]=1;
            //cout<<"ok"<<endl;
        }
        int ret=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1)ret++;
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}