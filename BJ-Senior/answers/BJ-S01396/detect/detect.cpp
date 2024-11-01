#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int d[N],v[N],a[N],p[N];
struct node{
	int l,r;
}h[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		memset(h,0,sizeof(h));
		int n,m,l,u;
		cin>>n>>m>>l>>u;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			double x=u*u-v[i]*v[i];
			double y=2*a[i];
			int dis=int(x/y);
			if(v[i]>u&&a[i]>=0){
				h[i]={d[i],l};
			}else if(v[i]>u&&a[i]<0){
				h[i]={d[i],d[i]+dis};
			}else if(v[i]<u&&a[i]>=0&&d[i]+dis<=l){
				h[i]={d[i]+dis,l};
			}else{
				h[i]={-1,-1};
			}
		}
		int f=0,cnt=0;
		for(int i=1;i<=n;i++){
			f=0;
			if(h[i].l==-1&&h[i].r==-1) continue;
			for(int j=h[i].l;j<=h[i].r;j++){
				for(int k=1;k<=m;k++){
					if(p[k]==j){
						cnt++;
						f=1;
						break;
					}
				}
				if(f==1) break;
			}
		}
		cout<<cnt<<" ";
		map<int,int> mp;
		for(int i=1;i<=n;i++){
			if(h[i].l==-1&&h[i].r==-1) continue;
			for(int j=h[i].l;j<=h[i].r;j++){
				for(int k=1;k<=m;k++){
					if(p[k]==j){
						mp[j]++;
					}
				}
			}
		}
		int maxx=0;
		for(auto i:mp){
			maxx=max(maxx,i.second);
		}
		int s=cnt-maxx;
		cout<<m-s-1<<endl;
	}
	return 0;
}
