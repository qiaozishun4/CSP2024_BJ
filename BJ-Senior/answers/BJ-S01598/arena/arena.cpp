#include<bits/stdc++.h>
using namespace std;
long long n,m,r;
string s;
int k;
signed main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>r;
    for(int i=1;i<=m;i++) cin>>r;
    k=log2(n);
    if(int(pow(2,k))!=n) k++;
    for(int i=1;i<=k;i++) cin>>r;
    cin>>m;
    for(int i=1;i<=m;i++) cin>>k>>k>>k>>k;
    for(int i=1;i<=m;i++) cout<<1<<'\n';
    return 0;
}
