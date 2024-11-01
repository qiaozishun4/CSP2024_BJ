#include<bits/stdc++.h>
using namespace std;
typedef int ll;
char c[1005][1005];
bool b[1005][1005];
void dfs(ll cnt,ll x,ll y,ll d,ll n,ll m,ll k,ll ans){
     if(cnt == k){
        cout<<ans<<endl;
        return;
     }
     cnt++;
     if(d == 0){
        if(x >= 1 && x <= n && y + 1 >= 1 && y + 1 <= m && c[x][y + 1] != 'x' && b[x][y + 1] != true){
            ans++;
            b[x][y + 1] = true;
            dfs(cnt,x,y + 1,d,n,m,k,ans);
        }
        else if(x >= 1 && x <= n && y + 1 >= 1 && y + 1 <= m && c[x][y + 1] != 'x' && b[x][y + 1] == true){
            dfs(cnt,x,y + 1,d,n,m,k,ans);
        }
        else{
            dfs(cnt,x,y,1,n,m,k,ans);
        }
     }
     else if(d == 1){
        if(x + 1 >= 1 && x + 1 <= n && y >= 1 && y <= m && c[x + 1][y] != 'x' && b[x + 1][y] != true){
            ans++;
            b[x + 1][y] = true;
            dfs(cnt,x + 1,y,d,n,m,k,ans);
        }
        else if(x + 1 >= 1 && x + 1 <= n && y >= 1 && y <= m && c[x + 1][y] != 'x' && b[x + 1][y] == true){
            dfs(cnt,x + 1,y,d,n,m,k,ans);
        }
        else{
            dfs(cnt,x,y,2,n,m,k,ans);
        }
     }
     else if(d == 2){
        if(x >= 1 && x <= n && y - 1 >= 1 && y - 1 <= m && c[x][y - 1] != 'x' && b[x][y - 1] != true){
            ans++;
            b[x][y - 1] = true;
            dfs(cnt,x,y - 1,d,n,m,k,ans);
        }
        else if(x >= 1 && x <= n && y - 1 >= 1 && y - 1 <= m && c[x][y - 1] != 'x' && b[x][y - 1] == true){
            dfs(cnt,x,y - 1,d,n,m,k,ans);
        }
        else{
            dfs(cnt,x,y,3,n,m,k,ans);
        }
     }
     else if(d == 3){
        if(x - 1 >= 1 && x - 1 <= n && y >= 1 && y <=  m && c[x - 1][y] != 'x' && b[x - 1][y] != true){
            ans++;
            b[x - 1][y] = true;
            dfs(cnt,x - 1,y,d,n,m,k,ans);
        }
        else if(x - 1 >= 1 && x - 1 <= n && y >= 1 && y <=  m && c[x - 1][y] != 'x' && b[x - 1][y] == true){
            dfs(cnt,x - 1,y,d,n,m,k,ans);
        }
        else{
            dfs(cnt,x,y,0,n,m,k,ans);
        }
     }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ll t;
    cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        ll x,y,d;
        cin>>x>>y>>d;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                b[i][j] = false;
            }
        }
        b[x][y] = true;
        for(ll i = 1;i <= n;i++){
            for(ll j = 1;j <= m;j++){
                cin>>c[i][j];
            }
        }
        dfs(0,x,y,d,n,m,k,1);
    }
    return 0;
}
