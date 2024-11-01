#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+7;

struct node{
	int l,g;
	bool operator <(const node &a)const{
		return a.l<l;
	}
}node_u;

ll T,n,m,L,V,d[N],v[N],a[N],p[N],cnt,sum,VV,b[N],o,r[N],last;
int wz;
bool vis1,vis2,vis3,vis[N];
priority_queue<node>q;

bool check(int x,ll L){
	wz=0;
	for(int i=1;i<=m;i++){
		if(d[x]<=p[i]){
			wz=i;
			break;
		}
	}
	r[x]=min(L,d[x]+(VV-v[x]*v[x])/(2*a[x]));
	//cout<<p[wz]<<" "<<r[x]<<" "<<L<<endl;
	if(wz>0&&r[x]>=p[wz])
		return true;
	return false;
}
bool cmp(int x,int y){
	return d[x]<d[y];
}
int bj(node x){
	for(int i=1;i<=m;i++){
		if(x.g>p[i]){
			return i-1;
		}
	}
	return 0;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		vis1=0;
		vis2=0;
		vis3=0;
		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		VV=V*V;
		cnt=0;
		sum=0;
		last=0;
		memset(vis,0,sizeof(vis));
		o=1;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
			if(a[i]!=0)
				vis1=1;
			if(a[i]<=0)
				vis2=1;
			if(a[i]>=0)
				vis3=1;
		}
		for(int i=1;i<=m;i++){
			scanf("%lld",&p[i]);
			sort(p+1,p+m+1);
		}
		if(!vis1){
			for(int i=1;i<=n;i++){
				if(v[i]>V&&d[i]<=p[m]){
					cnt++;
				}
			}
			printf("%lld ",cnt);
			printf("%lld\n",m-1);
		}else if(!vis2){
			for(int i=1;i<=n;i++){
				if(v[i]<=V){
					d[i]+=(VV-v[i]*v[i])/(2*a[i]);
					if(d[i]<p[m]){
						cnt++;
					}else if(d[i]==p[m]){
						if((VV-v[i]*v[i])%(2*a[i])==0){
							cnt++;
						}
					}
				}else if(d[i]<=p[m]){
					cnt++;
				}
			}
			printf("%lld ",cnt);
			printf("%lld\n",m-1);
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]>=0&&v[i]>V&&d[i]<=p[m]){
					cnt++;
					b[o]=i;
					r[i]=L;
					o++;
					continue;
				}
				if(a[i]>0){
					r[i]=d[i]+(VV-v[i]*v[i])/(2*a[i]);
					if(r[i]<p[m]||(r[i]==p[m]&&(VV-v[i]*v[i])%(2*a[i])==0)){
						cnt++;
						b[o]=i;
						o++;
					}
					continue;
				}
				if(a[i]<0&&v[i]>=V){
					if(check(i,L)){
						cnt++;
						b[o]=i;
						o++;
					}
					continue;
				}
			}
			sort(b+1,b+1+cnt,cmp);
			for(int i=1;i<=cnt;i++){
				for(int j=1;j<i;j++){
					if(!vis[j]&&r[j]>r[i]){
						vis[j]=1;
					}
				}
			}
			for(int i=1;i<=cnt;i++){
				if(!vis[i]){
					node_u.l=d[b[i]];
					node_u.g=r[b[i]];
					q.push(node_u);
				}
			}
			while(!q.empty()){
				node_u=q.top();
				q.pop();
				if(last<node_u.l){
					last=bj(node_u);
					sum++;
				}
			}
			printf("%lld %lld\n",cnt,m-sum);
		}
	}
	return 0;
}
