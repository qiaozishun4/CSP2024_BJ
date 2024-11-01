#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int maxn=2e5+10,maxm=1e6+10;
struct T{
	int d,v,a;
}a[maxn];
int n,m,L,v,p[maxn],ans1,ans2;
bool vis[maxn];
vector<int> e[maxn];
inline int getl(int x){
	return lower_bound(p+1,p+1+m,x)-p;
}
inline int getr(int x){
	return upper_bound(p+1,p+1+m,x)-p-1;
}
set<int> se;
void so(){
	cin>>n>>m>>L>>v;ans1=ans2=0;se.clear();
	for(int i=1;i<=m;i++) e[i].clear();
	for(int i=1;i<=n;i++) cin>>a[i].d>>a[i].v>>a[i].a;
	for(int i=1;i<=m;i++) cin>>p[i];p[m+1]=0;
	for(int i=1;i<=n;i++){
		int pre=ans1;
		if(a[i].d>p[m]) continue;
		if(a[i].a>0){
			if(a[i].v>v){
				int nxt=getl(a[i].d);
				e[nxt].push_back(m);
				vis[nxt]=1;
				ans1++;
			}
			else{
				int l=0,r=L-a[i].d,ans=-1;
				while(l<=r){
					ll mid=l+r>>1;
					if(a[i].v*a[i].v+2*a[i].a*mid>v*v) ans=mid,r=mid-1;
					else l=mid+1;
				}
				if(ans==-1) continue;
				int nxt=getl(a[i].d+ans);
				if(a[i].d+ans>p[m]) continue;
				e[nxt].push_back(m);
				vis[nxt]=1;
				ans1++;
			}
		}
		if(a[i].a==0&&a[i].v>v){
			int nxt=getl(a[i].d);
			e[nxt].push_back(m);
			vis[nxt]=1;
			ans1++;
		}
		if(a[i].a<0){
			if(a[i].v>v){
				int l=0,r=L-a[i].d,ans=-1;
				while(l<=r){
					int mid=l+r>>1;
					if(a[i].v*a[i].v+2*a[i].a*mid>v*v) ans=mid,l=mid+1;
					else r=mid-1;
				}
				if(ans==-1) continue;
				int nxt=getr(a[i].d+ans),cur=getl(a[i].d);
				if(p[nxt]<a[i].d||p[cur]>a[i].d+ans) continue;
				e[cur].push_back(nxt);
				ans1++;
			}
		}
		//if(ans1>pre) cout<<i<<endl;
	}
	for(int i=1;i<=m;i++){
		for(int x:e[i]) se.insert(x);
		if(se.size()&&*se.begin()<=i) se.clear(),ans2++;
	}
	cout<<ans1<<' '<<m-ans2<<endl;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;cin>>t;
	while(t--) so();
	return 0;
}
