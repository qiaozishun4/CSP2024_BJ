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

int n,m,L,V;
int d[100005],v[100005],a[100005];
pii q[100005];
double p[100005];

void __INIT__(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);}
void __SOLVE__(int _cs){
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
	for(int i=1;i<=m;i++)cin>>p[i];
	sort(p+1,p+m+1);
	for(int i=1;i<=n;i++){
		//calc Tmax
		int smx=L-d[i];
		int sqrvmx;
		double ld,rd;
		if(a[i]==0){
			if(v[i]>V)ld=d[i],rd=L;
			else ld=rd=0;
		}else{
			if(v[i]*v[i]+2*a[i]*smx<0)sqrvmx=0;
			else sqrvmx=v[i]*v[i]+2*a[i]*smx;
			if(v[i]<=V&&sqrvmx<=V*V)ld=rd=0;
			if(v[i]>V&&sqrvmx>V*V)ld=d[i],rd=L;
			if(v[i]<=V&&sqrvmx>V*V)ld=d[i]+(V*V-v[i]*v[i])/2.0/a[i]+1e-5,rd=L;
			if(v[i]>V&&sqrvmx<=V*V){
				ld=d[i],rd=d[i]+(V*V-v[i]*v[i])/2.0/a[i]-1e-5;
			}
		}
		q[i].fi=lower_bound(p+1,p+m+1,ld)-p;
		q[i].se=upper_bound(p+1,p+m+1,rd)-p-1;
		if(q[i].fi>q[i].se)q[i]={114514,1919810};
		// cerr<<i<<": "<<ld<<" "<<rd<<" "<<q[i].fi<<" "<<q[i].se<<"\n";
	}
	sort(q+1,q+n+1,[&](pii a,pii b){return a.se<b.se;});
	while(n&&q[n].se==1919810)n--;
	int cnt=0,mx=0;
	for(int i=1;i<=n;i++){
		if(q[i].fi>mx)mx=q[i].se,++cnt;
	}
	cout<<n<<" "<<m-cnt<<"\n";
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	__INIT__();
	int T;DC?cin>>T,0:T=1;
	for(int i=1;i<=T;i++)__SOLVE__(i);
	return 0;
}