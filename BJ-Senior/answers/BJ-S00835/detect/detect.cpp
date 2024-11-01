#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define ll __int128
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
int T,n,m,L,V,d[100010],v[100010],a[100010],p[100010];
bitset<100010>chao;
bool chk(int i,int j){// car i on detector j
	return d[i]>p[j]?0:v[i]*v[i]+2*a[i]*(p[j]-d[i])>V*V;
}
int b[100010];
vector<int>luandou[100010];
void solve(){
	cin>>n>>m>>L>>V;
	bool flg=1;
	for(int i=1;i<=n;++i)cin>>d[i]>>v[i]>>a[i],flg&=a[i]>=0;
	for(int i=1;i<=m;++i)cin>>p[i];
	int ans1=0;
	for(int i=1;i<=n;++i){
		auto it=lower_bound(p+1,p+m+1,d[i]);
		if(it==p+m+1)continue;
		ans1+=chao[i]=chk(i,it-p)||chk(i,m);
	}
	cout<<ans1<<" ";
	vector<pair<int,int>>limits;
	for(int i=1;i<=n;++i){
		if(!chao[i])continue;
		if(a[i]>0){
			int id=upper_bound(p+1,p+m+1,(V*V-v[i]*v[i])/(2*a[i])+d[i])-p;
			if(id<=m)limits.push_back({id,m});
		}else if(a[i]<0){
			int id=lower_bound(p+1,p+m+1,(-V*V+v[i]*v[i]+2*(-a[i])-1)/(2*(-a[i]))+d[i])-p-1;
			int id1=lower_bound(p+1,p+m+1,d[i])-p;
			if(id1<=id)limits.push_back({id1,id});
		}else{
			int id=lower_bound(p+1,p+m+1,d[i])-p;
			if(id<=m)limits.push_back({id,m});
		}
	}
	for(int i=1;i<=m;++i)luandou[i].clear();
	memset(b,0,sizeof(b));
	for(auto[l,r]:limits)luandou[r].push_back(l-1);
	for(int i=1;i<=m;++i){
		b[i]=max(b[i],b[i-1]);
		for(auto j:luandou[i])b[i]=max(b[i],b[j]+1);
	}
	cout<<m-b[m]<<'\n';
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	fre("detect");
	cin>>T;
	while(T--)solve();
    return 0;
}