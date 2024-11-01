#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll num[10]={6,2,5,5,4,5,6,3,7,6};
ll ans=1e9;
void dfs(ll n,ll cnt){
    if(n==0){
        ans=min(ans,cnt);
        return ;
    }
    if(n<2){
        return ;
    }
    if(cnt>=ans){
        return ;
    }
    for(int i=0;i<10;i++){
        if(cnt==0&&i==0) continue;
        if(n>=num[i]){
            dfs(n-num[i],cnt*10+i);
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ll T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        if(n<2){
            cout<<-1<<'\n';
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
        if(n%7==1&&n>7){
            cout<<10;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
        if(n%7==2&&n>7){
            cout<<1;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
        if(n%7==3&&n>7){
            if(n==10){
                cout<<22<<'\n';
                continue;
            }
            cout<<200;
            for(int i=1;i<=n/7-2;i++){
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
        if(n%7==4&&n>7){
            cout<<20;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
        if(n%7==5&&n>7){
            cout<<2;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
        if(n%7==6&&n>7){
            cout<<6;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
        ans=1e9;
        dfs(n,0);
        if(ans==1e9){
            cout<<-1<<'\n';
        }else{
            cout<<ans<<'\n';
        }
    }
    return 0;
}
/*
18
0123456789
6255456376

n%7==0 8~
n%7==1 108~
n%7==2 18~
*/
