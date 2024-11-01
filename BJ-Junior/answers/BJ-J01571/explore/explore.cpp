#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int cnt=0;
int vis[1005][1005];
string ma[1005];
int n,m,k,x,y,d;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cnt=0;
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        vis[x][y]=1;
        cnt++;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            ma[i]="*"+s;
        }
        for(int i=1;i<=k;i++){
            int px=x+dx[d];
            int py=y+dy[d];
            if(px>=1&&py>=1&&px<=n&&py<=m&&ma[px][py]=='.'){
                if(vis[px][py]==0){
                    cnt++;
                }
                x=px,y=py;
                vis[px][py]=1;
            }
            else{
                d++;
                d%=4;
            }
//            cout<<x<<" "<<y<<" "<<d<<endl;
        }
        cout<<cnt<<endl;
    }


    return 0;
}
