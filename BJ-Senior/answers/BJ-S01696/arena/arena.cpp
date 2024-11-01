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
const int DC=0;
const int N=0;
const ll mod=0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll b,ll p=mod){ll ans=1;for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;return ans;}

int n,m,A[100005],a[100005],b[100005],c[100005],k;
bool tp[20][262155];
ll ANS[100005];
ll ans[20][262155],cnt[20][262155],dep,cur;
void bld(int d,int x){
	if(d)bld(d-1,x*2-1),bld(d-1,x*2),cnt[d][x]=cnt[d-1][x*2-1]+cnt[d-1][x*2],ans[d][x]=ans[d-1][x*2-1]+ans[d-1][x*2];
	else cnt[d][x]=1,ans[d][x]=x;
}
void add(int d,int x){//modify x at dep=d
	if(!d){
		cnt[d][x]=1,ans[d][x]=x;
	}else{
		int c=!tp[d][x];
		if(cnt[d-1][x*2-c]==1&&ans[d-1][x*2-c]<=cur){
			if(a[ans[d-1][x*2-c]]>=d)cnt[d][x]=1,ans[d][x]=ans[d-1][x*2-c];
			else cnt[d][x]=cnt[d-1][x*2-!c],ans[d][x]=ans[d-1][x*2-!c];
		}else{
			cnt[d][x]=cnt[d-1][x*2-1]+cnt[d-1][x*2];
			ans[d][x]=ans[d-1][x*2-1]+ans[d-1][x*2];
		}
		// cerr<<"add "<<d<<" "<<x<<": "<<cnt[d-1][x*2-1]<<" "<<ans[d-1][x*2-1]<<" "<<cnt[d-1][x*2]<<" "<<ans[d-1][x*2]<<" "<<cnt[d][x]<<" "<<ans[d][x]<<" "<<tp[d][x]<<"\n";
	}
	if(d<dep)add(d+1,(x+1)/2);
}
int calc(int d,int x){
	if(!d)return x;
	int l=calc(d-1,x*2-1),r=calc(d-1,x*2);
	if(tp[d][x]==0)return b[l]>=d?l:r;
	return b[r]>=d?r:l;
}
bool can[262155];
void chk(int x){
	if(x>(1<<dep)){
		can[calc(dep,1)]=1;
		return;
	}
	for(int i=0;i<=dep;i++){
		b[x]=i;
		chk(x+1);
	}
}

void __INIT__(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);}
void __SOLVE__(int _cs){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>A[i];
	for(int i=1;i<=m;i++)cin>>c[i];
	while((1<<k)<n)k++;
	for(int i=1;i<=k;i++)for(int j=1;j<=(1<<k-i);j++){
		char c;
		cin>>c;
		tp[i][j]=c=='1';
	}
	int t;
	cin>>t;
	while(t--){
		int x[4];cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++)a[i]=A[i]^x[i%4];
		if(n<=8){
			ll res=0;
			for(int i=1;i<=m;i++){
				cur=c[i];
				dep=0;
				while((1<<dep)<cur)dep++;
				for(int i=1;i<=cur;i++)b[i]=a[i];
				Cl(can);
				chk(cur+1);
				ll s=0;
				for(int i=1;i<=(1<<dep);i++)if(can[i])s+=i;
				res^=1ll*i*s;
			}
			cout<<res<<"\n";
			continue;
		}
		// calc
		Cl(ANS);Cl(ans);Cl(cnt);
		dep=0;
		ANS[1]=ans[0][1]=cnt[0][1]=1;
		for(cur=2;cur<=n;cur++){
			if((1<<dep)<cur){
				dep++;bld(dep-1,2);
			}
			add(0,cur);
			ANS[cur]=ans[dep][1];
		}
		ll res=0;
		for(int i=1;i<=m;i++)res^=1ll*i*ANS[c[i]];
		cout<<res<<"\n";
	}
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	__INIT__();
	int T;DC?cin>>T,0:T=1;
	for(int i=1;i<=T;i++)__SOLVE__(i);
	return 0;
}