#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,totc;
struct node{
	int l,r,bh;
}c[100005];
int wz[100005],sc[100005];
int mp[10005];
bool cmp(node x,node y){
	if(x.r!=y.r) return x.r<y.r;
	return x.l<y.l;
}
int f[100005];
vector<int> hv[100005];
int ans1,ans2;
void dfs(int wz,int sum){
//	cout<<wz<<" "<<sum<<"\n";for(int i=1;i<=m;++i) cout<<mp[i]<<" ";cout<<"\n";
	if(wz>m){
		int cnt=0;
		for(int i=1;i<=m;++i) if(mp[i]) cnt++;
		if(ans1<cnt){
			ans1=cnt;
			ans2=sum;
		}
		else if(ans1==cnt) ans2=min(ans2,sum);
		return ;
	}
	dfs(wz+1,sum);
	for(int i=0;i<hv[wz].size();++i) mp[hv[wz][i]]++;
	dfs(wz+1,sum+1);
	for(int i=0;i<hv[wz].size();++i) mp[hv[wz][i]]--;
}
void zuo(){
	for(int i=1;i<=m;++i){
		hv[i].clear();
		for(int j=1;j<=totc;++j){
			if(c[j].l<=wz[i]&&wz[i]<=c[j].r){
				hv[i].push_back(j);
			}
		}
	}
	ans1=-1,ans2=INT_MAX;
	dfs(1,0);
	cout<<ans1<<" "<<m-ans2<<"\n";
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		totc=0;
		for(int i=1,tmp;i<=n;++i){
			int d;
			double v,a;
			cin>>d>>v>>a;
			if(v>V&&a>=0){
				c[++totc]=(node){d,L,i};
				continue;
			}
			if((a<0&&v<=V)||!a) continue;
			double s=(V*V-v*v)/2.0/a;
			if(s<0) continue;
			if(a<0){
				s-=0.0000001;
				tmp=d+(int)s;
				c[++totc]=(node){d,min(tmp,L),i};
			}
			else{
				s+=1;
				tmp=d+(int)s;
				c[++totc]=(node){tmp,L,i};
			}
			//cout<<i<<" "<<s<<" "<<d<<"\n";
		}
		for(int i=1;i<=m;++i) cin>>wz[i];
		sort(wz+1,wz+m+1);
		sort(c+1,c+totc+1,cmp);
		//for(int i=1;i<=totc;++i) cout<<c[i].l<<" "<<c[i].r<<" "<<c[i].bh<<"\n";
		//cout<<"wz:"<<"\n";for(int i=1;i<=m;++i) cout<<wz[i]<<"\n";
		if(n<=20) {zuo();continue;}
		int anshv=0,anskq=0;
		for(int i=1;i<=totc;++i){
			int it=upper_bound(wz+1,wz+m+1,c[i].r)-wz;
			if(it>=1&&it<=m&&c[i].l<=wz[it]&&wz[it]<=c[i].r) it++;
			if(it-1>=1&&it-1<=m&&c[i].l<=wz[it-1]&&wz[it-1]<=c[i].r){
				//cout<<i<<" "<<it-1<<" "<<wz[it-1]<<"\n";
				while(c[i].l<=wz[it-1]&&wz[it-1]<=c[i].r&&i<=totc) i++,anshv++;
				i--,anskq++;
				//cout<<i<<"\n";
			}
		}
		cout<<anshv<<" "<<m-anskq<<"\n";
	}
	return 0;
}