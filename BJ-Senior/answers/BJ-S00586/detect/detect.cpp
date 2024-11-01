#include<bits/stdc++.h>
using namespace	std;
int d[100005],v[100005],a[100005];
int p[100005];
int n,m,l,V;
vector<int> dfs_arr;
int key;
int maxn;
void dfs(int x,int now){
	if(x==m+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			bool f=false;
			for(int j:dfs_arr){
				if(a[i]==0){
					if(d[i]<=p[j]&&v[i]>V){
						f=true;
						break;
					}
				}
				else{
					if(d[i]<=p[j]&&(v[i]*v[i]+2*a[i]*(p[j]-d[i]))>0&&sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]))>V){
						f=true;
						break;
					}
				}
			}
			if(f) cnt++;
		}
		if(cnt==key){
			maxn=max(maxn,m-now);
		}
		return ;
	}
	dfs_arr.push_back(x);
	dfs(x+1,now+1);
	dfs_arr.pop_back();
	dfs(x+1,now);
}
void fun(){
	cin>>n>>m>>l>>V;
	if(n<=20&&m<=20){
		maxn=0;
		key=0;
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>p[i];
		for(int i=1;i<=n;i++){
			bool f=false;
			for(int j=1;j<=m;j++){
				if(a[i]==0){
					if(d[i]<=p[j]&&v[i]>V){
						f=true;
						break;
					}
				}
				else{
					if(d[i]<=p[j]&&sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]))>V){
						f=true;
						break;
					}
				}
			}
			if(f) key++;
		}
		dfs(1,0);
		cout<<key<<' '<<maxn<<endl;
	}
	else{
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>p[i];
		sort(p+1,p+m+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(d[i]<=p[m]&&v[i]>V) ans++;
			}
			else{
				if(d[i]<=p[m]&&sqrt(v[i]*v[i]+2*a[i]*(p[m]-d[i]))>V) ans++;
			}
		}
		if(ans) cout<<ans<<' '<<m-1<<endl;
		else cout<<0<<' '<<m<<endl;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) fun();
	return 0;
}
