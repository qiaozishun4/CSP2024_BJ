#include<bits/stdc++.h>
using namespace std;
const int R=110,M=20,N=1e5+10,L=2e5+10;
int T;
int n,k,q;
bool dp[R][M];
bool h[M][M];
int l[N];
vector<int> a[L];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				int x;
				cin>>x;
				a[i].push_back(x);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<l[i];j++){
				int u=a[i][j];
				for(int qaq=1;qaq<k;qaq++){
					if(j-qaq<0) break;
					int v=a[i][j-qaq];
					h[u][v]=1;
				}
			}
		}
		while(q--){
			int r,c;
			cin>>r>>c;
			memset(dp,0,sizeof(dp));
			dp[0][1]=1;
			for(int i=1;i<=r;i++){
				for(int j=0;j<=10;j++){
					for(int qaq=0;qaq<=10;qaq++){
						dp[i][j]=dp[i][j]|dp[i-1][qaq]&h[j][qaq];
					}
				}
			}
			cout<<dp[r][c]<<"\n";
		}
	}
	return 0;
}
