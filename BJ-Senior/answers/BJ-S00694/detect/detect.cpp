#include<bits/stdc++.h>
using namespace std;
struct car {
	int d,v,a;
	bool dd,on;
	vector<int> can;
} c[100005];
int p[100005];
int cnt[100005];
int ans,ans1;
int n,m,L,V;
map<int,map<int,bool> > mp;
void dfs(int x,int sum,int gs){
	if(sum==ans) {
		ans1=min(ans1,gs);
		return;
	}
	if(x==0) return ;
	dfs(x-1,sum+cnt[x],gs+1);
	dfs(x-1,sum,gs);
	
}
bool cmp(car a,car b){
	return a.d>b.d;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w", stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
			c[i].dd=0;
			c[i].on=0;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		sort(c+1,c+n+1,cmp);
		int i=1;
		for(int j=1;j<=n;j++){
			while(c[j].d>p[i]&&i<n) i++;
			if(c[j].d<=p[i]){
				c[j].on=1;
			}
			if(c[j].on) {
					if(c[j].v>V) {
					c[j].dd=1;
					cnt[i]++;
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++) if(c[i].dd) ans++;
		cout<<ans<<' ';
		ans1=0;
		dfs(n,0,0);
		ans1=n-ans1;
		cout<<ans1<<'\n';
	}
	return 0;
}
