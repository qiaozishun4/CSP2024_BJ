#include<iostream>
#include<deque>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e5+50,M=1e6+50;
typedef long long ll;
struct node{
	ll l,r;
	bool operator<(const node &y) const{
		return r>y.r;
	}
}c[N];
bool cmp(node x,node y){
	if(x.l==y.l) return x.r<y.r;
	return x.l<y.l;
}
deque<ll> dq;
priority_queue<node> pq;
ll dp[N],d[N],v[N],a[N],T,n,m,L,V,m1,pos[N];
ll s[M];
bool count(int x,int y){
	if(x>0) return s[y]-s[x-1];
	else return (s[y]-s[x]+s[0])>0;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int i,j;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		for(i=1;i<=n;i++) 
			scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
		for(i=1;i<=m;i++){
			scanf("%lld",&pos[i]);
			s[pos[i]]++;
		}
		for(i=1;i<=L;i++)
			s[i]+=s[i-1];
		for(i=1;i<=n;i++){
			if(a[i]<0){
				if(v[i]<V) continue;
				ll l=d[i],r=L;
				while(r-l>5){
					ll mid=(l+r)>>1;
					if(v[i]*v[i]+2*a[i]*(mid-d[i])>V*V) l=mid;
					else r=mid; 
				}
				ll p=-1;
				for(j=r;j>=l;j--){
					if(v[i]*v[i]+2*a[i]*(j-d[i])>V*V){
						p=j;
						break;
					}
				}
				if(p!=-1&&count(d[i],p)){
					m1++;
					c[m1].l=d[i];
					c[m1].r=p;
				}
			}
			else if(a[i]>0){
				ll l=d[i],r=L;
				while(r-l>5){
					ll mid=(l+r)>>1;
					if(v[i]*v[i]+2*a[i]*(mid-d[i])>V*V) r=mid;
					else l=mid; 
				}
				ll p=-1;
				for(j=l;j<=r;j++)
					if(v[i]*v[i]+2*a[i]*(j-d[i])>V*V){
						p=j;
						break;
					}
				if(p!=-1&&count(p,L)){
					m1++;
					c[m1].l=p;
					c[m1].r=L;
				}
			}
			else if(a[i]==0){
				if(v[i]<=V||(!count(d[i],L))) continue;
				m1++;
				c[m1].l=d[i];
				c[m1].r=L;
			}
		}
		sort(pos+1,pos+1+m);
		sort(c+1,c+1+m1,cmp);
		pos[0]=-1;
		dq.push_back(0);
		for(i=1;i<=m;i++) dp[i]=1e9;
		
		ll r=1,p=-1;
		for(i=1;i<=m;i++){
			while(r<=m1&&c[r].l<=pos[i]){
				pq.push(c[r]);
				r++;
			}
			while(!pq.empty()&&pq.top().r<pos[i]){
				p=max(p,pq.top().l);
				pq.pop();
			}
			while(!dq.empty()&&pos[dq.front()]<p)
				dq.pop_front();
			if(!dq.empty()){
				dp[i]=dp[dq.front()]+1;
				//cout<<i<<' '<<dp[i]<<' '<<dq.front()<<endl;
				while(!dq.empty()&&dp[dq.back()]>=dp[i])
					dq.pop_back();
				dq.push_back(i);
				
			}
		}
		ll ans=m;
		for(i=1;i<=m;i++) {
			if(pos[i]>=c[m1].l)
				ans=min(ans,dp[i]);
		}
		if(m1==0) ans=0;
		printf("%lld %lld\n",m1,m-ans);
		for(i=1;i<=n;i++)
			d[i]=v[i]=a[i]=0;
		for(i=1;i<=m;i++) dp[i]=pos[i]=0;
		for(i=0;i<=L;i++) s[i]=0;
		for(i=1;i<=m1;i++) c[i].l=c[i].r=0;
		while(!dq.empty()) dq.pop_back();
		while(!pq.empty()) pq.pop();
		n=m=L=V=m1=0;
	}
	return 0;
}
