//expect 5pts
#include<bits/stdc++.h>
using namespace std;
int T,n,K,q;
int l[200010];
vector<int> s[200010];
struct game{
	int r,c;
} games[200010];
inline bool operator<(const game& a,const game& b){
	return a.r<b.r;
}
int dp[110][200010];
bool canTrans(int player,int from,int to){
	//O(l)
	int dis=0;
	for(auto i:s[player]){
		if(i==from)dis=0;
		else if(i==to){
			if(dis>=1&&dis<K)return true;
		}
		dis++;
	}
	return false;
}
vector<pair<int,int> > pos[200010];
bool flag[200010];
//int trans[2010][2010];
bool dp2[10][15][25];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>K>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			s[i].clear();
			for(int j=1;j<=l[i];j++){
				int cur;
				cin>>cur;
				//pos[cur].insert(i);
				s[i].push_back(cur);
			}
		}
		int maxr=0;
		for(int i=1;i<=q;i++){
			cin>>games[i].r>>games[i].c;
			maxr=max(maxr,games[i].r);
		}
		if(maxr==1){
			for(int i=1;i<=n;i++){
				for(int j=0;j<l[i];j++){
					if(s[i][j]!=1)continue;
					for(int k=1;k<K&&j+k<l[i];k++){
						flag[s[i][j+k]]=true;
					}
				}
			}
			for(int i=1;i<=q;i++){
				if(flag[games[i].c])cout<<1<<endl;
				else cout<<0<<endl;
			}
		}else if(maxr<=5){
			for(int i=1;i<=200000;i++)pos[i].clear();
			for(int i=1;i<=n;i++){
				for(int j=0;j<l[i];j++){
					pos[s[i][j]].push_back({i,j});
				}
			}
			memset(dp2,0,sizeof(dp2));
			for(int i=1;i<=n;i++){
				for(int j=0;j<l[i];j++){
					if(s[i][j]!=1)continue;
					for(int k=1;k<K&&j+k<l[i];k++){
						dp2[1][i][k]=true;
					}
				}
			}
			for(int i=2;i<=maxr;i++){
				for(int j=1;j<=n;j++){
					for(int k=1;k<=l[j];k++){
						for(int from=1;from<=n;from++){
							if(from==j)continue;
							for(int word=0;word<l[from];word++){
								if(canTrans(j,s[from][word],s[j][k])){
									dp2[i][j][k]|=dp2[i-1][from][word];
								}
							}
						}
					}
				}
			}
			for(int i=1;i<=q;i++){
				bool flag=false;
				for(auto j:pos[games[i].c]){
					if(dp2[games[i].r][j.first][j.second])flag=true;
				}
				cout<<flag<<endl;
			}
		}
	}
}