#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{LL l,r;}e[100010];
LL n,m,nn,k,ans1,ans2;
LL a[100010],b[100010],c[100010];
LL t[1000010],d[100010],ltp;
LL st[100010],h;
int find1(int x){
	int l=1,r=m;
	while(l<r){
		int mid=(l+r)>>1;
		if(d[mid]>=x) r=mid;
		else l=mid+1;
	}return l;
}
int find2(int x){
	int l=1,r=m;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(d[mid]<=x) l=mid;
		else r=mid-1;
	}return r;
}
bool cmp(A x,A y){return x.l<y.l;}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;cin>>T;
	while(T--){
		cin>>n>>m>>nn>>k;ltp=ans1=ans2=0;
		for(int i=0;i<=nn+1;i++) t[i]=0;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		for(int i=1;i<=m;i++) cin>>d[i],t[d[i]+1]++;
		for(int i=1;i<=nn+1;i++) t[i]+=t[i-1];
		sort(d+1,d+m+1);
		for(int i=1;i<=n;i++){
			if(c[i]<=0&&b[i]<=k) continue;
			if(c[i]==0&&t[nn+1]-t[a[i]]==0) continue;
			if(c[i]==0){ans1++,ltp++;e[ltp].l=a[i],e[ltp].r=nn;continue;}
			if(c[i]>0){
				if(b[i]>k){
					LL x=a[i];
					if(x>nn||t[nn+1]-t[x]==0) continue;
					ans1++,ltp++;e[ltp].l=x,e[ltp].r=nn;continue;
				}
				LL x=a[i]+((k*k-b[i]*b[i])/(c[i]*2))+1;
				if(x>nn||t[nn+1]-t[x]==0) continue;
				ans1++,ltp++;e[ltp].l=x,e[ltp].r=nn;continue;
			}
			LL x=a[i]+((b[i]*b[i]-k*k-c[i]*2-1)/(-c[i]*2))-1;
			if(x>nn) x=nn;
			if(t[x+1]-t[a[i]]==0) continue;
			ans1++,ltp++;e[ltp].l=a[i],e[ltp].r=x;
		}
		for(int i=1;i<=ltp;i++){
			//cout<<e[i].l<<" "<<e[i].r<<" ";
			e[i].l=find1(e[i].l),e[i].r=find2(e[i].r);
			//cout<<e[i].l<<" "<<e[i].r<<"\n";
		}
		sort(e+1,e+ltp+1,cmp);
		LL now=1,minn=m+1;h=0;
		for(int i=1;i<=m;i++){
			while(now<=ltp&&e[now].l==i){
				h++,st[h]=now,minn=min(minn,e[now].r);now++;
			}
			if(minn>i) continue;
			while(h) t[st[h]]=1,h--;
			ans2++;h=0;minn=m+1;
		}
		cout<<ans1<<" "<<m-ans2<<"\n";
	}
	return 0;
}
