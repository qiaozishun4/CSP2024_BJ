#include<bits/stdc++.h>
using namespace std;
int n,m,d,x,y,k,t,mp[1111][1111],cnt,
dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char c;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        memset(mp,-1,sizeof mp);
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            getchar();
            for(int j=1;j<=m;j++){
                c=getchar();
                mp[i][j]=(c-'x'?0:-1);
            }
        }
        while(k--){
            mp[x][y]=114514;
            if(~mp[x+dx[d]][y+dy[d]])x+=dx[d],y+=dy[d];
            else d=(d+1)%4;
        }
        mp[x][y]=114514;
        cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j]>0)cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}