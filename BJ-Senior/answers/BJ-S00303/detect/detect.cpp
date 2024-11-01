#include<bits/stdc++.h>
using namespace std;
int t,n,m;
bool mark[100005];
bool v[100005];
long double L,V,check;
struct car{
	long double d,v,a;
	int ws,we;
}c[100005];
long double p[100005];
bool w[1000005];
int faster,stop;
int find(long double w){
	int l=1,r=m,mid=(l+r)/2;
	while(l<r){
		if(p[mid]<w){
			l=mid+1;
		}
		else{
			r=mid;
		}
		mid=(l+r)/2;
	}
	return r;
}
void dfs(int w,int state){
	if(w==n+1){
		for(int i=1;i<=n;i++){
			if(v[i])continue;
			if(c[i].a>0&&)
		}
	}
	c[w]=state;
	dfs(w+1,0);
	dfs(w+1,1);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(v,0,sizeof v);
		faster=0,stop=0;
		scanf("%d%d%Lf%Lf",&n,&m,&L,&V);
		for(int i=1;i<=n;i++)
			scanf("%Lf%Lf%Lf",&c[i].d,&c[i].v,&c[i].a);
		for(int i=1;i<=m;i++){
			scanf("%Lf",&p[i]);
		}
		for(int i=1;i<=n;i++){
			c[i].ws=find(c[i].d);
		}
		//input&chuli
		for(int i=1;i<=n;i++){
			if(c[i].v<=V&&c[i].a<=0.0){v[i]=1;continue;}
			if(c[i].a==0.0&&c[i].v>V){
				if(c[i].d<=p[m])faster++;
				else v[i]=1;
				continue;
			}
			check=c[i].d+((V*V)-(c[i].v*c[i].v))/(c[i].a*2.0);
			if(check<=p[m]&&c[i].a>0.0)faster++,c[i].ws=find(check);
			if(check>=p[c[i].ws]&&c[i].a<0.0)faster++,c[i].ws=find(check);;
		}
		memset(mark,0,sizeof mark);
		dfs(1,1);
		memset(mark,0,sizeof mark);
		dfs(1,0);
		printf("%d %d\n",faster,stop);
	}
	return 0;
}