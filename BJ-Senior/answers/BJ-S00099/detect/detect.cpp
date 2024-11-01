#include<iostream>
#include<algorithm>
#include<fstream>
#include<cstring>
using namespace std;
const int N=100010,M=200010;
const double Lim=1e-6;
double p[N];
struct Car{
	int d,v,a;
	double l,r;
}cr[N];
int to[M],ne[M],h[N],w[M],idx;
int f[N];
inline void add(int a,int b,int c){
	to[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(f,0,sizeof f);
		memset(h,-1,sizeof h);
		idx=0;
		int n,m,l,v;
		scanf("%d%d%d%d",&n,&m,&l,&v);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&cr[i].d,&cr[i].v,&cr[i].a);
		for(int i=1;i<=m;i++)
			scanf("%lf",&p[i]);
		int res=0;
		for(int i=1;i<=n;i++){
			auto t=cr[i];
			if(t.a==0){
				t.l=t.d;
				if(t.v>v)
					t.r=l;
				else
					t.r=t.l-Lim;
			}
			else if(t.a>0){
				t.r=l;
				if(t.v>v)
					t.l=t.d;
				else
					t.l=t.d+((double)v*v-t.v*t.v)/2/t.a+Lim;
			}
			else{
				t.l=t.d;
				if(t.v<=v)
					t.r=t.d-Lim;
				else
					t.r=t.d+((double)v*v-t.v*t.v)/2/t.a-Lim;
			}
			//printf("%.6lf %.6lf\n",t.l,t.r);
			int nl=lower_bound(p+1,p+1+m,t.l)-p;
			int nr=upper_bound(p+1,p+1+m,t.r)-p-1;
			//printf("%d %d\n",nl,nr);
			if(nl>nr)
				continue;
			res++;
			add(nl-1,nr,1);
		}
		for(int i=0;i<m;i++)
			add(i,i+1,0);
		for(int u=0;u<m;u++)
			for(int i=h[u];~i;i=ne[i]){
				int v=to[i];
				f[v]=max(f[v],f[u]+w[i]);
			}
		printf("%d %d\n",res,m-f[m]);
	}
	return 0;
}