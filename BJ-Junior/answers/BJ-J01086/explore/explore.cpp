#include<bits/stdc++.h>
using namespace std;
int T;
char mp[1005][1005];
bool mp1[1005][1005];
int n,m,k;
bool in(int x,int y){
    return x>0 && x<=n && y>0 && y<=m && mp[x][y]=='.';
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                mp1[i][j]=0;
                cin>>mp[i][j];
            }
        }
        while(k--){
            mp1[x][y]=1;
            if(d==0){
                if(in(x,y+1))++y;
                else ++d;
            }else if(d==1){
                if(in(x+1,y))++x;
                else ++d;
            }else if(d==2){
                if(in(x,y-1))--y;
                else ++d;
            }else{
                if(in(x-1,y))--x;
                else d=0;
            }
        }
        mp1[x][y]=1;
        int ans=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(mp1[i][j])++ans;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
