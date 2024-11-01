// Toilet Scuffle
// And in that light, I found deliverance.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define Cl(x) memset(x,0,sizeof(x))
const int DC=1;
const int N=0;
const ll mod=0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll b,ll p=mod){ll ans=1;for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;return ans;}

int n,a[200005];
ll f[2005][2005];

void __INIT__(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);}
void __SOLVE__(int _cs){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>2000)return;
	Cl(f);
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)if(i^j){
		int k=max(i,j)+1;
		f[k][j]=max(f[k][j],f[i][j]+((a[i]==a[k])?a[i]:0));
		f[i][k]=max(f[i][k],f[i][j]+((a[j]==a[k])?a[j]:0));
	}
	ll ans=0;
	for(int i=0;i<n;i++)ans=max(ans,f[i][n]);
	cout<<ans<<"\n";
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	__INIT__();
	int T;DC?cin>>T,0:T=1;
	for(int i=1;i<=T;i++)__SOLVE__(i);
	return 0;
}