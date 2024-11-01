#include<bits/stdc++.h>
#define lch (p<<1)
#define rch (p<<1|1)
using namespace std;
typedef long long ll;
bool st;
const int N=100005,K=17,MX=(1<<18),inf=0x3f3f3f3f;
int T,n,m,k,c[N],a[N],ori[N],all,x[4],lg2[MX],pw[20];
int b[MX],nwn,g[MX];
string d[20];
bool ed;
void dfs(int p){
	if(lg2[p]==k){g[p]=min(k,b[p-pw[k]+1]);return;}
	dfs(lch),dfs(rch);
	int r=k-lg2[p],p1,p2;
	if(d[lg2[p]][p-pw[lg2[p]]]=='0')	p1=lch,p2=rch;
	else	p1=rch,p2=lch;
	if(g[p1]==-1)	g[p]=min(r,g[p2]);
	else	g[p]=g[g[p1]>=r?p1:p2];
}
bool check(int p,int v){
	if(p==1)	return 1;
	int fa=(p>>1),r=k-lg2[fa],p1=(fa<<1),p2=p1+1;
	if(d[lg2[fa]][fa-pw[lg2[fa]]]=='1')	swap(p1,p2);
	if(p==p1){
		if(v>=r)	return check(fa,v);
		else	return 0;
	}else{
		if(g[p1]<r)	return check(fa,v);
		else	return 0;
	}
}
ll solve(int len){
	nwn=len,k=0;while((1<<k)<len)k++;
	for(int i=1;i<=pw[k];i++)	b[i]=(i<=len?a[i]:-1);
	dfs(1);ll ans=0;
	for(int i=1;i<=pw[k];i++)if(check(pw[k]+i-1,i<=len?b[i]:k))ans+=i;
	return ans;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m,pw[0]=1;
	while((1<<k)<n)k++;all=(1<<k);
	for(int i=1;i<=k;i++)	pw[i]=pw[i-1]<<1;
	for(int i=0;i<=k;i++)	lg2[pw[i]]=i;
	for(int i=1;i<MX;i++)if(!lg2[i])lg2[i]=lg2[i-1];
	for(int i=1;i<=n;i++)	cin>>ori[i];
	for(int i=1;i<=m;i++)	cin>>c[i];
	for(int i=k-1;~i;i--)	cin>>d[i];
	cin>>T;
	while(T--){
		for(int i=0;i<4;i++)	cin>>x[i];
		for(int i=1;i<=n;i++)	a[i]=ori[i]^x[i%4];
		ll res=0;
		for(int i=1;i<=m;i++)	res^=i*solve(c[i]);
		cout<<res<<'\n';
	}
	return 0;
}