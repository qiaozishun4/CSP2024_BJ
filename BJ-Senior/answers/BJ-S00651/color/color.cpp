#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int typ[200005],n;
int a[100005],lst[2];
ll ans;
void ck(){
    ll an=0;
    lst[0]=lst[1]=0;
    for(int i=1;i<=n;i++){
        if(lst[typ[i]]!=0){
            an+=(a[lst[typ[i]]]==a[i])*a[i];
        }
        lst[typ[i]]=i;
    }
   // cout<<an<<" ";
    ans=max(ans,an);
}
void dfs(int pl){
    if(pl>n){
        ck();
        return;
    }
    typ[pl]=0;
    dfs(pl+1);
    typ[pl]=1;
    dfs(pl+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}
