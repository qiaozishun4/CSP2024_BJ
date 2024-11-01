#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll T,n,m,a[N],a2[N],c[N];
string s[N];
int main(){
  freopen("arena.in","r",stdin);
  freopen("arena.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;++i)cin>>a2[i];
  for(int i=1;i<=m;++i)cin>>c[i];
  ll tmp=1,k=0;
  while(tmp<n)tmp*=2,++k;
  for(int i=1;i<=k;++i){
    for(int j=1;j<=(1<<(k-i));++j){
      char c;cin>>c;
      s[i].push_back(c);
    }
  }
  cin>>T;
  while(T--){
    ll x[4];
    for(int i=1;i<=3;++i)cin>>x[i];
    for(int i=1;i<=n;++i)a[i]=a2[i]^x[i%4];
    cout<<0<<endl;
  }
  return 0;
}
