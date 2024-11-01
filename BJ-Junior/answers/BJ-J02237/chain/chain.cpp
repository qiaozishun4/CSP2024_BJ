#include<bits/stdc++.h>
using namespace std;

const int MAX=100,w=2e5;

int mx;
int t;
int n,kx,q;
int len[100005];
int r[100005],num[100005],x;
vector<int> a[100005],c[100005];
vector< pair<int,int> > p[200005];
bitset<200005> ans[105];
int f[200005];

void init(){
	vector< pair<int,int> > lst=p[1],nxt;
	for(int i=1;i<=w;++i){
		f[i]=-1;
	}
	for(int i=1;i<=mx;++i){
		nxt.clear();
		for(int j=0;j<(int)(lst.size());++j){
			if(lst[j].second+1<len[lst[j].first]){
				++c[lst[j].first][lst[j].second+1];
			}
			if(lst[j].second+kx<len[lst[j].first]){
				--c[lst[j].first][lst[j].second+kx];
			}
		}
		for(int j=1;j<=n;++j){
			int s=0;
			for(int k=0;k<len[j];++k){
				s+=c[j][k];
				c[j][k]=0;
				if(s!=0){
					nxt.push_back(make_pair(j,k));
				}
			}
		}
		for(int j=0;j<(int)(nxt.size());++j){
			ans[i][a[nxt[j].first][nxt[j].second]]=1;
			if(f[a[nxt[j].first][nxt[j].second]]==-1 || f[a[nxt[j].first][nxt[j].second]]==nxt[j].first){
				f[a[nxt[j].first][nxt[j].second]]=nxt[j].first;
			}
			else{
				f[a[nxt[j].first][nxt[j].second]]=-2;
			}
		}
		lst.clear();
		for(int j=1;j<=w;++j){
			if(f[j]==-1){
				continue;
			}
			for(int k=0;k<(int)(p[j].size());++k){
				if(f[j]!=-2 && p[j][k].first==f[j]){
					continue;
				}
				lst.push_back(p[j][k]);
			}
			f[j]=-1;
		}
	}
	return;
}

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>kx>>q;
		for(int i=1;i<=n;++i){
			cin>>len[i];
			for(int j=0;j<len[i];++j){
				cin>>x;
				a[i].push_back(x);
				c[i].push_back(0);
				p[x].push_back(make_pair(i,j));
			}
		}
		mx=0;
		for(int i=1;i<=q;++i){
			cin>>r[i]>>num[i];
			mx=max(mx,r[i]);
		}
		init();
		for(int i=1;i<=q;++i){
			//cout<<ans[r][x]<<'\n';
			if(ans[r[i]][num[i]]==0){
				putchar('0');
			}
			else{
				putchar('1');
			}
			putchar('\n');
		}
		for(int i=1;i<=n;++i){
			a[i].clear();
			c[i].clear();
			len[i]=0;
		}
		for(int i=1;i<=w;++i){
			p[i].clear();
		}
		for(int i=1;i<=mx;++i){
			ans[i].reset();
		}
	}
	return 0;
}
