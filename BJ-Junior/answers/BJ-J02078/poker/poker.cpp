// And in that light, I found deliverance.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
#define pb push_back
#define Cl(x) memset(x,0,sizeof(x))
#define all(x) x.begin(),x.end()
const int DC=0;
const int N=0;
const ll mod=0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll b,ll p=mod){ll ans=1;for(a%=p;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;return ans;}

int n;
set<string>t;

void __INIT__(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
void __SOLVE__(){
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		t.insert(s);
	}
	cout<<52-t.size()<<"\n";
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	__INIT__();
	int T;DC?cin>>T,0:T=1;
	for(int i=1;i<=T;i++)__SOLVE__();
	return 0;
}