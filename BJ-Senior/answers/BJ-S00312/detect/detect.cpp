#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int T,n,m,l,lim,lim2,p[N],a1,a2,nwr;
struct CAR{int d,v,a;}a[N];
struct Node{int l,r;}c[N];
inline ll x2(ll x){return x*x;}
inline bool check(ll v,ll a,ll s){return x2(v)+2ll*a*s>lim2;}
void solve(int i){
	int l=1,r=m+1;
	while(l<r){
		int mid=l+r>>1;
		if(p[mid]>=a[i].d)	r=mid;
		else	l=mid+1;
	}
	if(l==m+1)	c[i].l=c[i].r=0;
	else if(!a[i].a){
		if(a[i].v>lim)	c[i].l=l,c[i].r=m;
		else	c[i].l=c[i].r=0;
	}else if(a[i].a<0){
		c[i].l=l,r=m,l--;
			while(l<r){
			int mid=l+r+1>>1;
			if(check(a[i].v,a[i].a,p[mid]-a[i].d))	l=mid;
			else	r=mid-1;
		}
		if(l>=c[i].l)	c[i].r=l;
		else	c[i].l=c[i].r=0;
	}else{
		r=m+1;
		while(l<r){
			int mid=l+r>>1;
			if(check(a[i].v,a[i].a,p[mid]-a[i].d))	r=mid;
			else	l=mid+1;
		}
		if(l<=m)	c[i].l=l,c[i].r=m;
		else	c[i].l=c[i].r=0;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>l>>lim,lim2=x2(lim);
		for(int i=1;i<=n;i++)cin>>a[i].d>>a[i].v>>a[i].a;
		for(int i=1;i<=m;i++)cin>>p[i];
		for(int i=1;i<=n;i++)solve(i);
		sort(c+1,c+1+n,[&](Node x,Node y){return x.r<y.r;});
		nwr=a1=a2=0;
		for(int i=1;i<=n;i++){
			if(!c[i].l&&!c[i].r)	a1++;
			else if(c[i].l>nwr)	nwr=c[i].r,a2++;
		}
		cout<<n-a1<<' '<<m-a2<<'\n';
	}
	return 0;
}