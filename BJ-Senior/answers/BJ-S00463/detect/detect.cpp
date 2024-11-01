#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
#define REPG(i,h,x) for(int i=h[x];~i;i=edge[i].next)
#define CLR(a,x) memset(a,x,sizeof(a))
#define pii pair<int,int>

const int N=1e5+5,VL=1e6+5,VV=1e6;
int T,n,m,L,V,p[N],sum[VL],ans1;
bool ok[N],ok2[30];
struct line{int l,r;}li[N],li2[N];
inline void solve(){
	CLR(sum,0),CLR(ok,0),ans1=0;
	scanf("%d%d%d%d",&n,&m,&L,&V);
	for(int i=1,st,v,A;i<=n;i++){
		scanf("%d%d%d",&st,&v,&A);
		if(A>=0&&v>V) li[i]={st,L};
		else if(A<=0&&v<=V) li[i]={st,st-1};
		else{
			ll fz=(ll)V*V-(ll)v*v;
			if(A>0){
				ll delta=(ll)ceil((double)(fz)/(double)(A*2));
				if(delta==fz/(ll)A/2) delta++;
				if((ll)st+delta>L) li[i]={L+1,L};
				else li[i]={st+delta,L};
			}else{
				ll delta=fz/(ll)A/2;
				li[i]={st,min((ll)st+delta,(ll)L)};
			}
		}
	}
	for(int i=1;i<=m;i++) scanf("%d",&p[i]),sum[p[i]]=1;
	for(int i=1;i<=L;i++) sum[i]+=sum[i-1];
	for(int i=1;i<=n;i++) if((li[i].l<=li[i].r)&&(sum[li[i].r]-sum[li[i].l-1])) ok[i]=true,ans1++;
	// for(int i=1;i<=n;i++) printf("[%d,%d]\n",li[i].l,li[i].r);
	printf("%d ",ans1);
	if(m<=20){
		int cnt=0,ans=INF;
		for(int i=1;i<=n;i++) if(ok[i]) li2[++cnt]=li[i];
		for(int S=0;S<(1<<m);S++){
			CLR(ok2,0);bool flag=true;
			for(int j=1;j<=m;j++){
				if(!((S>>(j-1))&1)) continue;
				for(int k=1;k<=cnt;k++) if(li2[k].l<=p[j]&&p[j]<=li2[k].r) ok2[k]=true;
			}
			for(int i=1;i<=cnt;i++) if(!ok2[i]){flag=false;break;}
			if(!flag) continue;
			ans=min(ans,__builtin_popcount(S));
		}
		printf("%d\n",m-ans);
		return;
	}
	for(int i=1;i<=n;i++) if(ok[i]&&li[i].r!=L){puts("Oops");return;}
	printf("%d\n",ans1?m-1:m);
	// int cnt=0;
	// for(int i=1;i<=n;i++) if(ok[i]) li2[++cnt]=li[i];
	// sort(li2+1,li2+1+cnt,[](line a,line b){return a.l<b.l;});
	
}
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	// printf("%d\n",(int)ceil(101.0/100.0));return 0;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}