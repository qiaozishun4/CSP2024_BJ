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
const int DC=0;
const int N=0;
const ll mod=0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll b,ll p=mod){ll ans=1;for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;return ans;}

int n,a[100005];

void __INIT__(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);}
void __SOLVE__(int _cs){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[l])l++;
	}
	cout<<n-l+1<<"\n";
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	__INIT__();
	int T;DC?cin>>T,0:T=1;
	for(int i=1;i<=T;i++)__SOLVE__(i);
	return 0;
}