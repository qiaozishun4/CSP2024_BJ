#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e3+10;
ll t,n,m,k,res=1,x,y,d;
bool a[N][N],f[N][N];
char c;
bool isin(ll x,ll y){
    return 1<=x&&x<=n&&1<=y&&y<=m;
}
void go(ll k,ll x,ll y,ll d){
    while(k--){

        if(d==0){
            if(isin(x,y+1)&&a[x][y+1]){
                if(!f[x][y+1]){
                    res++;
                    f[x][y+1]=1;
                }
                y++;
            }
            else{
                d=(d+1)%4;
            }
            continue;
        }
        if(d==1){
            if(isin(x+1,y)&&a[x+1][y]){
                if(!f[x+1][y]){
                    res++;
                    f[x+1][y]=1;
                }
                x++;
            }
            else{
                d=(d+1)%4;
            }
            continue;
        }
        if(d==2){
            if(isin(x,y-1)&&a[x][y-1]){
                if(!f[x][y-1]){
                    res++;
                    f[x][y-1]=1;
                }
                y--;
            }
            else{
                d=(d+1)%4;
            }
            continue;
        }
        if(d==3){
            if(isin(x-1,y)&&a[x-1][y]){
                if(!f[x-1][y]){
                    res++;
                    f[x-1][y]=1;
                }
                x--;
            }
            else{
                d=(d+1)%4;
            }
            continue;
        }

    }
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        res=1;
        f[x][y]=1;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                cin>>c;
                if(c=='.'){
                    a[i][j]=1;
                }
            }
        }
        go(k,x,y,d);
        cout<<res<<endl;
    }

    return 0;
}
