#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5;

ll n,m;
ll a3[N+5];
ll c[N+5];
ll K,k;
char d[2*N+5][30];
ll T;
ll X[5];
ll a2[N+5];
ll len;
ll a[N+5];
set<ll> res;
ll mp[N+5];
void cal(){
	vector<ll> last;
	vector<ll> ans;
	for(ll i=1;i<=len;i++)
		ans.push_back(i);
	for(ll t=1;t<=k;t++){
		last=ans;
		ans.erase(ans.begin(),ans.end());
		for(ll i=0;i<last.size();i+=2){
			//i & i+1;
			if(d[t][i/2]=='0'){
				if(a[last[i]]>=t)
					ans.push_back(last[i]);
				else
					ans.push_back(last[i+1]);
			}
			else{
				if(a[last[i+1]]>=t)
					ans.push_back(last[i+1]);
				else
					ans.push_back(last[i]);
			}
		}
	}
	res.insert(ans[0]);
	return ;
}
void dfs(ll x){
	if(x>len){	
		cal();
		return ;
	}
	for(ll i=0;i<=k+1;i++){
		a[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a3[i];
	for(ll j=1;j<=m;j++)
		cin>>c[j];
	K=ceil(log2(n));
	for(ll i=1;i<=K;i++)
		cin>>d[i];
	cin>>T;
	while(T--){
		res.erase(res.begin(),res.end());
		cin>>X[0]>>X[1]>>X[2]>>X[3];
		for(ll i=1;i<=n;i++)
			a2[i]=a3[i]^X[i%4];
		ll ans=0;
		memset(mp,0,sizeof(mp));
		for(ll i=1;i<=m;i++){
			ll sum=0;
			if(!mp[c[i]]){
				k=ceil(log2(c[i]));
				res.erase(res.begin(),res.end());
				len=(1<<k);
				for(ll j=1;j<=c[i];j++)
					a[j]=a2[j];
				dfs(c[i]+1);
				for(auto it=res.begin();it!=res.end();it++)
					sum+=*it;
			}
			else
				sum=mp[c[i]];
			ans=ans^((ll)i*sum);
			mp[c[i]]=sum;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//caijiuduolian