#include <bits/stdc++.h>
using namespace std;
int n,m,ans1,last=-1,cnt,q;
long long d[100005],v[100005],a[100005],l,V,p[100005],f[100005];
long long l1;
long long f1(int v,int v2,int a){
	return (1ll*v*v-(1ll*v2*v2))/(1ll*2*a);
}
struct node{
	long long st,ed,i;
}s[100005];
bool cmp(node x,node y){
	return x.ed<y.ed;
}
int find(long long x){
	int l=1,r=m,bk;
	while(l<r){
		int mid=(l+r)>>1;
		if(x>=p[mid]){
			bk=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	if(p[l]<=x) bk=l;
	return p[bk];
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&q);
	while(q--){
		ans1=0,cnt=0,last=-100000;
		scanf("%d%d%lld%lld",&n,&m,&l,&V);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%lld",&p[i]);
		}
		for(int i=1;i<=n;i++){
			if(a[i]>0){
				if(v[i]>V && p[m]>=d[i]){
					ans1++;
					f[ans1]=i;
				}else{
					l1=f1(V,v[i],a[i]);
					if(1ll*d[i]+l1+1ll*1<=1ll*p[m] &&  d[i]<p[m]){
						ans1++;
						f[ans1]=i;
					}
				}
				
			}else if(a[i]<0){
				l1=f1(V,v[i],a[i]);
				if(l1<0) continue;
				if((1ll*V*V-(1ll*v[i]*v[i]))%(1ll*2*a[i])==0) l1=l1-1;
				if(d[i]==find(d[i]) && v[i]<=V) continue; 
				if(find(l1+d[i])>=d[i]){
					ans1++;
					f[ans1]=i;
				}else if(d[i]==find(d[i]) && V<v[i]){
					ans1++;
					f[ans1]=i;
				}
			}else{
				if(v[i]>V && d[i]<=p[m]){
					ans1++;
					f[ans1]=i;
				}
			}
		}
		cout<<ans1<<' ';
		for(int i=1;i<=ans1;i++){
			s[i].i=f[i];
			if(a[f[i]]<0){
				l1=f1(V,v[f[i]],a[f[i]]);
				if((1ll*V*V-(1ll*v[f[i]]*v[f[i]]))%(1ll*2*a[f[i]])==0) l1=l1-1;
				s[i].ed=d[f[i]]+l1;
				s[i].st=d[f[i]];
			}else if(a[f[i]]>0){
				s[i].ed=l;
				l1=f1(V,v[f[i]],a[f[i]]);
				s[i].st=l1+1+d[f[i]];
			}else{
				s[i].st=d[f[i]];
				s[i].ed=l;
			}
			
		}
		sort(s+1,s+1+ans1,cmp);
		for(int i=1;i<=ans1;i++){
			if(s[i].ed>=last && s[i].st<=last){
				continue;
			}
			cnt++;
			last=find(s[i].ed);
		}
		cout<<m-cnt<<endl;
	}
}
