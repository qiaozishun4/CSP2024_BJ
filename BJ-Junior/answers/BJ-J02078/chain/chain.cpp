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
const int DC=1;
const int N=0;
const ll mod=0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll b,ll p=mod){ll ans=1;for(a%=p;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;return ans;}

int n,k,m;
vector<int>v[200005];
int va[200005],le[105][200005];
bool vis[105][200005],ANS[105][200005];
int len[200005],cnt,from[200005];
bool cng[200005];

void __INIT__(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
void __SOLVE__(){
	Cl(cng);Cl(vis);Cl(ANS);
	for(int i=1;i<=200000;i++)v[i].clear();
	memset(le,0x3f,sizeof(le));
	cnt=0;
	cin>>n>>k>>m;//k--;
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=0;j<l;j++){
			++cnt;
			cin>>va[cnt];
			from[cnt]=i;
			v[va[cnt]].pb(cnt);
		}
		cng[cnt]=1;
	}
	cng[0]=1;
	va[0]=1;
	vector<int>q1,q2;
	q1.pb(0);
	for(int r=0;r<=100;r++){
		for(int _=0;_<q1.size();_++){
			int c=q1[_];
			ANS[r][va[c]]=1;
			// if(r<=6)cerr<<r<<" "<<c<<"("<<cng[c-1]<<")\n";
			for(auto i:v[va[c]])if(from[i]^from[c]&&!cng[i]){
				//c -> i,id
				le[r+1][i+1]=2;
				if(!vis[r+1][i+1])vis[r+1][i+1]=1,q2.pb(i+1);
			}
			if(!cng[c]&&le[r][c]<k&&le[r][c+1]>le[r][c]+1){
				le[r][c+1]=le[r][c]+1;
				if(!vis[r][c+1])vis[r][c+1]=1,q1.pb(c+1);
			}
		}
		q1=q2;q2.clear();
	}
	while(m--){
		int r,c;cin>>r>>c;
		cout<<ANS[r][c]<<"\n";
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	__INIT__();
	int T;DC?cin>>T,0:T=1;
	for(int i=1;i<=T;i++)__SOLVE__();
	return 0;
}