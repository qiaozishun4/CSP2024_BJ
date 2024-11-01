#include<bits/stdc++.h>
using namespace std;
int d[3005],v[3005],a[3005],p[3005];
bool vis[3005];
vector<int> vec[3005];
bool cmp(vector<int> x,vector<int> y){
	return x.size()>y.size();
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T,n,m,L,V,ans;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			int l,r;
			if(v[i]>V){
				l=d[i],r=L;
				if(a[i]<0) r=min(r,int(d[i]+ceil((V*V-v[i]*v[i])*1.0/(2*a[i]))));
			}else{
				l=L+1,r=L;
				if(a[i]>0) l=min(L,int(d[i]+ceil((V*V-v[i]*v[i])*1.0/(2*a[i]))));
			}
			for(int j=1;j<=m;j++){
				if(p[j]>=l && p[j]<=r){
					vec[j].push_back(i);
					vis[i]=1;
				}
			}
			if(vis[i]) ans++;
		}
		cout<<ans<<" ";
		int cnt=0;
		sort(vec+1,vec+1+n,cmp);
		for(int i=1;i<=m;i++){
			for(int j=0;j<vec[i].size();j++){
				if(vis[vec[i][j]]){
					vis[vec[i][j]]=0;
					ans--;
				}
			}
			cnt++;
			if(!ans) break;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}