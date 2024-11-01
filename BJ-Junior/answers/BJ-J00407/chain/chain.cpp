#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>vec[N];
int l[N];
int t,n,k,q;
int dfs(int r,int c,int now){
	if(r==0)return c==1;
	for(int i=1;i<=n;i++){
		if(i==now)continue;
		for(int j=0;j<l[i];j++){
			if(vec[i][j]==c){
				for(int z=2;z<=k;z++){
					if(j-z+1>=0){
						if(dfs(r-1, vec[i][j-z+1],i))return 1;
					}
				}
			}
		}
	}
	return 0;
}

int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=N;i++)vec[i].clear();
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				int num;
				cin>>num;
				vec[i].push_back(num);
			}
		}
		for(int j=1; j<=q;j++){
			int r,c;
			cin>>r>>c;
			cout<<dfs(r,c,0)<<"\n";
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
