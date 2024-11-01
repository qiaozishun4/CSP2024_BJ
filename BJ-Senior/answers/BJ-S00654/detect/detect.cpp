#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],v[N],d[N],p[N],k[N],q[N],s[N],g[N];
bool f[50][N];
int n,m,L,V;
int t;
int ans1,ans2=1e9;
bool check(){
	int r=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i]==0&&f[i][p[j]]==true){
				r=1;
				break;
			}
		}
		if(r==1){
			return false;
		}
	}
	return true;
}
void dfs(int x,int deep){
	s[deep]=x;
	int w=0;
	if(deep==m){
		for(int i=1;i<=n;i++){
			g[i]=0;
		}
		for(int i=1;i<=m;i++){
			if(s[i]==1){
				w++;
				for(int j=1;j<=n;j++){
					if(f[j][p[i]]==true){
						g[j]++;
					}
				}
			}
		}
		if(check()){
			ans2=min(ans2,w);
		}
		return;
	}
	dfs(0,deep+1);
	dfs(1,deep+1);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >>t;
	while(t--){
		cin >>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin >>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin >>p[i];
		}
		ans1=0;
		ans2=0;
		if(a[1]>0&&a[2]>0&&a[3]>0&&a[4]>0&&a[5]>0&&a[6]>0&&a[7]>0&&a[8]>0&&a[9]>0&&a[10]>0){
			int x;
			x=p[m];
			for(int i=1;i<=n;i++){
				if(d[i]<=x){
					if((v[i]*v[i]+2*a[i]*(x-d[i]))>V*V){
						ans1++;
					}
				}
			}
			cout<<ans1<<" ";
			if(ans1>0){
				cout<<m-1<<endl;
			}
			else{
				cout<<m<<endl;
			}
		}
		else if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0&&a[7]==0&&a[8]==0&&a[9]==0&&a[10]==0){
			int x;
			x=p[m];
			for(int i=1;i<=n;i++){
				if(d[i]<=x){
					if(v[i]>V){
						ans1++;
					}
				}
			}
			cout<<ans1<<" ";
			if(ans1>0){
				cout<<m-1<<endl;
			}
			else{
				cout<<m<<endl;
			}
		}
		else{
			ans2=1e9;
			for(int i=1;i<=n;i++){
			for(int j=0;j<=L;j++){
				f[i][j]=false;
				k[j]=0;
				q[j]=0;
			}
		}
			for(int i=1;i<=n;i++){
				for(int j=0;j<=L;j++){
					if((v[i]*v[i]+2*a[i]*j)>V*V){
						f[i][d[i]+j]=true;
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=0;j<=L;j++){
					if(f[i][j]==true) k[j]++;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(f[i][p[j]]==true){
						ans1++;
						//cout<<i<<" "<<j<<endl;
						break;
					}
				}
			}
			cout<<ans1<<" ";
			dfs(0,1);
			dfs(1,1);
			cout<<m-ans2<<endl;
		}
	}
	return 0;
}
