#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,m,L,V,d[N],v[N],a[N],p[N];
double eps=1e-6;
bool Chk(int x,int mid){
	if(sqrt(v[x]*v[x]+2*a[x]*mid)-V>-eps) return 1;// 1 = chaosu
	return 0;
}
struct node{
	double l,r;
}st[N];
bool cmp(node n1,node n2){
	if(n1.r<n2.r) return 1;
	else if(n1.r==n2.r&&n1.l<n2.l) return 1;
	return 0;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int tt=1;tt<=T;tt++){
		int tot=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		int ans=0,mx=0;
		for(int i=1;i<=m;i++) cin>>p[i],mx=max(mx,p[i]);
		for(int i=1;i<=n;i++){
			if(!a[i]){
				if(v[i]<=V||d[i]>mx);
				else{
					ans++;
					for(int j=1;j<=m;j++){
						if(p[j]<=d[i]){
							st[++tot].l=p[j],st[tot].r=L;
							break;
						}
					}
				}
			}else if(a[i]>0){
				for(int j=1;j<=m;j++){
					if(p[j]<d[i]) continue;
					if(Chk(i,p[j]-d[i])){
						st[++tot].l=p[j],st[tot].r=L;
						ans++;
						break;
					}
				}
			}else{
				int l1=-1,r1=-1;
				for(int j=1;j<=m;j++){
					if(v[i]*v[i]+2*a[i]*(p[j]-d[i])<0) break;
					if(p[j]<d[i]) continue;
					if(Chk(i,p[j]-d[i])){
						ans++;
						break;
					}
				}
				for(int j=1;j<=m;j++){
					//if(v[i]*v[i]+2*a[i]*(p[j]-d[i])<0) break;
					if(p[j]<d[i]) continue;
					if(Chk(i,p[j]-d[i])){
						if(l1==-1) l1=p[j];
						/*
						st[++tot].l=p[j];
						st[tot].r=(d[i]+1.0*(-v[i]*v[i])/(2.0*a[i]));
						st[tot].r=(st[i].r>L)?L:st[i].r;
						st[tot].r=L-st[tot].r;
						break;
						*/
					}else{
						r1=p[j-1];
					}
				}
				r1=-1;
				for(int j=1;j<=m;j++){
					//if(v[i]*v[i]+2*a[i]*(p[j]-d[i])<0) break;
					if(p[j]<d[i]) continue;
					if(Chk(i,p[j]-d[i])){;
					}else{
						r1=p[j-1];
						break;
					}
				}
				st[++tot].l=l1;
				st[tot].r=r1;
			}
		}
		sort(st+1,st+tot+1,cmp);
		int lasp=-1,ansss=0;
		for(int i=1;i<=tot;i++){
			if(st[i].l<=lasp) continue;
			lasp=st[i].r;
			ansss++;
		}
		cout<<ans<<" "<<tot-ansss+1<<'\n';
	}
	return 0;
}