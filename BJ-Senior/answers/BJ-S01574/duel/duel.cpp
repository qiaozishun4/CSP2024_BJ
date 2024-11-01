#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
ll ans,cnt[M];
string str;
int qpow(int b,int p){
    int res=1;
    while(p){
        if(p%2=1)res=1ll*res*b%M;
        p/=2;
        b=1ll*b*b%M;
    }
    return res;
}
int main(){
    cin>>str;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        cnt[u]++;
        cnt[v]++;
    }
    for(int i=1;i<=m;i++){
        ans+=cnt[i];
    }
    cout<<ans;
    return 0;
}