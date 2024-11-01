#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],c[N],ans;
void dfs(int x){
    if(x==n+1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(c[i]==c[j]){
                    if(a[i]==a[j]){
                        cnt+=a[i];
                    }
                    break;
                }
            }
        }
        ans=max(ans,cnt);
        return ;
    }
    c[x]=0;
    dfs(x+1);
    c[x]=1;
    dfs(x+1);
}
void solve(){
    memset(c,0,sizeof(c));
    ans=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    dfs(1);
    cout <<ans<<endl;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}
