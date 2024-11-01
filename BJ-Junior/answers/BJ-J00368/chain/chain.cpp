#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int T;
int l[N],s[N][2*N];
bool num[N][2*N];
int n,k,q;
int ans;
void dfs(int x,int r,int c){
	if(num[x][c]==true){
		ans=1;
		return ;
	}
	if(ans==1||r==0) return ;
	for(int i=1;i<=l[i];i++){
		for(int j=1;j<=n;j++){
			if(j==x) continue;
			if(ans==1) return ;
			if(num[j][i]==true){
				dfs(j,r-1,c);
			}
		}
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	int c,r;
	while(T--){
		cin>>n>>k>>q;
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>s[i][j];
				num[i][s[i][j]]=true;
			}
		}
		while(q--){
			ans=0;
			cin>>r>>c;
			if(r==1){
				for(int i=1;i<=n;i++){
					if(num[i][1]==true&&num[i][c]==true){
						ans=1;
						break;
					}
				}
			}
			else{
				for(int i=1;i<=n;i++){
					if(num[i][1]==true){
						dfs(i,r,c);
					}
					if(ans==1) break;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}