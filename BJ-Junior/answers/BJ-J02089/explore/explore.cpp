#include <bits/stdc++.h>
using namespace std ;
char g[1010][1010] ;
bool vis[1010][1010] ;
int ans=0,cnt=0,n,m,k,t ;
void mg(int x,int y,int z){
    if (cnt>=k){
        return ;
    }
    cnt++ ;
    //cout << ans << endl ;
    if (z==0){
        if (y==m || g[x][y+1]=='*'){
            mg(x,y,z+1) ;
            return ;
        }
        //cout << x << " " <<y+1 << " " << z << " " << cnt << endl ;
        if (vis[x][y+1]){
            ans++;
        }

        vis[x][y+1]=false ;
        mg(x,y+1,z) ;
        return ;
    }
    else if (z==1){
        if (x==n || g[x+1][y]=='*'){
            mg(x,y,z+1) ;
            return ;
        }
        //cout << x+1 << " " <<y << " " << z << " " << cnt << endl ;
        if (vis[x+1][y]){
            ans++;
        }
        vis[x+1][y]=false ;
        mg(x+1,y,z) ;
        return ;
    }
    else if (z==2){
        if (y==1 || g[x][y-1]=='*'){
            mg(x,y,z+1) ;
            return ;
        }
        //cout << x << " " <<y-1 << " " << z << " " << cnt << endl ;
        if (vis[x][y-1]){
            ans++;
        }
        vis[x][y-1]=false ;
        mg(x,y-1,z) ;
        return ;
    }
    else if (z==3){
        if (x==1 || g[x-1][y]=='*'){
            mg(x,y,0) ;
            return ;
        }
        //cout << x-1 << " " <<y << " " << z<< " " << cnt << endl ;
        if (vis[x-1][y]){
            ans++;
        }
        vis[x-1][y]=false ;
        mg(x-1,y,z) ;
        return ;
    }
    return ;
}
int main (){
    freopen("explore.in","r",stdin) ;
    freopen("explore.out","w",stdout) ;
    cin >> t ;
    while (t--){
        memset(vis,true,sizeof(vis)) ;
        cin >> n >>m >>k ;
        int x,y,z ;
        cin >> x >>y >> z ;
        for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=m ; j++){
                char a ;
                cin >>a ;
                if (a=='x'){
                    g[i][j]='*' ;
                }
                else {
                    g[i][j]='.' ;
                }
            }
        }
        vis[x][y]=false ;
        ans=1 ;
        cnt=0 ;
        mg(x,y,z) ;
        cout << ans << endl ;
    }
    return 0 ;
}
