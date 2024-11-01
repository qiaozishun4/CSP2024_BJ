#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using v2=vector<vi>;
const int inf=0x3f3f3f3f;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,k,q;
		cin>>n>>k>>q;
		vector<vi>s(n+1);
		vi l(n+1);
		vi lsh(1);
		int lshl=0;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			vi x(l[i]+1);
			for(int j=1;j<=l[i];j++){
				cin>>x[j];
				lsh.push_back(x[j]);
				lshl++;
			}
			s[i]=x;
		}
		sort(lsh.begin()+1,lsh.end());
		lshl=unique(lsh.begin()+1,lsh.end())-lsh.begin()-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=l[i];j++){
				s[i][j]=lower_bound(lsh.begin()+1,lsh.begin()+lshl+1,s[i][j])-lsh.begin();
			}
		}
		int RMAX=10; 
		vector<v2>dp(RMAX+1,v2(n+1,vi(lshl+1)));
		if(k>=lshl){
			vector<vi>B(n+1,vi(lshl+1));
			for(int i=1;i<=n;i++){
				for(int j=1;j<=l[i];j++){
					B[i][s[i][j]]=1;
					dp[1][i][s[i][j]]=1;
				}
			}
			for(int i=1;i<=RMAX;i++){
				for(int j=1;j<=n;j++){
					for(int x=1;x<=lshl;x++){
						if(dp[i][j][x])break;
						if(!B[j][x])continue;
						for(int y=1;y<=n;y++){
							if(dp[i][j][x])break;
							if(y==j)continue;
							for(int c=1;c<=lshl;c++){
								if(dp[i][j][x])break;
								if(B[j][c]&&B[y][c]&&B[j][x])dp[i][j][x]|=dp[i-1][y][c];
							}
						}
					}
				}
			}
			
		}else{
			vector<v2>B(n+1,v2(lshl+1,vi(lshl+1)));
			for(int i=1;i<=n;i++){
				for(int j=1;j<l[i];j++){
					for(int x=1;x<k&&j+x<=l[i];x++){
						B[i][s[i][j]][s[i][j+x]]=1;
						if(s[i][j]==1)dp[1][i][s[i][j+x]]=1;
					}
				}
			}
			for(int i=2;i<=RMAX;i++){
				for(int j=1;j<=n;j++){
					for(int x=1;x<=lshl;x++){
						if(dp[i][j][x])break;
						for(int y=1;y<=n;y++){
							if(dp[i][j][x])break;
							if(y==j)continue;
							for(int c=1;c<=lshl;c++){
								if(dp[i][j][x])break;
								if(B[j][c][x])dp[i][j][x]|=dp[i-1][y][c];
							}
						}
					}
				}
			}
		}
		int r,x;
		while(q--){
			cin>>r>>x;
			bool sf=0;
			for(int i=1;i<=n;i++){
				if(dp[r][i][x]){
					sf=1;
					break;
				}
			}
			cout<<sf<<endl;
		}
	}
	return 0;
}
