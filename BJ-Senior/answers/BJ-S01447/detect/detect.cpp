#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,W=1e6+5;

int n,m,L,V,tot;
int d[N],v[N],a[N];
int pre[W],p[N];
vector<int> t[N];

void check(int l,int r,int id) {
	if (l>r) return;
	r=min(r,L);
	if (pre[r]!=(l?pre[l-1]:0)) {
		int lid=lower_bound(p+1,p+m+1,l)-p;
		int rid=upper_bound(p+1,p+m+1,r)-p-1;
		t[rid].push_back(lid);
		tot++;
		//cout<<l<<' '<<r<<'\n';
	}
	//if (pre[r]!=(l?pre[l-1]:0))
//		cout<<id<<" out\n";
}

int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin>>T;
	while (T--) {
		cin>>n>>m>>L>>V; tot=0;
		for (int i=0; i<=L; i++) pre[i]=0;
		for (int i=1; i<=m; i++) t[i].clear();
		for (int i=1; i<=n; i++) cin>>d[i]>>v[i]>>a[i];
		for (int i=1; i<=m; i++) {cin>>p[i]; pre[p[i]]++;}
		sort(p+1,p+m+1);
		for (int i=1; i<=L; i++) pre[i]+=pre[i-1];
		for (int i=1; i<=n; i++) {
			if (a[i]==0) {
				if (v[i]>V) check(d[i],L,i);
			} else if (a[i]>0) {
				if (v[i]>V) check(d[i],L,i);
				else {
					int tmp=d[i]+floor(1.0*(V*V-v[i]*v[i])/(2.0*a[i]))+1;
					check(tmp,L,i);
				}
			} else {
				if (v[i]>V) {
					int tmp=d[i]+ceil(1.0*(V*V-v[i]*v[i])/(2.0*a[i]))-1;
//					cout<<"id "<<i<<' '<<tmp<<'\n';
					check(d[i],tmp,i);
				}
			}
		} cout<<tot<<' ';
		for (int i=1; i<=m; i++)
			if (t[i].size()>1) sort(t[i].begin(),t[i].end(),greater<int>());
		int maxn=-1,cnt=0;
		for (int i=1; i<=m; i++) {
			while (t[i].size()&&t[i].back()<=maxn) t[i].pop_back();
			if (t[i].size()) maxn=i,cnt++;
		}
		cout<<m-cnt<<'\n';
	}
	return 0;
}