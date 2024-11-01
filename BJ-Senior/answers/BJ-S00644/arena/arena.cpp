#include<iostream>
using namespace std;
typedef long long ll;
const ll inf=10000000000;
ll t,n,m,x[4],a[100005],ans[100005],c[100005],f[800005],BD,qp,g[800005],lgs[800005],lgp[800005];
string d[25];
void psup(ll p,ll l,ll r){
	ll t=r/(r-l+1),Q;
	Q=lgs[r-l+1]-1;
	//cout<<p<<" "<<l<<" "<<r<<" HV Legnth"<<Q<<endl;
	if(d[Q][t-1]=='0'){
		if(f[p<<1]>=Q){
			f[p]=f[p<<1];
			g[p]=g[p<<1];
		}
		else{
			f[p]=f[p<<1|1];
			g[p]=g[p<<1|1];
		}
	}
	else{
		if(f[p<<1|1]<Q){
			f[p]=f[p<<1];
			g[p]=g[p<<1];
		}
		else{
			f[p]=f[p<<1|1];
			g[p]=g[p<<1|1];
		}
	}
}
void build(ll p,ll l,ll r){
	if(l==r){
		if(l<=BD){
			f[p]=a[l];
		}
		else{
			f[p]=0;
		}
		g[p]=l;
		return ;
	}
	ll mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	psup(p,l,r);
}
void modify(ll p,ll l,ll r,ll wz,ll v){
	if(l==r){
		f[p]=v;
		return ;
	}
	ll mid=(l+r)>>1;
	if(wz<=mid){
		modify(p<<1,l,mid,wz,v);
	}
	else{
		modify(p<<1|1,mid+1,r,wz,v);
	}
	psup(p,l,r);
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=2*n;i++){
		lgs[i]=lgs[i>>1]+1;
		lgp[i]=(lgs[i]!=lgs[i-1]);
	}
	for(ll i=0;i<=20;i++){
		if((1ll<<i)>=n){
			qp=i;
			break;
		}
	}
	//cout<<"lAWRENCE "<<qp<<endl<<endl<<endl;
	for(ll i=1;i<=m;i++){
		cin>>c[i];
	}
	for(ll i=1;i<=qp;i++){
		cin>>d[i];
	}
	cin>>t;
	while(t--){
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(ll i=1;i<=n;i++){
			a[i]^=x[i%4];
		}
		BD=1;
		build(1,1,1);
		for(ll i=1;i<=n;i++){
			modify(1,1,BD,i,a[i]);
			//cout<<i<<" "<<g[1]<<endl;
			ans[i]=0;
			ans[i]=g[1];
			for(ll j=i+1;j<=BD;j++){
				modify(1,1,BD,j,inf);
				if(g[1]==j){
					ans[i]+=j;
				}
				modify(1,1,BD,j,0);
			}
			ll now=1;
			if(lgp[i]){
				build(1,1,2*i);
				BD=2*i;
			}
		}
		ll ret=0;
		for(ll i=1;i<=m;i++){
			ret^=(i*ans[c[i]]);
		}
		cout<<ret<<endl;
		for(ll i=1;i<=n;i++){
			a[i]^=x[i%4];
		}
	}
	return 0;
}
