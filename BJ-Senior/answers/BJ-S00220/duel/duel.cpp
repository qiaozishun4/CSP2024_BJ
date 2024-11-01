#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
int a[100010];
int t[400010];
int f[400010];
void pushup(int k){
	t[k]=t[k<<1]+t[k<<1|1];
	if(t[k<<1]) f[k]=f[k<<1];
	else if(t[k<<1|1]) f[k]=f[k<<1|1];
	else f[k]=0;
}
void update(int k,int l,int r,int p,int v){
	if(l==r){
		t[k]+=v;if(t[k]) f[k]=l;else f[k]=0;return;
	}
	int mid=(l+r)>>1;
	if(p<=mid) update(k<<1,l,mid,p,v);
	else update(k<<1|1,mid+1,r,p,v);
	pushup(k);
}
int query(int k,int l,int r,int L,int R){
	if(L>R) return 0;
	if(L<=l&&r<=R) return f[k];
	int mid=(l+r)>>1,tmp=0;
	if(L<=mid) tmp=query(k<<1,l,mid,L,R);
	if(mid<R&&!tmp) tmp=query(k<<1|1,mid+1,r,L,R);
	return tmp;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],m=max(a[i],m);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) update(1,1,m,a[i],1);
	int ans=0;
	for(int i=1;i<=n;i++){
		int cnt=query(1,1,m,1,a[i]-1);
		if(!cnt) continue;
		ans++;update(1,1,m,cnt,-1);
	}
	cout<<n-ans<<"\n";
	return 0;
}
