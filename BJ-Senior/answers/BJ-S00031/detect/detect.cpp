#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,MAXL=1e6+5;
struct Over{
	long long ll,rr;
} o[N];
bool cmp1(Over xx,Over yy){
	return xx.ll<yy.ll;
}
bool cmp2(Over xx,Over yy){
	return xx.rr<yy.rr;
}
int d[N],v[N],a[N],leftp[MAXL],rightp[MAXL],p[N];
bool ifp[MAXL];
int n,m,V,tot;
int cnt;
long long L;
void init(){
	tot=0;
	cnt=0;
	for(int i=0;i<=MAXL-4;i++){
		ifp[i]=0;
		leftp[i]=-1;
		rightp[i]=-1;
	}
	for(int i=0;i<=N-4;i++){
		d[i]=0;v[i]=0;a[i]=0;p[i]=0;
		o[i].ll=o[i].rr=0;
	}
}
Over Find(int dd,int vv,int aa){
	Over ret;
	ret.ll=ret.rr=-1;
	if(vv<=V&&aa<=0) return ret;
	if(aa==0){
		ret.ll=dd;ret.rr=L;
		return ret;
	}
	long long fz=(long long)abs(vv-V)*(vv+V);
	long long fm=abs(aa)*2;
	if(aa<0){
		ret.ll=dd;
		if(fz+fm*dd>L*fm){ret.rr=L;return ret;}
		ret.rr=(fz-1)/fm+dd;
		//ret.rr=min(L,(fz-1)/fm+dd);
		return ret;
	}
	if(vv>V){ret.ll=dd;ret.rr=L;return ret;}
	if(fz+fm*dd>=L*fm){return ret;}
	ret.rr=L;
	ret.ll=fz/fm+1+dd;
	return ret;
}
void run(){
	for(int i=1;i<=n;i++) ifp[p[i]]=true;
	for(int i=0;i<=L;i++){
		if(i==0&&(!ifp[i])){leftp[i]=-1;continue;}
		if(ifp[i]) leftp[i]=i;
		else leftp[i]=leftp[i-1];
	}
	for(int i=L;i>=0;i--){
		if(ifp[i]) rightp[i]=i;
		else rightp[i]=rightp[i+1];
	}
	Over now;
	for(int i=1;i<=n;i++){
		now=Find(d[i],v[i],a[i]);
		if(now.ll!=-1&&now.rr!=-1){
			if(rightp[now.ll]<=leftp[now.rr]&&rightp[now.ll]!=-1&&leftp[now.rr]!=-1){
				tot++;
				o[tot]=now;
				//printf("%d\n",i);
			}
		}
	}
	//for(int i=1;i<=tot;i++) printf("%d %d\n",o[i].ll,o[i].rr);
	sort(o+1,o+tot+1,cmp2);
	int search_last_p=-1;
	for(int i=1;i<=tot;i++){
		if(search_last_p<o[i].ll){
			cnt++;
			search_last_p=leftp[o[i].rr];
		}
	}
	//if(search_last_p<s[n].ll) cnt++;
	printf("%d %d\n",tot,m-cnt);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int j=1;j<=T;j++){
		init();
		scanf("%d%d%lld%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;i++) scanf("%d",&p[i]);
		run();
	}
	return 0;
}