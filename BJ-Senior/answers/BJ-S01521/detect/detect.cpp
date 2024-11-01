#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
const int inf=0x3f3f3f3f;
struct Node{
	ll l,r;
	bool sf=false;
};
const int M=1e6+5;
struct XDS{
	int l,r;
	int zhi;//zui xiao zhi
}tr[M*4];
int g[M*4];
XDS Merge(XDS a,XDS b){
	return XDS{a.l,b.r,min(a.zhi,b.zhi)};
}
void bud(int l,int r,int u){
	if(l==r){
		tr[u]={l,r,0};
		return;
	}
	int mi=(l+r)/2;
	bud(l,mi,u*2);
	bud(mi+1,r,u*2+1);
	tr[u]=Merge(tr[u*2],tr[u*2+1]);
}
//int jl(int u){return tr[u].r-tr[u].l+1;}
void lazy(int u){
	if(g[u]==0)return;
	tr[u*2].zhi+=g[u];
	tr[u*2+1].zhi+=g[u];
	g[u*2]+=g[u];
	g[u*2+1]+=g[u];
	g[u]=0;
}
int cha(int l,int r,int u){
	if(l<=tr[u].l&&tr[u].r<=r)return tr[u].zhi;
	lazy(u);
	int mi=(tr[u].l+tr[u].r)/2;
	if(r<=mi)return cha(l,r,u*2);
	else if(l>mi)return cha(l,r,u*2+1);
	else return min(cha(l,r,u*2),cha(l,r,u*2+1));
}
void add(int l,int r,int u,int d){
	if(l<=tr[u].l&&tr[u].r<=r){
		tr[u].zhi+=d;
		g[u]+=d;
		return;
	}
	lazy(u);
	int mi=(tr[u].l+tr[u].r)/2;
	if(r<=mi)add(l,r,u*2,d);
	else if(l>mi)add(l,r,u*2+1,d);
	else add(l,r,u*2,d),add(l,r,u*2+1,d);
	tr[u]=Merge(tr[u*2],tr[u*2+1]);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		ll L,V;
		cin>>n>>m>>L>>V;
		vl d(n+1),v(n+1),a(n+1);
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		vi p(m+1);
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		vector<Node>c;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>V)c.push_back({d[i],L});
			}
			if(a[i]>0){
				int l=d[i],r=L;
				int mi,sc=0;
				while(l<=r){
					mi=(l+r)/2;
					if((mi-d[i])*2*a[i]>V*V-v[i]*v[i]){
						r=mi-1;
						sc=mi;
					}else l=mi+1;
				}
				if(sc!=0)c.push_back({sc,L});
			}
			if(a[i]<0){
				if(v[i]<=V)continue;
				int l=d[i],r=L;
				int mi,sc=0;
				while(l<=r){
					mi=(l+r)/2;
					if((mi-d[i])*2*a[i]>V*V-v[i]*v[i]){
						l=mi+1;
						sc=mi;
					}else r=mi-1;
				}
				if(sc!=0)c.push_back({d[i],sc});
			}
		}
		//for(auto nd:c)cout<<"["<<nd.l<<","<<nd.r<<"]\n";
		int ans1=0;
		for(auto &nd:c){
			int x=lower_bound(p.begin()+1,p.end(),nd.l)-p.begin();
			if(p[x]<=nd.r)ans1++,nd.sf=1;
		}
		cout<<ans1<<" ";
		bud(1,L,1);
		int ans2=0;
		vi bj1(L+1,0);
		vi bj2(L+1,0);
		ll x=0;
		sort(c.begin(),c.end(),[&](Node x,Node y){return x.l<y.l;});
		for(auto nd:c){
			if(nd.sf==false)continue;
			for(x=max(x,nd.l);x<=nd.r;x++)bj1[x]=nd.l;
			int u=lower_bound(p.begin()+1,p.end(),nd.l)-p.begin();
			int v=lower_bound(p.begin()+1,p.end(),nd.r)-p.begin();
			if(p[v]>nd.r)v--;
			cout<<u<<" "<<v<<endl;
			if(v-u+1<=0)continue;
			add(nd.l,nd.r,1,v-u+1);
		}
		sort(c.begin(),c.end(),[&](Node x,Node y){return x.r>y.r;});
		x=L+1;
		for(auto nd:c){
			if(nd.sf==false)continue;
			for(x=min(x,nd.r);x>=nd.l;x--)bj2[x]=nd.r;
		}
		//for(int i=1;i<=m;i++)cout<<bj1[p[i]]<<" "<<bj2[p[i]]<<endl;
		for(int i=1;i<=m;i++){
			//cout<<cha(p[i],p[i],1)<<endl;
			//cout<<bj1[p[i]]<<" "<<bj2[p[i]]<<" "<<cha(bj1[p[i]],bj2[p[i]],1)<<endl;
			if(cha(bj1[p[i]],bj2[p[i]],1)>1){
				add(bj1[p[i]],bj2[p[i]],1,-1);
				ans2++;
			}
		}
		//cout<<cha(35943,40407,1)<<" "<<cha(40408,150307,1)<<" "<<cha(35943,150307,1);
		cout<<ans2<<endl;
	}
	return 0;
}