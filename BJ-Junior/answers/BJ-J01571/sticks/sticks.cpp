#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[10]={6,2,5,5,4,5,6,3,7,6};
ll y[20]={0,0,1,7,4,2,6,8,10,18,22,20,28,68,88};
ll a[100005];
void solve(ll n){
    ll cnt=0;
    ll sum=0;
    memset(a,0,sizeof(a));
    if(n<=1){
        cout<<-1<<endl;
        return;
    }
    if(n<=14){
        cout<<y[n]<<endl;
        return;
    }
    while(n>14){
        a[++cnt]=8;
        n-=7;
    }
    if(n<=7){
        a[++cnt]=y[n];
    }
    else{
        a[++cnt]=y[n]%10;
        a[++cnt]=y[n]/10;
    }
    for(int i=cnt;i>=1;i--){
        cout<<a[i];
    }
    cout<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ll T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        solve(n);
    }
    return 0;
}
