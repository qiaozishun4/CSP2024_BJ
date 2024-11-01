#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int n;
int a[N];

int c[N];

int ans=0;

void dfs(int i){
    if(i==n+1){
        int sum=0;
        int lst[2]={-1,-1};
        for(int j=1;j<=n;j++){
            if(lst[c[j]]==a[j]){
                sum+=a[j];
            }
            lst[c[j]]=a[j];
        }
        ans=max(ans,sum);
        return;
    }
    c[i]=0;
    dfs(i+1);
    c[i]=1;
    dfs(i+1);
}

void solve(){
    ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<ans<<endl;
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        solve();
    }

    return 0;
}