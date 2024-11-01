#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<utility>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define int long long
using namespace std;
const int maxn=1e5+10;
const double eps=1e-6;
int n,m,L,V;
struct node{
	double d,v,a;
}c1[maxn],c2[maxn];
int p[maxn];
bool mark[maxn];
int tot1,tot2,ans1,ans2;
pii s[maxn];
inline double cal(double x,double v0,double a){
	if(v0*v0+2*a*x<0){
		return 2147483647;
	}
	return sqrt(v0*v0+2*a*x);
}
inline bool check1(double v_cur){
	if(v_cur<=V){
		return true;
	}
	return false;
}
inline bool cmp(pii x,pii y){
	return x.fi>y.fi;
}
inline void init(){
	for(int i=1;i<=tot1;i++){
		double d=c1[i].d,v=c1[i].v,a=c1[i].a;
		if(cal(p[m]-d,v,a)<=V){
			continue;
		}
		s[i].se=m;
		ans1++;
		int l=1,r=m;
		while(l<r){
			int mid=(l+r)>>1;
			if(p[mid]<d){
				l=mid+1;
			}else{
				r=mid;
			}
		}
		int left=l,right=m;
		while(left<right){
			int mid=(left+right)>>1;
			double v_cur=cal(p[mid]-d,v,a);
			if(check1(v_cur)){
				left=mid+1;
			}else{
				right=mid;
			}
		}
		s[i].fi=left;
	}
	for(int i=1;i<=tot2;i++){
		double d=c2[i].d,v=c2[i].v,a=c2[i].a;
		int l=1,r=m;
		while(l<r){
			int mid=(l+r)>>1;
			if(p[mid]<d){
				l=mid+1;
			}else{
				r=mid;
			}
		}
		if(cal(p[l]-d,v,a)<=V){
			continue;
		}
		ans1++;
		s[i+tot1].fi=l;
		int left=l,right=m;
		while(left<right){
			int mid=(left+right)>>1;
			double v_cur=cal(p[mid]-d,v,a);
			if(check1(v_cur)){
				right=mid-1;
			}else{
				left=mid;
			}
		}
		s[i+tot1].se=right;
	}
	return;
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		memset(mark,false,sizeof(mark));
		tot1=0;
		tot2=0;
		ans1=0;
		ans2=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			double d,v,a;
			cin>>d>>v>>a;
			if(a>=0){
				c1[++tot1].d=d*1.0;
				c1[tot1].v=v*1.0;
				c1[tot1].a=a*1.0;
			}else{
				c2[++tot2].d=d*1.0;
				c2[tot2].v=v*1.0;
				c2[tot2].a=a*1.0;
			}
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		sort(p+1,p+m+1);
		/*
		for(int i=1;i<=tot1;i++){
			cout<<c1[i].d<<" "<<c1[i].v<<" "<<c1[i].a<<endl;
		}
		for(int i=1;i<=tot2;i++){
			cout<<c2[i].d<<" "<<c2[i].v<<" "<<c2[i].a<<endl;
		}
		*/
		init();
		/*
		for(int i=1;i<=n;i++){
			cout<<s[i].fi<<' '<<s[i].se<<endl;
		}
		*/
		sort(s+1,s+n+1,cmp);
		int idx=2147483647;
		for(int i=1;i<=n;i++){
			if(idx>=s[i].fi&&idx<=s[i].se){
				continue;
			}
			ans2++;
			idx=s[i].se;
		}
		cout<<ans1<<' '<<ans2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
