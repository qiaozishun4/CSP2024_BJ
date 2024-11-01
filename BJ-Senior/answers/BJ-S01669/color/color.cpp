#include <bits/stdc++.h>
using namespace std;
long long n,ans=INT_MIN;
vector<int> v,a;
void check(){
    long long cnt=0;
    for(int i=1;i<n;i++){
        long long t=i-1;
        while(t>=0&&a[t]!=a[i]){
            t--;
        }
        if(t>=0&&v[t]==v[i])cnt+=v[t];
    }
    ans=max(ans,cnt);
}
void dfs(long long k){
    if(k==0){
        check();
        return;
    }
    for(int i=0;i<2;i++){
        a[n-k]=i;
        dfs(k-1);
    }
}
int main(){
    freopen("color. in","r",stdin);
    freopen("color.out","w",stdout);
    long long t;
    cin>>t;
    while(t--){
        ans=INT_MIN;
        cin>>n;
        v.resize(n,0);
        a.resize(n,0);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        if(n<=15){
            dfs(n);
        }
        cout<<ans<<'\n';
    }
    return 0;
}