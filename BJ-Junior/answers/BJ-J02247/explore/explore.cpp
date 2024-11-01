#include<bits/stdc++.h>
using namespace std;
#define int long long
int q,n,m,k,x,y,d;
char a,s[1005][1005];
bool vis[1005][1005];
bool check(int xx,int yy,int dd){
    int nx=xx,ny=yy;
    if(dd==0){
        ny+=1;
        if(ny>=1 && ny<=m && s[nx][ny]=='.'){
            return true;
        }
    }else if(dd==1){
        nx+=1;
        if(nx>=1 && nx<=n && s[nx][ny]=='.'){
            return true;
        }
    }else if(dd==2){
        ny-=1;
        if(ny>=1 && ny<=m && s[nx][ny]=='.'){
            return true;
        }
    }else{
        nx-=1;
        if(nx>=1 && nx<=n && s[nx][ny]=='.'){
            return true;
        }
    }
    return false;
}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>q;
    int sum=0;
    int i,j;
    while(q--){
        sum=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                cin>>a;
                s[i][j]=a;
                vis[i][j]=false;
            }
        }
        vis[x][y]=true;
        sum++;
        while(k--){
            if(check(x,y,d)){
                if(d==0){
                    y++;
                }else if(d==1){
                    x++;
                }else if(d==2){
                    y--;
                }else{
                    x--;
                }
                if(vis[x][y]==false){
                    sum++;
                }
                vis[x][y]=true;
            }else{
                d=(d+1)%4;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
