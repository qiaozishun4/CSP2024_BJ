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

int n,m,k,x,y,d;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char mp[1005][1005];
bool vis[1005][1005];

void __INIT__(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
void __SOLVE__(){
	Cl(vis);
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>mp[i][j];
	vis[x][y]=1;
	while(k--){
		if(1<=x+dir[d][0]&&x+dir[d][0]<=n&&1<=y+dir[d][1]&&y+dir[d][1]<=m&&mp[x+dir[d][0]][y+dir[d][1]]=='.')
			x+=dir[d][0],y+=dir[d][1];
		else ++d%=4;
		vis[x][y]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ans+=vis[i][j];
	cout<<ans<<"\n";
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	__INIT__();
	int T;DC?cin>>T,0:T=1;
	for(int i=1;i<=T;i++)__SOLVE__();
	return 0;
}