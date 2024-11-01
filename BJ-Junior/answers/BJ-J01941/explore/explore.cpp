#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d;
bool check(int x, int y){
    return x>=1&&y>=1&&x<=n&&y<=m;
}
char mp[1005][1005];
bool v[1005][1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        v[x][y]=1;
        int c=0,xx,yy;
        for(int i=1;i<=k;i++){
            xx=x,yy=y;
            if(d==0){
                if(mp[x][y+1]=='.'&&check(x,y+1)){
                    y++;
                    v[x][y]=1;
                }else{
                    d++;
                }
            }else if(d==1){
                if(mp[x+1][y]=='.'&&check(x+1,y)){
                    x++;
                    v[x][y]=1;
                }else{
                    d++;
                }
            }else if(d==2){
                if(mp[x][y-1]=='.'&&check(x,y-1)){
                    y--;
                    v[x][y]=1;
                }else{
                    d++;
                }
            }else if(d==3){
                if(mp[x-1][y]=='.'&&check(x-1,y)){
                    x--;
                    v[x][y]=1;
                }else{
                    d=0;
                }
            }
            if(xx!=x||yy!=y)c++;
        }
        if(xx!=x||yy!=y)c++;
        if(c==0)c++;
        cout<<c<<endl;
    }
    return 0;
}
