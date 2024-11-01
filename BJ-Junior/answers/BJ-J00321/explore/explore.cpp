#include<bits/stdc++.h>
using namespace std;
int mx[]={0,1,0,-1};
int my[]={1,0,-1,0};


int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int a;
    cin>>a;
    while(a--){
        int x,y,d,cnt=0;
        int n,m,k;
        cin>>n>>m>>k>>x>>y>>d;
        char xy[1005][1005];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>xy[i][j];
            }
        }
        int vis[1005][1005]={};
        vis[x][y]=1;
        cnt++;
        for(int i=1;i<=k;i++){
        //cout<<d;
            if(xy[x+mx[d]][y+my[d]]=='x'||mx[d]+x>n||my[d]+y>m||mx[d]+x<1||my[d]+y<1){

                d++;
                d%=4;
            }else if(vis[x+mx[d]][y+my[d]]==0){
                x+=mx[d];
                y+=my[d];
                cnt++;
                vis[x][y]=1;

            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
