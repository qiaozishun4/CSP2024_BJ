#include<bits/stdc++.h>
using namespace std;
int n,ans,f[100005];
int cnt,mi,mx;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    mi=1e9+7;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        f[x]++;
        mi=min(mi,x);
        mx=max(mx,x);
    }
    for(int i=mi;i<=mx;i++){
        if(f[i]!=0){
            if(cnt<=f[i]){
                cnt=f[i];
                continue;
            }
        }
    }
    cout<<cnt;
    return 0;
}