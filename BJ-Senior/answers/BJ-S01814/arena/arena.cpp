#include<bits/stdc++.h>
using namespace std;

int t;
int n,q,k;
int a[100005],c[100005];
long long ans[100005];
int b[20][100005];
string s;
int xx[5];

vector<int> v[20][100005];

long long query(int len){
	int kx=0;
	while((1<<kx)<len){
		++kx;
	}
	for(int i=1;i<=(1<<kx);++i){
		v[0][i].push_back(i);
	}
	for(int i=1;i<=kx;++i){
		for(int j=1;j<=(1<<(kx-i));++j){
			if(b[i][j]==0){
				bool flag=0;
				for(int l=0;l<(int)(v[i-1][j*2-1].size());++l){
					if(v[i-1][j*2-1][l]>len){
						v[i][j].push_back(v[i-1][j*2-1][l]);
						flag=1;
					}
					else if(a[v[i-1][j*2-1][l]]>=i){
						v[i][j].push_back(v[i-1][j*2-1][l]);
					}
					else{
						flag=1;
					}
				}
				if(flag==1){
					for(int l=0;l<(int)(v[i-1][j*2].size());++l){
						v[i][j].push_back(v[i-1][j*2][l]);
					}
				}
			}
			else{
				bool flag=0;
				for(int l=0;l<(int)(v[i-1][j*2].size());++l){
					if(v[i-1][j*2][l]>len){
						v[i][j].push_back(v[i-1][j*2][l]);
						flag=1;
					}
					else if(a[v[i-1][j*2][l]]>=i){
						v[i][j].push_back(v[i-1][j*2][l]);
					}
					else{
						flag=1;
					}
				}
				if(flag==1){
					for(int l=0;l<(int)(v[i-1][j*2-1].size());++l){
						v[i][j].push_back(v[i-1][j*2-1][l]);
					}
				}
			}
		}
	}
	long long rt=0;
	for(int i=0;i<(int)(v[kx][1].size());++i){
		rt+=v[kx][1][i];
	}
	for(int i=0;i<=kx;++i){
		for(int j=1;j<=(1<<(kx-i));++j){
			v[i][j].clear();
		}
	}
	return rt;
}

long long solve(){
	long long rt=0;
	for(int i=1;i<=q;++i){
		if(ans[c[i]]==-1){
			ans[c[i]]=query(c[i]);
		}
		rt^=i*ans[c[i]];
	}
	return rt;
}

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=q;++i){
		cin>>c[i];
	}
	while((1<<k)<n){
		++k;
	}
	for(int i=1;i<=k;++i){
		cin>>s;
		for(int j=0;j<(int)(s.size());++j){
			b[i][j+1]=s[j]-'0';
		}
	}
	cin>>t;
	for(int tid=1;tid<=t;++tid){
		cin>>xx[0]>>xx[1]>>xx[2]>>xx[3];
		for(int i=1;i<=n;++i){
			a[i]^=xx[i%4];
			ans[i]=-1;
		}
		cout<<solve()<<'\n';
		for(int i=1;i<=n;++i){
			a[i]^=xx[i%4];
		}
	}
	return 0;
}
