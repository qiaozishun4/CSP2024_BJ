#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb emplace_back
bool vis[1005][1005];
bool mp[1005][1005];
int cnt;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d,xx,yy;
    char c;
    cin>>t;
    while(t--){
        for(int i=1;i<=1000;i++){
            for(int j=1;j<=1000;j++) vis[i][j]=0;
        }
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        vis[x][y]=1;
        cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c;
                if(c=='x') mp[i][j]=0;
                else mp[i][j]=1;
            }
        }
        while(k--){
            xx=x;
            yy=y;
            if(d==0){
                yy++;
            }else if(d==1){
                xx++;
            }else if(d==2){
                yy--;
            }else{
                xx--;
            }
            if(1<=xx && xx<=n && 1<=yy && yy<=m && mp[xx][yy]){
                x=xx;
                y=yy;
                vis[x][y]=1;
            }else{
                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
