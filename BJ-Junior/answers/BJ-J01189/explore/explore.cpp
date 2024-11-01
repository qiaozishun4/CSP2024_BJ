#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = int(1e3+10);
int n,m,k;
bool maps[MAX_N][MAX_N],runs[MAX_N][MAX_N];
bool lists(char a){
    if(a=='x')return true;
    return false;
}
bool run(int x,int y,int d){
    if(d==0){
        y++;
    }else if(d==1){
        x++;
    }else if(d==2){
        y--;
    }else if(d==3){
        x--;
    }
    if(x<1)return false;
    if(x>n)return false;
    if(y<1)return false;
    if(y>m)return false;
    if(maps[x][y])return false;
    return true;
}
void solve(){
    cin >> n >> m >> k;
    int x,y,d;
    cin >> x >> y >> d;
    runs[x][y]=true;
    int ans=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char a;
            cin >> a;
            if(lists(a)){
                maps[i][j]=true;
            }
        }
    }
    while(k--){
        if(run(x,y,d)){
            if(d==0){
                y++;
            }else if(d==1){
                x++;
            }else if(d==2){
                y--;
            }else if(d==3){
                x--;
            }
        }else{
            d=(d+1)%4;
        }
        if(!runs[x][y]){
            ans++;
            runs[x][y]=true;
        }

    }
    cout << ans << '\n';
    memset(maps,0,sizeof(maps));
    memset(runs,0,sizeof(runs));
}
int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}