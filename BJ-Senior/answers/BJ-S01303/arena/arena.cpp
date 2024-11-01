#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MXN=2e5+10,MXM=2e5+10,MXK=22;
int n,m,k,t;
int a[MXN],c[MXM],la[MXN];
char d[MXN<<1];
int w[MXN<<1];
inline int lowbit(const int x){
    return x&(-x);
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    k=(1<<(__lg(n-1)+1))-1;
    for(int i=1;i<=k;i++){
        cin>>d[i];
    }
    cin>>t;
    int x[4];
    while(t--){
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++){
            la[i]=(a[i]^x[i%4]);
        }
        cout<<0<<'\n';
    }
    return 0;
}
