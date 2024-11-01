#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int T,n,f[N],a[N];
int tree[N<<2],lazy[N<<2];
void pushup(int rt){
	tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);
}
void pushdown(int rt){
	if(lazy[rt]){
		lazy[rt<<1]+=lazy[rt];
		lazy[rt<<1|1]+=lazy[rt];
		tree[rt<<1]+=lazy[rt];
		tree[rt<<1|1]+=lazy[rt];
		lazy[rt]=0;
	}
}
void update(int rt,int left,int right,int x,int y){
	if(left<right)pushdown(rt);
	if(left==right){tree[rt]=max(tree[rt],y);return;}
	int mid=(left+right)>>1;
	if(x<=mid)update(rt<<1,left,mid,x,y);
	else update(rt<<1|1,mid+1,right,x,y);
	pushup(rt);
}
int query(int rt,int left,int right,int x){
	if(left<right)pushdown(rt);
	if(left==right)return tree[rt];
	int mid=(left+right)>>1;
	if(x<=mid)return query(rt<<1,left,mid,x);
	else return query(rt<<1|1,mid+1,right,x);
}
void solve(){
	cin>>n;int maxv=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],maxv=max(maxv,a[i]);
	fill(tree,tree+4*(maxv+1)+1,-1e18);
	fill(lazy,lazy+4*(maxv+1)+1,0);
	update(1,0,maxv,0,0);
	for(int i=2;i<=n;i++){
		int x=max(query(1,0,maxv,a[i])+a[i],tree[1]);
		if(a[i]==a[i-1])lazy[1]+=a[i];
		update(1,0,maxv,a[i-1],x);
	}
	cout<<tree[1]<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--)solve();
	//cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	return 0;
}