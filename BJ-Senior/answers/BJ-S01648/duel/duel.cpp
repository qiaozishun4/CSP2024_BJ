#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
const int N=1e5+10;
int r[N];
int vis[N]={};
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        vis[i]=1;
    }
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+n+1,greater<int>());
    for(int i=1;i<n;i++){
        if(vis[i]==1){
            for(int j=n;j>=i+1;j--){
                if(vis[j]!=0){
                    if(r[i]==r[j]) continue;
                    else{
                        vis[i]=0;
                        vis[j]=3;
                        break;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==3||vis[i]==1) ans++;
    }
    cout<<ans;
    return 0;
}
