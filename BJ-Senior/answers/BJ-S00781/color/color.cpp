#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[200005];
int tmp[200005];
int n;

int ans;
void dfs(int times){
    if(times==n+1){
        int ret; ret=0;

        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(tmp[j]==tmp[i]){
                    if(a[i]==a[j]){
                        ret+=a[i];
                    }
                    break;
                }
            }
        }

        //cout<<ret<<endl;
        ans=max(ans,ret);
        return;
    }

    tmp[times]=1;
    dfs(times+1);
    tmp[times]=0;
    dfs(times+1);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("color.in" ,"r",stdin);
    freopen("color.out","w",stdout);

    int t; cin>>t;

    while(t--){
        cin>>n;

        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

        ans=0;
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
