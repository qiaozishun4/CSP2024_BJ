#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5,N2=1e6+5,inf=LLONG_MAX/2;
ll T,n,a[N],f[2][N],pre[N],lst[N2],maxn[2][N],sum[N];
int main(){
  freopen("color.in","r",stdin);
  freopen("color.out","w",stdout);
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>T;
  while(T--){
    cin>>n;
    ll up=0;
    for(int i=1;i<=n;++i){cin>>a[i];up=max(up,a[i]);}
    for(int i=0;i<=up;++i)lst[i]=0;
    sum[0]=0;
    for(int i=1;i<=n;++i)for(int tp=0;tp<=1;++tp)f[tp][i]=maxn[tp][i]=-inf,sum[i]=0;
    for(int i=1;i<=n;++i){
      pre[i]=i;
      if(lst[a[i]])pre[i]=lst[a[i]];
      lst[a[i]]=i;
    }
    for(int i=2;i<=n;++i){
      f[0][i-1]=maxn[1][i-2];
      f[1][i-1]=maxn[0][i-2];
      ll val=0;
      if(i>2)sum[i-2]=sum[i-3];
      if(pre[i]==i-1){
        sum[i-2]+=a[i];val=a[i];
      }else if(pre[i]<i-1){
        for(int tp=0;tp<=1;++tp){
          ll tmp=0;if(pre[i]-1>=0)tmp=sum[pre[i]-1];
          f[tp][i-1]=max(f[tp][i-1],f[tp^1][pre[i]]+sum[i-2]-tmp+a[i]);
        }
      }
      for(int tp=0;tp<=1;++tp)maxn[tp][i-1]=max(maxn[tp][i-2]+val,f[tp][i-1]);
    }
    cout<<max(maxn[0][n-1],maxn[1][n-1])<<endl;
  }
  return 0;
}
