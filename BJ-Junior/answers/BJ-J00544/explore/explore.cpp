#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    int xx[4]={0,1,0,-1},yy[4]={1,0,-1,0};
    while(t--){
        int n,m,d,x,y,k,sum=1;
        cin>>n>>m>>k>>x>>y>>d;
        bool visit[1005][1005]={0},mp[1005][1005];
        visit[x][y]=1;
        for(int i=1;i<=n;i++){
            string ss;
            cin>>ss;
            for(int j=1;j<=m;j++){
                if(ss[j-1]=='x'){
                    mp[i][j]=false;
                }
                else{
                    mp[i][j]=true;
                }
            }
        }
        while(k--){
            //cout<<x<<" "<<y<<endl;
            int dx=x+xx[d],dy=y+yy[d];
            if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&mp[dx][dy]){
                if(!visit[dx][dy]){
                    visit[dx][dy]=true;
                    sum++;
                }
                x=dx;
                y=dy;
            }
            else{
                d=(d+1)%4;
            }
        }
        cout<<sum<<endl;
    }
}
