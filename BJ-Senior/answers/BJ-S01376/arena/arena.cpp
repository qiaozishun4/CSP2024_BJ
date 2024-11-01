
#include<bits/stdc++.h>
using namespace std;
const int NR=(1<<17)+10;
#define ll long long
int N,n,m,k,v[NR],a[NR],nxt[NR],c[NR],f[NR],opt[18][NR],dfn[NR],idx[NR],S,pre[NR];
ll ans[NR],res;
char str[NR];
#define pb emplace_back
vector<int>qbuc[NR];

void dfs(int id,int col){
	if(!col){
		dfn[id]=S;idx[S]=id;S++;
		return;
	}
	int tmp=opt[col][id>>col];
	if(!tmp){
		dfs(id,col-1);
		dfs(id|(1<<(col-1)),col-1);
	}
	else{
		dfs(id|(1<<(col-1)),col-1);
		dfs(id,col-1);
	}
}
//nxt:id->dfn
//pre_i:the first time when i is updated by '?' 

int ex[5],L,R,lim,nowk,wxb;
inline int calc(int x,int y){return ((x>>y)<<y)+(1<<y);}
inline void add(int x){
	f[x]=1;
	if(x>=wxb||dfn[nxt[x]]>R)res+=x+1;
}
void release(int x){
	if(x>=lim||!f[x])return;
	// printf("release:%d dfn:%d %d k:%lld\n",x,dfn[x],wxb,nowk);
	if(x>=wxb){//a '?'
		for(int i=0;i<=nowk;i++){
			int tmp=idx[calc(dfn[x],i)];
			// printf("x:%d i:%d tmp:%d %d\n",x,i,tmp,calc(dfn[x],i));
			if(pre[tmp]>x||tmp>=lim)break;
			pre[tmp]=x;
			if(!f[tmp])add(tmp),release(tmp);
		}
	}
	else if(nxt[x]<lim&&!f[nxt[x]])add(nxt[x]),release(nxt[x]);
}
void solve(){
	for(int i=0;i<4;i++)cin>>ex[i];
	for(int i=0;i<N;i++){
		a[i]=min(v[i]^ex[(i+1)%4],k);
		nxt[i]=idx[calc(dfn[i],a[i])];
		// printf("i:%d nxt:%d %d\n",i,nxt[i],calc(dfn[i],a[i]));
	}
	memset(f,0,sizeof(f));
	memset(pre,0,sizeof(pre));
	int now=idx[0];res=0;wxb=N;
	lim=N;L=0;R=N-1;nowk=k;
	while(now<N){
		add(now);
		now=nxt[now];
	}
	for(int i=N-1;i;i--){//turn nxt_i to 1,2,...,k
		if(i<=lim/2){
			for(int j=0;j<=lim;j++)f[j]=pre[j]=0;
			if(opt[nowk][0]==0){
				R=L+i-1;
			}
			else{
				L=R-i+1;
			}
			int now=idx[L];res=0;
			nowk--;lim=i;wxb=i;
			// printf("-----%d %d\n",L,R);
			while(now<i){
				add(now);
				now=nxt[now];
			}
		}
		else{
			if(f[i]==1&&dfn[nxt[i]]<=R)res+=i+1;
			wxb=i;release(i);
		}
		for(int x:qbuc[i])ans[x]=res;
		// printf("i:%lld ans:%lld\n",i,res);
	}
	ll lcy=0;
	for(int i=1;i<=m;i++)lcy^=(1ll*i*ans[i]);
	cout<<lcy<<endl;
}

signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)scanf("%d",&v[i]);
	for(int i=1;i<=m;i++)scanf("%d",&c[i]),qbuc[c[i]].pb(i);
	while((1<<k)<n)k++;
	for(int i=1;i<=k;i++){
		scanf("%s",str);
		for(int j=0;j<(1<<(k-i));j++)opt[i][j]=str[j]-'0';
	}
	N=(1<<k);
	dfs(0,k);idx[N]=dfn[N]=N;
	// for(int i=0;i<N;i++)cout<<idx[i]<<' ';cout<<endl;
	int T;cin>>T;
	while(T--)solve();
	return 0;
}