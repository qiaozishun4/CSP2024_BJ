#include <bits/stdc++.h>
using namespace std;
int t;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t){
        int n,m,k,x,y,d;
        queue<int>q,p;
        string s;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        char ch[n+1][m+1];
        int vis[n+1][m+1];
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=0;j<m;j++){
                ch[i][j+1]=s[j];
                vis[i][j+1]=0;
            }
        }
        int sum=1;
        q.push(x);
        p.push(y);
        while(k){
            k--;
            int tx=q.back()+dx[d];
            int ty=p.back()+dy[d];
            if(tx>=1 && tx<=n && ty>=1 && ty<=m && ch[tx][ty]=='.'){
                q.push(tx);
                p.push(ty);
                if(vis[tx][ty]==0) sum++;
                vis[tx][ty]=1;
            }
            else{
                d=(d+1)%4;
            }
        }
        cout<<sum<<endl;
        t--;
    }
    return 0;
}
