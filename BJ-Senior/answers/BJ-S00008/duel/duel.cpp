#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e5+5;
ll n;
ll a[MAXN];
ll cnt[MAXN];
ll vis[MAXN];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	// ll qwq=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		// qwq=max(qwq,a[i]);
	}
	// cout<<"debug "<<qwq<<endl;
	// cout<<cnt[1]<<" "<<cnt[2]<<endl;
	ll now=-1;
	for(int i=1;i<=1e5;i++){
		if(cnt[i]==0)continue;
		if(now==-1){
			now=i;
			continue;
		}
		// cout<<"Case "<<i<<" "<<"now="<<now<<'\n';
		while(vis[i]<=cnt[i]){
			if(now==i)break;
			if(cnt[now]>(cnt[i]-vis[i])){
				cnt[now]-=(cnt[i]-vis[i]);
				vis[i]=cnt[i];
				break;
			}
			vis[i]+=cnt[now];
			cnt[now]=0;
			// cout<<"? "<<now<<endl;
			while((cnt[now]==0)&&(now<i))now++;
			// cout<<"! "<<now<<endl;
		}
	}
	ll ans=0;
	for(int i=1;i<=1e5;i++)ans+=cnt[i];

	// cout<<"debug "<<cnt[1]<<" "<<cnt[2]<<endl;

	cout<<ans;
	return 0;
}