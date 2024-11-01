#include<bits/stdc++.h>
using namespace std;
const int NR=1e6+10;
#define int long long
int n,m,L,lim,pos[NR],d[NR],v[NR],a[NR],minr[NR];

void solve(){
	cin>>n>>m>>L>>lim;
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
	for(int i=1;i<=m;i++)scanf("%lld",&pos[i]);
	memset(minr,999999,sizeof(minr));
	int ans1=0,ans2=0;
	for(int i=1;i<=n;i++)
		if(a[i]>0){
			if(v[i]>lim){
				int l=d[i],r=L+1;
				int p1=lower_bound(pos+1,pos+1+m,l)-pos;
				int p2=upper_bound(pos+1,pos+1+m,r)-pos-1;
				if(p1>m||p1>p2)continue;
				ans1++;minr[p1]=min(minr[p1],p2);
				// printf("-%lld %lld\n",p1,p2);
			}
			else{
				int l=d[i]+(lim*lim-v[i]*v[i]+2*a[i])/(2*a[i]),r=L+1;
				int p1=lower_bound(pos+1,pos+1+m,l)-pos;
				int p2=upper_bound(pos+1,pos+1+m,r)-pos-1;
				if(p1>m||p1>p2)continue;
				ans1++;minr[p1]=min(minr[p1],p2);
				// printf("--%lld %lld\n",p1,p2);
			}
		}
		else if(a[i]==0){
			if(v[i]>lim){
				int l=d[i],r=L+1;
				int p1=lower_bound(pos+1,pos+1+m,l)-pos;
				int p2=upper_bound(pos+1,pos+1+m,r)-pos-1;
				if(p1>m||p1>p2)continue;
				ans1++;minr[p1]=min(minr[p1],p2);
				// printf("---%lld %lld\n",p1,p2);
			}
		}
		else{
			if(v[i]>lim){
				a[i]=-a[i];
				int l=d[i],r=d[i]+(v[i]*v[i]-lim*lim+a[i]*2-1)/(2*a[i])-1;
				int p1=lower_bound(pos+1,pos+1+m,l)-pos;
				int p2=upper_bound(pos+1,pos+1+m,r)-pos-1;
				if(p1>m||p1>p2)continue;
				ans1++;minr[p1]=min(minr[p1],p2);
				// printf("----%lld %lld\n",p1,p2);
			}
		}
	for(int i=m;i>=1;i--)minr[i]=min(minr[i],minr[i+1]);
	int now=minr[1];
	while(now<=m)ans2++,now=minr[now+1];
	cout<<ans1<<" "<<m-ans2<<endl;
}

signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}