#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=1e6+10;
struct node{
	int dist,stv,pv;
}a[N];
int d[N],f[N];
int t,n,m,l,v,ans_cnt,xmax=0;
map<int,int> mp;
void dfs(int cur,int ge){
	if(cur>ge){
		mp.clear();
		for(int i=1;i<=ge;i++) mp[d[f[i]]]++;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i].stv>v&&mp[a[i].dist]>0){
				cnt++;
				continue;
			}
			if(a[i].stv<=v&&a[i].pv<=0) continue;
			int sumv=a[i].stv,cntd=a[i].dist;
			while(sumv>0&&cntd<=l){
				cntd++;
				sumv+=a[i].pv;
				if(mp[cntd]>0&&sumv>v){
					cnt++;
					break;
				}
			}
		}
		if(ge==m) ans_cnt=cnt;
		else if(cnt==ans_cnt) xmax=max(xmax,m-ge);
		return ;
	}
	for(int i=f[cur-1]+1;i<=m;i++){
		f[cur]=i;
		dfs(cur+1,ge);
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&l,&v);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].dist,&a[i].stv,&a[i].pv);
		for(int i=1;i<=m;i++) scanf("%d",&d[i]);
		for(int i=m;i>=0;i--) dfs(1,i);
		printf("%d %d\n",ans_cnt,xmax);
	}
	return 0;
}
