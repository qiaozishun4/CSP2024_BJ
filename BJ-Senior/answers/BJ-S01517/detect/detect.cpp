#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int mmm,n,m,l,V,p[N],d[N],v[N],a[N];
int bin1(int x){
	int l=1,r=m,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(p[mid]<x)l=mid+1;
		else{
			ans=mid;
			r=mid-1;
		}
	}
	return ans;
}
bool check(int id,int st,int v0,int a){
	int s1=p[id]-st;
	if(v0*v0+2*a*s1>V*V)return true;
	return false;
}
int bin2(int st,int x,int v,int s){
	int l=x,r=m,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid,st,v,s)){
			ans=mid;
			r=mid-1;
		}else
			l=mid+1;
	}
	return ans;
}
int bin3(int st,int x,int v,int s){
	int l=x,r=m,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid,st,v,s)){
			ans=mid;
			l=mid+1;
		}else
			r=mid-1;
	}
	return ans;
}
struct node{
	int l,r;
}t[N];
bool cmp(node a,node b){
	if(a.r!=b.r)return a.r<b.r;
	return a.l<b.l;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>mmm;
	while(mmm--){
		int cnt=0;
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;i++)scanf("%d",&p[i]);
		for(int i=1;i<=n;i++){
			int x=bin1(d[i]);
			if(x==-1)continue;
			if(a[i]>0){
				int y=bin2(d[i],x,v[i],a[i]);
				if(y==-1)continue;
				t[++cnt].l=y;
				t[cnt].r=m;
			}else if(a[i]==0){
				if(v[i]<=V)continue;
				t[++cnt].l=x;
				t[cnt].r=m;
			}else{
				int y=bin3(d[i],x,v[i],a[i]);
				if(y==-1)continue;
				t[++cnt].l=x;
				t[cnt].r=y;
			}
		}
		sort(t+1,t+cnt+1,cmp);
		int gb=0,ans=0;
		for(int i=1;i<=cnt;i++){
			if(gb<t[i].l){
				gb=t[i].r;
				ans++;
			}
		}
		printf("%d %d\n",cnt,m-ans);
	}
	return 0;
}
