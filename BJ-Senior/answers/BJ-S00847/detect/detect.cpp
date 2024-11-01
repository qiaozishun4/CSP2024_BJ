#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,m,L,V;
int d[N],v[N],a[N],p[N];
struct node{
	int l,r;
}car[N];
bool operator<(node A,node B){
	return A.l==B.l?A.r<B.r:A.l<B.l;
}
int cnt;
void add_car(int l,int r){
	l=lower_bound(p+1,p+m+1,l)-p;
	r=upper_bound(p+1,p+m+1,r)-p-1;
	if(l>r)return;
	car[++cnt].l=l;
	car[cnt].r=r;
	return;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		cnt=0;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;++i)scanf("%d%d%d",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;++i)scanf("%d",&p[i]);
		for(int i=1;i<=n;++i){
			//judge over speed
			if(v[i]>V){
				if(a[i]>=0){
					add_car(d[i],L);
				}else{
					double s=(V*V-v[i]*v[i])*1.0/(2*a[i]);
					int end=d[i]+(floor(s)==s?floor(s)-1:floor(s));//end of over speed
					add_car(d[i],min(end,L));
				}
			}else if(v[i]<V){
				if(a[i]>0){
					double s=(V*V-v[i]*v[i])*1.0/(2*a[i]);
					int start=d[i]+(ceil(s)==s?ceil(s)+1:ceil(s));//start of over speed
					if(start<=L)add_car(start,L);
				}
			}else{
				if(a[i]>0){
					add_car(d[i]+1,L);
				}
			}
		}
		sort(car+1,car+cnt+1);
		int l=car[1].l,r=car[1].r,need=1;
		for(int i=2;i<=cnt;++i){
			if(car[i].l>r){
				need++;
				r=car[i].r;
			}
			l=car[i].l;
		}
		printf("%d %d\n",cnt,m-need);
	}
	return 0;
}

