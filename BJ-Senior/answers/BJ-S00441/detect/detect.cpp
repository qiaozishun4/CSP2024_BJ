#include<bits/stdc++.h>
using namespace std;
struct node{
	int f;//1加速 0匀速 -1减速
	int d,v,a;
	int st,ed;
}c[100005];
int p[1000005],cf[1000005],qzh[1000005];
void solve(){
	int n,m,l,vmax;
	cin>>n>>m>>l>>vmax;
	for(int i=1;i<=n;i++){
		cin>>c[i].d>>c[i].v>>c[i].a;
		if(c[i].a>0){
			c[i].f=1;
			if(vmax<c[i].v) c[i].st=c[i].d,c[i].ed=l;
			else c[i].st=ceil(c[i].d+(vmax*vmax-c[i].v*c[i].v)*1.0/(2*1.0*c[i].a)+0.0001),c[i].ed=l;
		}
		if(c[i].a==0){
			c[i].f=0;
			if(vmax<c[i].v) c[i].st=c[i].d,c[i].ed=l;
			else c[i].st=-1,c[i].ed=-1;
		}
		if(c[i].a<0){
			c[i].f=-1;
			if(vmax<c[i].v) c[i].st=c[i].d,c[i].ed=floor(c[i].st*1.0+(vmax*vmax-c[i].v*c[i].v)*1.0/(2*1.0*c[i].a)-0.0001);
			else c[i].st=-1,c[i].ed=-1;
		}
		cf[c[i].st]++,cf[c[i].ed+1]--;
	}
	//for(int i=1;i<=n;i++) cout<<c[i].st<<' '<<c[i].ed<<endl;
	for(int i=1;i<=l;i++) qzh[i]=qzh[i-1]+cf[i];//cout<<qzh[i]<<' ';
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(c[i].st==-1||c[i].st>p[m]) continue;
		int ll=lower_bound(p+1,p+1+m,c[i].st)-p-1+1;
		if(c[i].ed<p[ll]) continue;
		//cout<<i<<' ';
		cnt++;
	}
	cout<<cnt<<' ';
	cnt=0;
	for(int i=2;i<=m;i++){
		bool f=1;
		for(int j=1;j<=n;j++){
			if(c[j].st<=p[i-1]&&c[j].ed>=p[i-1]){
				if(c[j].st>p[i]||c[j].ed<p[i]){
					f=0;
				}
			}
		}
		if(f) cnt++;
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
}
