#include<bits/stdc++.h>
#define ll long long
#define I 1e18
using namespace std;
const int N=200005;
int _,n,a[N],b[N],p[N];
ll sp[N],dp[N][2],T[N<<2];
void update(int k,int l,int r,int x,ll v){
	if(l==r) T[k]=max(T[k],v);
	else{
		int mid=(l+r)>>1;
		if(x<=mid) update(k<<1,l,mid,x,v);
		else update(k<<1|1,mid+1,r,x,v);
		T[k]=max(T[k<<1],T[k<<1|1]);
	}
}
ll query(int k,int l,int r,int L,int R){
	if(L<=l && r<=R) return T[k];
	int mid=(l+r)>>1;
	ll ans=-I;
	if(L<=mid) ans=max(ans,query(k<<1,l,mid,L,R));
	if(mid<R) ans=max(ans,query(k<<1|1,mid+1,r,L,R));
	return ans;
}
void solve(){
	for(int i=0;i<(N<<2);i++) T[i]=-I;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);b[i]=a[i];
		if(i>1) p[i]=(a[i]==a[i-1]?a[i]:0),sp[i]=sp[i-1]+p[i];
	}
	sort(a+1,a+n+1);
	int m=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=n;i++) b[i]=lower_bound(a+1,a+m+1,b[i])-a;
	for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=-I;
	dp[1][1]=0;
	update(1,0,n,0,dp[1][1]);
	for(int i=2;i<=n;i++){
		dp[i][0]=max(dp[i-1][1]+p[i],dp[i-1][0]+p[i]);
		ll q1=query(1,0,n,b[i],b[i]),q2=max(query(1,0,n,0,b[i]-1),query(1,0,n,b[i]+1,n));
		if(q1!=-I) dp[i][1]=max(dp[i][1],(ll)q1+a[b[i]]);
		if(q2!=-I) dp[i][1]=max(dp[i][1],(ll)q2);
		if(max(q1,q2)!=-I) dp[i][1]+=sp[i-1];
		update(1,0,n,b[i-1],dp[i][1]-sp[i]);
	}
	printf("%lld\n",max(dp[n][0],dp[n][1]));
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&_);
	while(_--) solve();
	return 0;
}
