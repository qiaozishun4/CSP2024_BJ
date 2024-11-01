#include <bits/stdc++.h>
using namespace std;
struct zhr{
	long long x,y;
}z[100005];
long long T,n,m,L,V,d[100005],v[100005],a[100005],p[100005]={-1},a1,a2,ith,x;
bool c(zhr z1,zhr z2){
	return z1.y<z2.y||z1.y==z2.y&&z1.x<z2.x;
}
int f(long long y){
	int l=0,r=m,mid=(m+1)/2;
	for(;l<r;mid=(l+r+1)/2)
		p[mid]<=y?l=mid:r=mid-1;
	return l;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&T);
	for(;T;T--,a1=0,a2=0,ith=0){
		scanf("%lld %lld %lld %lld",&n,&m,&L,&V);
		for(int i=1;i<=n;i++)
			scanf("%lld %lld %lld",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;i++)
			scanf("%lld",&p[i]);
		for(int i=1;i<=n;i++){
			if(a[i]>=0){
				if(v[i]>V&&d[i]<=p[m]){
					a1++;
					z[++ith]={d[i],L};
				}
				else if(v[i]==V&&a[i]>0&&d[i]<p[m]){
					a1++;
					z[++ith]={d[i]+1,L};
				}
				else if(v[i]<V&&a[i]>0&&v[i]*v[i]+2*a[i]*(p[m]-d[i])>V*V){
					a1++;
					z[++ith]={d[i]+(V*V-v[i]*v[i])/(2*a[i])+1,L};
				}
			}
			else if(v[i]>V&&p[f(d[i]+((v[i]*v[i]-V*V)%(-a[i]-a[i])?(v[i]*v[i]-V*V)/(-a[i]-a[i]):((v[i]*v[i]-V*V)/(-a[i]-a[i])-1)))]>=d[i]){
				a1++;
				z[++ith]={d[i],d[i]+((v[i]*v[i]-V*V)%(-a[i]-a[i])?(v[i]*v[i]-V*V)/(-a[i]-a[i]):((v[i]*v[i]-V*V)/(-a[i]-a[i])-1))};
			}
		}
		sort(z+1,z+1+ith,c);
		for(int i=1,j=0;i<=ith;i++)
			if(p[j]<z[i].x){
				a2++;
				j=f(z[i].y);
			}
		printf("%lld %lld\n",a1,m-a2);
	}
	return 0;
}