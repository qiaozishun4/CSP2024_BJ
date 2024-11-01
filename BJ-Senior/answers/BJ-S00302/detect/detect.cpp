#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int T;
int n,m,L,V;
int d[N],v[N],a[N];
int p[N];
bool cs[N];
bool sxt[N];
bool che[N];
vector<int> bh[N];
int ans,cnt;
void dfs(int step){
	if(step==m+1){
		int sxt_cnt=0;
		memset(che,0,sizeof(che));
		for(int i=1;i<=m;i++){
			if(sxt[i]==true){
				sxt_cnt++;
				int len=bh[i].size();
				for(int j=0;j<len;j++){
					che[bh[i][j]]=true;
				}
			}
		}
		int car=0;
		for(int i=1;i<=n;i++){
			if(che[i]==true) car++;
		}
		if(car==ans){
			cnt=max(cnt,m-sxt_cnt);
		}
		return ;
	}
	for(int i=0;i<=1;i++){
		sxt[step]=i;
		dfs(step+1);
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		memset(cs,0,sizeof(cs));
		for(int i=1;i<=m;i++){
			bh[i].clear();
		}
		double vt;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(p[j]<d[i]) continue;
				if(a[i]==0) vt=v[i];
				else vt=sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]));
				if(vt<=0) break;
				if(vt>V){
					if(cs[i]==false){
						ans++;
						cs[i]=true;
					}
					bh[j].push_back(i);
				}
				else if(a[i]<0) break;
			}
		}
		dfs(1);
		cout<<ans<<" "<<cnt<<"\n";
	}
	return 0;
}