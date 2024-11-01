#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;
ll n,m,k,sx,sy,sd,cnt,f[10005][10005];
char a[10005][10005];
ll checkx(ll d){
    if(d==1){
        return 1;
    }
    if(d==3){
        return -1;
    }
    return 0;
}
ll checky(ll d){
    if(d==0){
        return 1;
    }
    if(d==2){
        return -1;
    }
    return 0;
}
void dfs(ll x,ll y,ll d,ll now){
    if(now>k){
        return;
    }
    if(f[x][y]==0){
        cnt++;
        f[x][y]=1;
    }
    ll dx=x+checkx(d),dy=y+checky(d);
    if(dx>=1&&dx<=n&&dy>=1&&dy<=m){
        if(a[dx][dy]=='.'){
            dfs(dx,dy,d,now+1);
        }else{
            dfs(x,y,(d+1)%4,now+1);
        }

    }else{
        dfs(x,y,(d+1)%4,now+1);
    }
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(ll t=1;t<=T;t++){
        cnt=0;
        memset(f,0,sizeof(f));
        cin>>n>>m>>k;
        cin>>sx>>sy>>sd;
        //cout<<n<<" "<<m<<" "<<k<<endl;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                cin>>a[i][j];
                //scanf("%.s",a[i][j]);
            }
        }
        dfs(sx,sy,sd,0);
        cout<<cnt<<endl;
        //<<n<<" "<<m<<" "<<k<<endl;
        /*for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                cout<<f[i][j]<<" ";
            }
            cout<<endl;
        }*/
    }

    return 0;
}
