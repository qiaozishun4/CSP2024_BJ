#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200001],ans=0;
bool b[200001];
void dfs(int k){
    if(k>n){
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(b[i]==b[j]){
                    if(a[i]==a[j]){
                        cnt+=a[i];
                    }
                    break;
                }
            }
        }
        if(ans<cnt){
            ans=cnt;
        }
        return;
    }
    b[k]=1;
    dfs(k+1);
    b[k]=0;
    dfs(k+1);
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=0;
        }
        ans=0;
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}