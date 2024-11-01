#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct zone{
	long long int l,r;
};
const int MAXN = 100005;
int T;
long long n,m;
long long int L,V;
long long int d[MAXN],v[MAXN],a[MAXN];
long long int p[MAXN];
long long int p0[MAXN];
int ba[MAXN];
struct evt{
	long long int type,id,x;
}e[5*MAXN];
int cnt1;
bool cmp(evt a,evt b){
	if(a.x==b.x){
		return a.type<b.type;
	}
	return a.x<b.x;
}
zone check(long long d,long long int v,long long int a){
	int l = 1,r = m;
	if(p[m]<d)return (zone){0,0};
	while(l<r){
		int mid = (l+r)>>1;
		if(p[mid]>=d)r = mid;
		else l = mid+1;
	}
	//l:first p[l]>=d

	if(a>=0){
		if(V*V<(v*v+2*a*(p[m]-d))){//limit exceeded at the end
			r = m;
			while(l<r){
				int mid = (l+r)>>1;
				if(V*V<(v*v+2*a*(p[mid]-d)))r = mid;
				else l = mid+1;
			}
			return (zone){l,m};
		}else{
			return (zone){0,0};
		}
	}else{
		if(V*V>=(v*v+2*a*(p[l]-d))){
			return (zone){0,0};
		}
		int st = l;
		r = m;
		while(l<r){
			int mid = (l+r+1)>>1;
			if(V*V<(v*v+2*a*(p[mid]-d)))l = mid;
			else{
				r = mid-1;
			}
		}
		return (zone){st,l};
	}
}
void pro(){
	cnt1 = 0;

	scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
	for(int i = 1;i<=n;i++){
		ba[i] = 0;
		scanf("%lld%lld%lld",d+i,v+i,a+i);
	}
	for(int i = 1;i<=m;i++){
		scanf("%lld",p0+i);
	}
	int ans1 = 0;
	int ans2 = 0;
	int cnt0 = 0;
	sort(p0+1,p0+1+m);
	for(int i = 1;i<=m;i++){
		if(p0[i]!=p0[i-1]){
			p[++cnt0] = p0[i];
		}else{
			ans2++;
		}
	}
	m = cnt0;
	for(int i = 1;i<=n;i++){
		zone ret;
		ret = check(d[i],v[i],a[i]);
		if(ret.l == 0){
			continue;
		}else{
			ans1++;
			e[++cnt1] = (evt){1,i,ret.l};
			e[++cnt1] = (evt){2,i,ret.r};
		}
	}
	int ans3 = 0;
	int lst = 0;
	sort(e+1,e+1+cnt1,cmp);
	for(int i = 1;i<=cnt1;i++){
		if(ba[e[i].id])continue;
		if(e[i].type==2){
			ans3++;
			for(int j = lst+1;j<i;j++){
				ba[e[j].id] = 1;
			}
			lst = i;
		}
	}
	cout<< ans1 << " "<< ans2+(m-ans3)<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	for(int i = 1;i<=T;i++){
		pro();
	}
	return 0;
}