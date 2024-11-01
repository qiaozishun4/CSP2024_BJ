#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;

struct qqq{
	int lx,rx;
}a[100005];

int t;
int n,m,len;
long long lim;
int d[100005];
long long v[100005],add[100005];
int p[100005],c[100005];
int flag[100005];
int nxt[1000005];
int cnt,ans;

int check(int id,int px){
	if(d[id]>px || px==-1){
		return 0;
	}
	long long s=px-d[id];
	if(v[id]*v[id]+2*add[id]*s>lim*lim){//sqrt(v[id]*v[id]+2*add[id]*s)>lim
		return 1;
	}
	return 0;
}

bool cmp(qqq q1,qqq q2){
	return q1.lx<q2.lx;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>len>>lim;
		for(int i=1;i<=n;++i){
			cin>>d[i]>>v[i]>>add[i];
			++d[i];
		}
		for(int i=1;i<=m;++i){
			cin>>p[i];
			++p[i];
		}
		for(int i=1;i<=len;++i){
			nxt[i]=-1;
		}
		for(int i=1;i<=m;++i){
			for(int j=p[i-1]+1;j<=p[i];++j){
				nxt[j]=i;
			}
		}
		for(int i=1;i<=n;++i){
			flag[i]=(check(i,p[nxt[d[i]]])|check(i,p[m]));
			if(flag[i]==0){
				continue;
			}
			if(add[i]>0){
				int id=m;
				for(int j=20;j>=0;--j){
					if(id-(1<<j)>=nxt[d[i]] && check(i,p[id-(1<<j)])==1){
						id-=(1<<j);
					}
				}
				++cnt;
				a[cnt].lx=id;
				a[cnt].rx=m;
			}
			if(add[i]<0){
				int id=nxt[d[i]];
				for(int j=20;j>=0;--j){
					if(id+(1<<j)<=m && check(i,p[id+(1<<j)])==1){
						id+=(1<<j);
					}
				}
				++cnt;
				a[cnt].lx=nxt[d[i]];
				a[cnt].rx=id;
			}
			if(add[i]==0){
				++cnt;
				a[cnt].lx=nxt[d[i]];
				a[cnt].rx=m;
			}
		}
		sort(a+1,a+cnt+1,cmp);
		int mx=inf;
		for(int i=1;i<=cnt;++i){
			if(a[i].lx>mx){
				++ans;
				mx=a[i].rx;
			}
			else{
				mx=min(mx,a[i].rx);
			}
		}
		if(mx!=inf){
			++ans;
		}
		cout<<cnt<<' '<<m-ans<<'\n';
		for(int i=1;i<=n;++i){
			flag[i]=0;
		}
		cnt=0;
		ans=0;
	}
	return 0;
}
