#include<bits/stdc++.h>
using namespace std;

int t,ans;
int n,a[200010];
bool f[200010];

void dfs(int st){
    if(st>n){
        int x=0,y=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(f[i]==0){
                if(a[i]==a[x])
                    cnt+=a[x];
                x=i;
            }
            if(f[i]==1){
                if(a[i]==a[y])
                    cnt+=a[y];
                y=i;
            }
        }
        ans=max(ans,cnt);
        return;
    }
    f[st]=0;
    dfs(st+1);
    f[st]=1;
    dfs(st+1);
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>t;
    while(t--){
        memset(f,0,sizeof(f));
        ans=-1;

        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];

        dfs(1);

        cout<<ans<<"\n";
    }
    return 0;
}

