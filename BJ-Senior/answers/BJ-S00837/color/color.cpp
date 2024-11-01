#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int t,a[N],c[N],ans[N],n;
ll maxx=0;
inline void solve2(){
    memset(ans,0,sizeof(ans));
    for(register int i=1;i<=n;i++){
        for(register int j=i-1;j>0;j--){
            if(c[i]==c[j]){
                if(a[i]==a[j]){
                    ans[i]=a[i];
                }
                break;
            }
        }
    }
    ll s=0;
    for(register int i=1;i<=n;i++){
        s+=ans[i];
    }
    maxx=max(maxx,s);
}
inline void solve(int x){
    if(x>n){
        solve2();
        return;
    }
    c[x]=0;
    solve(x+1);
    c[x]=1;
    solve(x+1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        maxx=-1;
        cin>>n;
        for(register int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n<=15){
            solve(1);
            cout<<maxx<<'\n';
            continue;
        }
        //for(register int i=1;i<=n;i++){

        //}
    }
    return 0;
}
